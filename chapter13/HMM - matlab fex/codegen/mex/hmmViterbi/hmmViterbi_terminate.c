/*
 * hmmViterbi_terminate.c
 *
 * Code generation for function 'hmmViterbi_terminate'
 *
 */

/* Include files */
#include "hmmViterbi_terminate.h"
#include "_coder_hmmViterbi_mex.h"
#include "hmmViterbi.h"
#include "hmmViterbi_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void hmmViterbi_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void hmmViterbi_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (hmmViterbi_terminate.c) */
