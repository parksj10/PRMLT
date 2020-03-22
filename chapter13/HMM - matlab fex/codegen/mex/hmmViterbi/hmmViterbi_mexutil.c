/*
 * hmmViterbi_mexutil.c
 *
 * Code generation for function 'hmmViterbi_mexutil'
 *
 */

/* Include files */
#include "hmmViterbi_mexutil.h"
#include "hmmViterbi.h"
#include "rt_nonfinite.h"

/* Function Definitions */
const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/* End of code generation (hmmViterbi_mexutil.c) */
