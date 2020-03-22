/*
 * _coder_hmmEM_mex.c
 *
 * Code generation for function '_coder_hmmEM_mex'
 *
 */

/* Include files */
#include "_coder_hmmEM_mex.h"
#include "_coder_hmmEM_api.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "hmmEM_initialize.h"
#include "hmmEM_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void hmmEM_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
void hmmEM_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs, const
  mxArray *prhs[4])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4, 5,
                        "hmmEM");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "hmmEM");
  }

  /* Call the function. */
  hmmEM_api(prhs, nlhs, outputs);

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
  mexAtExit(hmmEM_atexit);

  /* Module initialization. */
  hmmEM_initialize();

  /* Dispatch the entry-point. */
  hmmEM_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  hmmEM_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_hmmEM_mex.c) */
