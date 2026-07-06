function main()
root = fileparts(mfilename('fullpath'));
addpath(genpath(root));
benchmarkRoot = fullfile(root,'..','..','benchmark','SEC2018_MaOP_M3_D10');
addpath(genpath(benchmarkRoot));
if exist('platemo','file') ~= 2
    error('PlatEMO runtime is required to execute RDEx-MOP.');
end
previousFolder = pwd;
cleanup = onCleanup(@() cd(previousFolder));
cd(benchmarkRoot);
for problemId = 1:10
    problemFunc = str2func(['MaOP',num2str(problemId)]);
    for runId = 1:30
        platemo('algorithm',@RDE,'problem',problemFunc,'N',100,'M',3,'D',7,'maxFE',100000,'run',runId,'save',500,'metName',{'IGD'});
    end
end
end
