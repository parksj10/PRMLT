/*
 * tic.c
 *
 * Code generation for function 'tic'
 *
 */

/* Include files */
#include "tic.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 34,  /* lineNo */
  "tic",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\tic.m"/* pathName */
};

/* Function Definitions */
void tic(const emlrtStack *sp)
{
  int32_T status;
  emlrtTimespec b_timespec;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &k_emlrtRSI;
  status = emlrtClockGettimeMonotonic(&b_timespec);
  c_st.site = &l_emlrtRSI;
  if (status != 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "Coder:toolbox:POSIXCallFailed", "Coder:toolbox:POSIXCallFailed", 5, 4, 26,
      cv, 12, status);
  }

  st.site = &j_emlrtRSI;
  timeKeeper(&st, b_timespec.tv_sec, b_timespec.tv_nsec);
}

/* End of code generation (tic.c) */
