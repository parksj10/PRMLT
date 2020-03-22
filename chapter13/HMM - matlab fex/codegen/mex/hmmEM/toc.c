/*
 * toc.c
 *
 * Code generation for function 'toc'
 *
 */

/* Include files */
#include "toc.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 31,  /* lineNo */
  "toc",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\toc.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 36,  /* lineNo */
  "toc",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\toc.m"/* pathName */
};

/* Function Definitions */
real_T toc(const emlrtStack *sp)
{
  real_T tstart_tv_sec;
  real_T tstart_tv_nsec;
  int32_T status;
  emlrtTimespec b_timespec;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_timeKeeper(&st, &tstart_tv_sec, &tstart_tv_nsec);
  st.site = &o_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  status = emlrtClockGettimeMonotonic(&b_timespec);
  c_st.site = &l_emlrtRSI;
  if (status != 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
      "Coder:toolbox:POSIXCallFailed", "Coder:toolbox:POSIXCallFailed", 5, 4, 26,
      cv, 12, status);
  }

  return (b_timespec.tv_sec - tstart_tv_sec) + (b_timespec.tv_nsec -
    tstart_tv_nsec) / 1.0E+9;
}

/* End of code generation (toc.c) */
