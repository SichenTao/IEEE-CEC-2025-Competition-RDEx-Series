function main()
root = fileparts(mfilename('fullpath'));
addpath(genpath(root));
benchmarkRoot = fullfile(root,'..','..','benchmark','SDC');
addpath(genpath(benchmarkRoot));
if exist('platemo','file') ~= 2
    error('PlatEMO runtime is required to execute RDEx-CMOP.');
end
for problemId = 1:15
    problemFunc = str2func(['SDC',num2str(problemId)]);
    for runId = 1:30
        platemo('algorithm',@RDE,'problem',problemFunc,'N',100,'D',30,'maxFE',200000,'run',runId,'save',1000,'metName',{'IGD','HV'});
    end
end
end
