/*
 * hmmEM_terminate.c
 *
 * Code generation for function 'hmmEM_terminate'
 *
 */

/* Include files */
#include "hmmEM_terminate.h"
#include "_coder_hmmEM_mex.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void hmmEM_atexit(void)
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

void hmmEM_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (hmmEM_terminate.c) */
