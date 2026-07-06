classdef MaOP7 < PROBLEM
    methods
        %% Default settings of the problem
        function Setting(obj)
            if isempty(obj.M); obj.M = 3; end
            if isempty(obj.D); obj.D = 7; end
            obj.lower    = zeros(1,obj.D);
            obj.upper    = ones(1,obj.D);
            obj.encoding = ones(1,obj.D);
        end

        %% Calculate objective values
        function PopObj = CalObj(obj,PopDec)
            [N, ~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                alpha = zeros(1, nobj);
                g = 0;
                tmp = prod(sin(0.5*pi*PopDec(i,1:(nobj-1))));
                for n=nobj:1:nvar
                    if mod(n,5)==0
                        g = g + (PopDec(i,n) - tmp).^2;
                    else
                        g = g + (PopDec(i,n) - 0.5).^2;
                    end
                end
                g = g*100;  % The scale 100 is multiplied by g. 2018.5.8
                tau = sqrt(2)/2;
                alpha(1) = -(2*PopDec(i,1)-1).^3 + 1;
                T = floor((nobj-1)/2);
                for j=1:T
                    alpha(2*j)    = PopDec(i,1) + 2*PopDec(i,j+1)*tau + tau*abs(2*PopDec(i,j+1)-1).^(0.5+PopDec(i,1));
                    alpha(2*j+1)  = PopDec(i,1) - (2*PopDec(i,j+1)-2)*tau + tau*abs(2*PopDec(i,j+1)-1).^(0.5+PopDec(i,1));
                end
                if mod(nobj,2)==0
                    alpha(nobj) = 1 - alpha(1);
                end
                PopObj(i,:) = (1 + g)*alpha;
            end
        end

        %% Generate points on the Pareto front
        % function R = GetOptimum(obj, N)
        %     R = UniformPoint(N, obj.M);
        %     realN = size(R, 1);
        %     for i = 1:realN
        %         f = R(i,:);
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
        %         f1_raw = f(1);
        %         f2_raw = f(2);
        %         sum_raw = f1_raw + f2_raw / 2;
        %         if sum_raw == 0
        %             f1 = rhs;
        %             f2 = 0;
        %         else
        %             factor = rhs / sum_raw;
        %             f1 = f1_raw * factor;
        %             f2 = f2_raw * factor;
        %         end
        %         R(i,:) = [f1, f2, f3];
        %     end
        % end
        % 
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP7_F3.txt');
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
        %% Generate the image of Pareto front
        function R = GetPF(obj)
            R = obj.GetOptimum(100);
        end
    end
end
