% COMPILEHMM_SCRIPT   Generate MEX-function hmmEM_mex from hmmEM, hmmViterbi.
% 
% Script generated from project 'compileHMM.prj' on 21-Mar-2020.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.MexCodeConfig'.
cfg = coder.config('mex');
cfg.GenerateReport = true;
cfg.ReportPotentialDifferences = true;

%% Define argument types for entry-point 'hmmEM'.
ARGS = cell(2,1);
ARGS{1} = cell(4,1);
ARGS{1}{1} = coder.typeof(0,[1 Inf],[0 1]);
ARGS_1_2 = struct;
ARGS_1_2.A = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_1_2.B = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_1_2.pi = coder.typeof(0,[Inf  1],[1 0]);
ARGS{1}{2} = coder.typeof(ARGS_1_2);
ARGS{1}{3} = coder.typeof(0);
ARGS{1}{4} = coder.typeof(0);

%% Define argument types for entry-point 'hmmViterbi'.
ARGS{2} = cell(2,1);
ARGS{2}{1} = coder.typeof(0,[1 Inf],[0 1]);
ARGS_2_2 = struct;
ARGS_2_2.A = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_2_2.B = coder.typeof(0,[Inf Inf],[1 1]);
ARGS_2_2.pi = coder.typeof(0,[Inf  1],[1 0]);
ARGS{2}{2} = coder.typeof(ARGS_2_2);

%% Create MATLAB Coder projects.
codegen -config cfg hmmEM -args ARGS{1} -toproject compile_hmmEM.prj
codegen -config cfg hmmViterbi -args ARGS{2} -toproject compile_hmmViterbi.prj

%% Invoke matlab codegen.
codegen compile_hmmEM.prj
codegen compile_hmmViterbi.prj
