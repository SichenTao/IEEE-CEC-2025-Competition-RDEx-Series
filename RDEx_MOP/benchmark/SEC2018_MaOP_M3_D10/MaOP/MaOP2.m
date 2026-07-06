classdef MaOP2 < PROBLEM
    methods
        %% Default parameter setting
        function Setting(obj)
            if isempty(obj.M), obj.M = 3; end
            if isempty(obj.D), obj.D = 7; end
            obj.lower = zeros(1,obj.D);
            obj.upper = ones(1,obj.D);
            obj.encoding = ones(1,obj.D);
        end

        %% Objective function evaluation
        function PopObj = CalObj(obj,PopDec)
            [N,~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                g = 0;
                tmp1 = prod(sin(0.5*pi*PopDec(i,1:(nobj-1))));
                for n=nobj:1:nvar
                    if mod(n,5)==0
                        g = g + (PopDec(i,n) - tmp1).^2;
                    else
                        g = g + (PopDec(i,n) - 0.5).^2;
                    end
                end
                g = g*200;    % The scale 200 is added to g.
                tmp2 = 1;
                for m = nobj:(-1):1
                    p = 2^(mod(m,2)+1);
                    if m==nobj
                        PopObj(i,m) = (1 + g)*sin(0.5*PopDec(i,1)*pi)^p;
                    elseif m<nobj&&m>=2
                        tmp2 = tmp2*cos(0.5*pi*PopDec(i,nobj-m));
                        PopObj(i,m) = (1 + g)*(tmp2*sin(0.5*pi*PopDec(i,nobj-m+1)))^p;        % wrong pow function
                    else
                        PopObj(i,m) = (1 + g)*(tmp2*cos(0.5*pi*PopDec(i,nobj-1)))^p;          % wrong pow function
                    end
                end
            end
        end

        %% Generate Pareto front
        % function R = GetOptimum(obj, N)
        %     R = UniformPoint(N, obj.M);
        %     [n, M] = size(R);
        %     q = 0.5 * ones(1, M);
        %     q(2:2:end) = 1;
        %     for i = 1:n
        %         f = R(i,:);
        %         scale = (1 / sum(f.^q))^(1 ./ mean(q));
        %         R(i,:) = f * scale;
        %         while abs(sum(R(i,:).^q) - 1) > 1e-6
        %             R(i,:) = R(i,:) * (1 / sum(R(i,:).^q))^(1 ./ mean(q));
        %         end
        %     end
        % end
        
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP2_F3.txt');
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
        %% Generate image of Pareto front
        function R = GetPF(obj)
            R = obj.GetOptimum(100);
        end
    end
end
