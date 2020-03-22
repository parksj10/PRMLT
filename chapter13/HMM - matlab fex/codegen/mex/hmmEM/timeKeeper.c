/*
 * timeKeeper.c
 *
 * Code generation for function 'timeKeeper'
 *
 */

/* Include files */
#include "timeKeeper.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T tv_sec;
  real_T tv_nsec;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static struct_T savedTime;
static boolean_T savedTime_not_empty;
static emlrtRSInfo m_emlrtRSI = { 14,  /* lineNo */
  "timeKeeper",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\private\\timeKeeper.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "timeKeeper",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\private\\timeKeeper.m"/* pName */
};

/* Function Definitions */
void b_timeKeeper(const emlrtStack *sp, real_T *outTime_tv_sec, real_T
                  *outTime_tv_nsec)
{
  if (!savedTime_not_empty) {
    emlrtErrorWithMessageIdR2018a(sp, &e_emlrtRTEI,
      "MATLAB:toc:callTicFirstNoInputs", "MATLAB:toc:callTicFirstNoInputs", 0);
  }

  *outTime_tv_sec = savedTime.tv_sec;
  *outTime_tv_nsec = savedTime.tv_nsec;
}

void savedTime_not_empty_init(void)
{
  savedTime_not_empty = false;
}

void timeKeeper(const emlrtStack *sp, real_T newTime_tv_sec, real_T
                newTime_tv_nsec)
{
  int32_T status;
  emlrtTimespec b_timespec;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (!savedTime_not_empty) {
    st.site = &m_emlrtRSI;
    b_st.site = &k_emlrtRSI;
    status = emlrtClockGettimeMonotonic(&b_timespec);
    c_st.site = &l_emlrtRSI;
    if (status != 0) {
      emlrtErrorWithMessageIdR2018a(&c_st, &c_emlrtRTEI,
        "Coder:toolbox:POSIXCallFailed", "Coder:toolbox:POSIXCallFailed", 5, 4,
        26, cv, 12, status);
    }

    savedTime.tv_sec = b_timespec.tv_sec;
    savedTime.tv_nsec = b_timespec.tv_nsec;
    savedTime_not_empty = true;
  }

  savedTime.tv_sec = newTime_tv_sec;
  savedTime.tv_nsec = newTime_tv_nsec;
}

/* End of code generation (timeKeeper.c) */
