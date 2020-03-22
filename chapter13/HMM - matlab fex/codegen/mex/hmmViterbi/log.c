/*
 * log.c
 *
 * Code generation for function 'log'
 *
 */

/* Include files */
#include "log.h"
#include "eml_int_forloop_overflow_check.h"
#include "hmmViterbi.h"
#include "hmmViterbi_data.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_log(const emlrtStack *sp, emxArray_real_T *x)
{
  boolean_T p;
  int32_T nx;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = false;
  nx = x->size[0] * x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      3, "log");
  }

  st.site = &f_emlrtRSI;
  nx = x->size[0] * x->size[1];
  b_st.site = &g_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    c_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    x->data[k] = muDoubleScalarLog(x->data[k]);
  }
}

/* End of code generation (log.c) */
