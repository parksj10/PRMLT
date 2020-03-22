/*
 * _coder_hmmViterbi_mex.c
 *
 * Code generation for function '_coder_hmmViterbi_mex'
 *
 */

/* Include files */
#include "_coder_hmmViterbi_mex.h"
#include "_coder_hmmViterbi_api.h"
#include "hmmViterbi.h"
#include "hmmViterbi_data.h"
#include "hmmViterbi_initialize.h"
#include "hmmViterbi_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void hmmViterbi_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
void hmmViterbi_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[2])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        10, "hmmViterbi");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "hmmViterbi");
  }

  /* Call the function. */
  hmmViterbi_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(hmmViterbi_atexit);

  /* Module initialization. */
  hmmViterbi_initialize();

  /* Dispatch the entry-point. */
  hmmViterbi_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  hmmViterbi_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_hmmViterbi_mex.c) */
