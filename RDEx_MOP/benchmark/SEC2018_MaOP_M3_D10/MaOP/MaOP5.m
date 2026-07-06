classdef MaOP5 < PROBLEM
    methods
        function Setting(obj)
            if isempty(obj.M), obj.M = 3; end
            if isempty(obj.D), obj.D = 7; end
            obj.lower    = zeros(1,obj.D);
            obj.upper    = ones(1,obj.D);
            obj.encoding = ones(1,obj.D);
        end

        function PopObj = CalObj(obj,PopDec)
            [N, ~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                g = zeros(1, nobj);
                for m=1:nobj
                    if m<=3
                        g(m) = max(0, -1.4*cos(2*PopDec(i,1)*pi)) + sum(abs(PopDec(i,3:nvar) - PopDec(i,1)*PopDec(i,2)).^2);
                    else
                        g(m) = exp((PopDec(i,m) - PopDec(i,1)*PopDec(i,2))^2) - 1;
                    end
                    g(m) = 10*g(m);
                end
                alpha1 = cos(0.5*pi*PopDec(i,1))*cos(0.5*pi*PopDec(i,2));
                alpha2 = cos(0.5*pi*PopDec(i,1))*sin(0.5*pi*PopDec(i,2));
                alpha3 = sin(0.5*pi*PopDec(i,1));
                PopObj(i,1) = (1 + g(1))*alpha1;
                PopObj(i,2) = 4*(1 + g(2))*alpha2;
                PopObj(i,3) = (1 + g(3))*alpha3;
                for m = 4:nobj
                    PopObj(i,m) = (1 + g(m))*(m*alpha1/nobj + (1-m/nobj)*alpha2 + sin(0.5*m*pi/nobj)*alpha3);  % n in g(n) -->g(m)
                end
            end
        end

        % function R = GetOptimum(~, N)
        %     R = zeros(N,3);
        %     count = 0;
        %     lower1 = 0;
        %     upper1 = 4*sin(pi/8);
        %     lower2 = 4*sin(3*pi/8);
        %     upper2 = 4;
        %     while count < N
        %         f2 = rand()*4;
        %         if (f2 >= lower1 && f2 <= upper1) || (f2 >= lower2 && f2 <= upper2)
        %             rhs = 1 - f2^2 / 16;
        %             if rhs >= 0
        %                 theta = rand()*2*pi;
        %                 f1 = sqrt(rhs) * cos(theta);
        %                 f3 = sqrt(rhs) * sin(theta);
        %                 count = count + 1;
        %                 R(count,:) = [f1, f2, f3];
        %             end
        %         end
        %     end
        % end
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP5_F3.txt');
            if size(allR, 2) ~= obj.M
                error('The loaded PF points do not match the expected number of objectives (obj.M).');
            end
            total = size(allR, 1);
            if N >= total
                R = allR;
            else
                idx = round(linspace(1, total, N));
                R = allR(idx, :);
            end
        end
        function R = GetPF(obj)
            R = obj.GetOptimum(100);
        end
    end
end
