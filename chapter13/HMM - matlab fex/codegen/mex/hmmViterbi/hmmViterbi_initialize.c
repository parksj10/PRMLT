/*
 * hmmViterbi_initialize.c
 *
 * Code generation for function 'hmmViterbi_initialize'
 *
 */

/* Include files */
#include "hmmViterbi_initialize.h"
#include "_coder_hmmViterbi_mex.h"
#include "hmmViterbi.h"
#include "hmmViterbi_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void hmmViterbi_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (hmmViterbi_initialize.c) */
