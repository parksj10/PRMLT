/*
 * hmmEM_initialize.c
 *
 * Code generation for function 'hmmEM_initialize'
 *
 */

/* Include files */
#include "hmmEM_initialize.h"
#include "_coder_hmmEM_mex.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Function Declarations */
static void hmmEM_once(void);

/* Function Definitions */
static void hmmEM_once(void)
{
  mex_InitInfAndNan();
  savedTime_not_empty_init();
}

void hmmEM_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    hmmEM_once();
  }
}

/* End of code generation (hmmEM_initialize.c) */
