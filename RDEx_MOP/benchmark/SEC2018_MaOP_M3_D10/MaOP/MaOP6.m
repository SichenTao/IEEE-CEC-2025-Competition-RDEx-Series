classdef MaOP6 < PROBLEM
    methods
        %% Default settings of the problem
        function Setting(obj)
            if isempty(obj.M), obj.M = 3; end
            if isempty(obj.D), obj.D = 7; end
            obj.lower    = zeros(1, obj.D);
            obj.upper    = ones(1, obj.D);
            obj.encoding = ones(1, obj.D);
        end

        %% Calculate objective values
        function PopObj = CalObj(obj, PopDec)
            [N, ~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                g = zeros(1, nobj);
                for m=1:nobj
                    if m<=3
                        g(m) =  max(0, 1.4*sin(4*PopDec(i,1)*pi)) + sum(abs(PopDec(i,3:nvar) - PopDec(i,1)*PopDec(i,2)).^2);
                    else
                        g(m) =  exp((PopDec(i,m) - PopDec(i,1)*PopDec(i,2)).^2) - 1;
                    end
                    g(m) = g(m)*10;
                end
                alpha1 = PopDec(i,1)*PopDec(i,2);
                alpha2 = (1-PopDec(i,2))*PopDec(i,1);
                alpha3 = (1-PopDec(i,1));
                PopObj(i,1) = (1 + g(1))*alpha1;
                PopObj(i,2) = 2*(1 + g(2))*alpha2;
                PopObj(i,3) = 6*(1 + g(3))*alpha3;
                for m = 4:nobj
                    PopObj(i,m) = (1 + g(m))*(m*alpha1/nobj + (1-m/nobj)*alpha2 + sin(0.5*m*pi/nobj)*alpha3);  % n in g(n) -->g(m)
                end
            end
        end

        %% Generate PF
        % function R = GetOptimum(~,N)
        %     R = zeros(N,3);
        %     count = 0;
        %     while count < N
        %         choice = randi(3);
        %         switch choice
        %             case 1
        %                 f3 = rand() * 1.5;
        %             case 2
        %                 f3 = 3 + rand() * 1.5;
        %             case 3
        %                 f3 = 6;
        %         end
        %         rhs = 1 - f3 / 6;
        %         if rhs >= 0
        %             t = rand();
        %             f1 = t * rhs;
        %             f2 = 2 * (rhs - f1);
        %             if f1 >= 0 && f1 <= 1 && f2 >= 0 && f2 <= 1
        %                 count = count + 1;
        %                 R(count,:) = [f1, f2, f3];
        %             end
        %         end
        %     end
        % end
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP6_F3.txt');
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
