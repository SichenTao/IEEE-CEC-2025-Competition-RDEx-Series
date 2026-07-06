classdef MaOP9 < PROBLEM

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
        function PopObj = CalObj(obj, PopDec)
            [N, ~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                g = 0;
                tmp = prod(sin(0.5*pi*PopDec(i,1:(nobj-1))));
                for n=nobj:1:nvar
                    if mod(n,5)==0
                        g = g + (PopDec(i,n) - tmp).^2;
                    else
                        g = g + (PopDec(i,n) - 0.5).^2;
                    end
                end
                g = g*100;    % The scale 100 is multiplied by g. 2018.5.8
                alpha = zeros(1, nobj);
                tau = sqrt(2)/2;
                alpha(1) = -(2*PopDec(i,1)-1).^3 + 1;
                T = floor((nobj-1)/2);
                for j=1:T
                    z = 2*(2*PopDec(i,j+1) - floor(2*PopDec(i,j+1))) - 1;
                    alpha(2*j)    = PopDec(i,1) + 2*PopDec(i,j+1)*tau + tau*abs(z).^(0.5+PopDec(i,1));
                    alpha(2*j+1)  = PopDec(i,1) - (2*PopDec(i,j+1)-2)*tau + tau*abs(z).^(0.5+PopDec(i,1));
                end
                if mod(nobj,2)==0
                    alpha(nobj) = 1 - alpha(1);
                end
                PopObj(i,:) = (1 + g)*alpha;
            end
        end


        %% Generate points on the Pareto front
        % function R = GetOptimum(obj, N)
        %     D = obj.D;
        %     M = obj.M;
        %     T = M - 1;
        %     R = zeros(N, D);
        %     count = 0;
        %     while count < N
        %         x = zeros(1, D);
        %         x1 = rand();
        %         x(1) = x1;
        %         if x1 >= 0 && x1 <= 0.5
        %             x(2:T+1) = randsample([0.25, 0.75], T, true);
        %             if D > T+1
        %                 x(T+2:end) = 0.5;
        %             end
        %         elseif x1 > 0.5 && x1 <= 1
        %             e = (0.5 + x1) ^ (1 / (x1 - 0.5));
        %             choice = randi(2); 
        %             if choice == 1
        %                 lb = (1 - e) / 4;
        %                 ub = (1 + e) / 4;
        %             else
        %                 lb = (3 - e) / 4;
        %                 ub = (3 + e) / 4;
        %             end
        %             x(2:T+1) = rand(1, T) .* (ub - lb) + lb;
        %             if D > T+1
        %                 x(T+2:end) = rand(1, D - T - 1);
        %             end
        %         else
        %             continue;
        %         end
        %         count = count + 1;
        %         R(count, :) = x;
        %     end
        % end
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP9_F3.txt');
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
