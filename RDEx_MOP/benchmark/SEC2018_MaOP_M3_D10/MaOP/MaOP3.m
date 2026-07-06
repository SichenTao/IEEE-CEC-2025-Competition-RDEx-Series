classdef MaOP3 < PROBLEM
    methods
        function Setting(obj)
            if isempty(obj.M), obj.M = 3; end
            if isempty(obj.D), obj.D = 7; end
            obj.lower    = zeros(1, obj.D);
            obj.upper    = ones(1, obj.D);
            obj.encoding = ones(1, obj.D);
        end

        function PopObj = CalObj(obj, PopDec)
            [N, ~] = size(PopDec);
            nobj = obj.M;
            nvar = obj.D;
            PopObj = zeros(N, nobj);
            for i = 1:N
                g = 0;
                tmp1 = prod(sin(0.5*pi*PopDec(i,1:(nobj-1))));
                for n=nobj:1:nvar
                    if mod(n,5)==0
                        g = g + n*abs(PopDec(i,n) - tmp1).^(0.1);
                    else
                        g = g + n*abs(PopDec(i,n) - 0.5).^(0.1);
                    end
                end
                tmp2 = 1;
                for m = nobj:(-1):1
                    if m==nobj
                        PopObj(i,m) = (1 + g)*sin(0.5*PopDec(i,1)*pi);
                    elseif m<nobj&&m>=2
                        tmp2 = tmp2*cos(0.5*pi*PopDec(i,nobj-m));
                        PopObj(i,m) = (1 + g)*tmp2*sin(0.5*pi*PopDec(i,nobj-m+1));
                    else
                        PopObj(i,m) = (1 + g)*tmp2*cos(0.5*pi*PopDec(i,nobj-1));
                    end
                end
            end
        end

        % function R = GetOptimum(obj, N)
        %     R = UniformPoint(N, obj.M);
        %     R = R ./ sqrt(sum(R.^2, 2));
        %     R = abs(R);
        % end
        function R = GetOptimum(obj, N)
            allR = load('POF/MaOP3_F3.txt');
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
