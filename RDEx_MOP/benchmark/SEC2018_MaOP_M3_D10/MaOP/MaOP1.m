classdef MaOP1 < PROBLEM
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
                g   = sum((PopDec(i,nobj:nvar) - 0.5).^2 + (1 - cos(20*pi*(PopDec(i,nobj:nvar)-0.5))))/nvar;  %    '+' before cos is changed to '-' 2018.5.8
                tmp = 1;
                for m = nobj:(-1):1
                    id = nobj - m + 1;
                    if m>1
                        PopObj(i,m) = (1 + g)*(1 - tmp*(1 - PopDec(i,id)));
                        tmp  = tmp*PopDec(i,id);
                    else
                        PopObj(i,m) = (1 + g)*(1 - tmp);
                    end
                    PopObj(i,m) = (0.1 + 10*m)*PopObj(i,m);
                end
            end
        end

        %% Generate the Pareto front
        % function R = GetOptimum(obj, N)
        %     R = UniformPoint(N, obj.M);
        %     realN = size(R,1);
        %     r = 0.1 + 10 * (0:obj.M-1);
        %     for i = 1:realN
        %         f = R(i,:);
        %         factor = (obj.M - 1) / sum(f ./ r);
        %         R(i,:) = f * factor;
        %     end
        % end
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP1_F3.txt');
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