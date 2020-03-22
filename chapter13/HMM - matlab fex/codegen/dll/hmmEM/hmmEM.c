/*
 * File: hmmEM.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Mar-2020 21:34:12
 */

/* Include Files */
#include "hmmEM.h"
#include "hmmEM_emxutil.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* Type Definitions */
#include <windows.h>

/* Type Definitions */
#ifndef typedef_rtBoundsCheckInfo
#define typedef_rtBoundsCheckInfo

typedef struct {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char * aName;
  const char * fName;
  const char * pName;
  int checkKind;
} rtBoundsCheckInfo;

#endif                                 /*typedef_rtBoundsCheckInfo*/

#ifndef typedef_rtDoubleCheckInfo
#define typedef_rtDoubleCheckInfo

typedef struct {
  int lineNo;
  int colNo;
  const char * fName;
  const char * pName;
  int checkKind;
} rtDoubleCheckInfo;

#endif                                 /*typedef_rtDoubleCheckInfo*/

#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo

typedef struct {
  int nDims;
  int lineNo;
  int colNo;
  const char * fName;
  const char * pName;
} rtEqualityCheckInfo;

#endif                                 /*typedef_rtEqualityCheckInfo*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  double tv_sec;
  double tv_nsec;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static double freq;
static boolean_T freq_not_empty;
static struct_T savedTime;
static boolean_T savedTime_not_empty;
static rtRunTimeErrorInfo emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "checkWindowsStatus",                /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\private\\getTime.m"/* pName */
};

static rtRunTimeErrorInfo b_emlrtRTEI = { 12,/* lineNo */
  9,                                   /* colNo */
  "timeKeeper",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\timefun\\private\\timeKeeper.m"/* pName */
};

static rtRunTimeErrorInfo c_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static rtRunTimeErrorInfo d_emlrtRTEI = { 95,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

rtRunTimeErrorInfo e_emlrtRTEI = { 26, /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static rtEqualityCheckInfo emlrtECI = { -1,/* nDims */
  32,                                  /* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static rtBoundsCheckInfo emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "delta",                             /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtEqualityCheckInfo b_emlrtECI = { -1,/* nDims */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static rtBoundsCheckInfo b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  23,                                  /* colNo */
  "logB",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo emlrtDCI = { 25,/* lineNo */
  23,                                  /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  25,                                  /* colNo */
  "O",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  9,                                   /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  26,                                  /* colNo */
  "P",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  33,                                  /* colNo */
  "logA",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "delta",                             /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "logB",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo b_emlrtDCI = { 51,/* lineNo */
  16,                                  /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "O",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  9,                                   /* colNo */
  "P",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  1,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  12,                                  /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  12,                                  /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  5,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo o_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  8,                                   /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo p_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  8,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static rtRunTimeErrorInfo f_emlrtRTEI = { 88,/* lineNo */
  9,                                   /* colNo */
  "check_forloop_overflow_error",      /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static rtBoundsCheckInfo q_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  33,                                  /* colNo */
  "c",                                 /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  26,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  30,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  7,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  3,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  20,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  31,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  21,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo c_emlrtDCI = { 18,/* lineNo */
  15,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  1                                    /* checkKind */
};

static rtDoubleCheckInfo d_emlrtDCI = { 18,/* lineNo */
  15,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  4                                    /* checkKind */
};

static rtDoubleCheckInfo e_emlrtDCI = { 77,/* lineNo */
  16,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  4                                    /* checkKind */
};

static rtDoubleCheckInfo f_emlrtDCI = { 18,/* lineNo */
  1,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  1                                    /* checkKind */
};

static rtDoubleCheckInfo g_emlrtDCI = { 18,/* lineNo */
  1,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  4                                    /* checkKind */
};

static rtBoundsCheckInfo cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  18,                                  /* colNo */
  "pi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  24,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo h_emlrtDCI = { 29,/* lineNo */
  24,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo eb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  5,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo fb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  19,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo gb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo hb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  23,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ib_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo jb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo kb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  14,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo lb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo mb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  26,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo nb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  39,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ob_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  52,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo pb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo qb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  22,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo rb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo i_emlrtDCI = { 46,/* lineNo */
  33,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo sb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo tb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ub_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  17,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo vb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  5,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo wb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  22,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo xb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo yb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ac_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  16,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo bc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  23,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo cc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  9,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo dc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  9,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo j_emlrtDCI = { 77,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  4                                    /* checkKind */
};

static rtBoundsCheckInfo ec_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  25,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo fc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  37,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo gc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  44,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo k_emlrtDCI = { 69,/* lineNo */
  44,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo hc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  44,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ic_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  56,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo jc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  13,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo kc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  21,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo lc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  26,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo mc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  9,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo nc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  9,                                   /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo oc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  18,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo pc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo qc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo rc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  36,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo sc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  43,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtDoubleCheckInfo l_emlrtDCI = { 83,/* lineNo */
  43,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static rtBoundsCheckInfo tc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  43,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo uc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  55,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo vc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  13,                                  /* colNo */
  "xi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  26,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  39,                                  /* colNo */
  "xi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo yc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  13,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ad_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  13,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "pi",                                /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  25,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  25,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ed_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  29,                                  /* colNo */
  "xi",                                /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo fd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  9,                                   /* colNo */
  "A",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "O",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo hd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  9,                                   /* colNo */
  "B",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo id_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  33,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo jd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  15,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo kd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo ld_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  22,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  31,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  48,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  57,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  18,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static rtBoundsCheckInfo qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  9,                                   /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static boolean_T isInitialized_hmmEM = false;

/* Function Declarations */
static void b_log(emxArray_real_T *x);
static void b_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
static void b_timeKeeper(double *outTime_tv_sec, double *outTime_tv_nsec);
static void c_rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo);
static void check_forloop_overflow_error(void);
static void d_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo);
static void e_rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo);
static void getTime(double *t_tv_sec, double *t_tv_nsec);
static void rtAddSizeString(char *aBuf, const int aDim);
static void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
  const rtBoundsCheckInfo *aInfo);
static void rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo);
static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf);
static void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo);
static boolean_T rtIsNullOrEmptyString(const char *aString);
static void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo
  *aInfo);
static void rtReportErrorLocation(const char * aFcnName, int aLineNo);
static void rtSizeEq1DError(const int aDim1, const int aDim2, const
  rtEqualityCheckInfo *aInfo);
static void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1, const int
  *aDims2, const int aNDims2, const rtEqualityCheckInfo *aInfo);
static void tic(void);
static void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec);
static double toc(void);

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
static void b_log(emxArray_real_T *x)
{
  boolean_T p;
  int nx;
  int k;
  p = false;
  nx = x->size[0] * x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    c_rtErrorWithMessageID(3, "log", &c_emlrtRTEI);
  }

  nx = x->size[0] * x->size[1];
  if ((1 <= nx) && (nx > 2147483646)) {
    check_forloop_overflow_error();
  }

  for (k = 0; k < nx; k++) {
    x->data[k] = log(x->data[k]);
  }
}

/*
 * Arguments    : const rtRunTimeErrorInfo *aInfo
 * Return Type  : void
 */
static void b_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "You must call TIC without an output argument before calling TOC without an input argument.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : double *outTime_tv_sec
 *                double *outTime_tv_nsec
 * Return Type  : void
 */
static void b_timeKeeper(double *outTime_tv_sec, double *outTime_tv_nsec)
{
  if (!savedTime_not_empty) {
    b_rtErrorWithMessageID(&b_emlrtRTEI);
  }

  *outTime_tv_sec = savedTime.tv_sec;
  *outTime_tv_nsec = savedTime.tv_nsec;
}

/*
 * Arguments    : const int b
 *                const char *c
 *                const rtRunTimeErrorInfo *aInfo
 * Return Type  : void
 */
static void c_rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "Domain error. To compute complex results from real x, use \'%.*s(complex(x))\'.",
          b, c);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void check_forloop_overflow_error(void)
{
  e_rtErrorWithMessageID(5, "int32", &f_emlrtRTEI);
}

/*
 * Arguments    : const rtRunTimeErrorInfo *aInfo
 * Return Type  : void
 */
static void d_rtErrorWithMessageID(const rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "If the working dimension of MAX or MIN is variable in length, it must not have zero length at runtime.");
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const int b
 *                const char *c
 *                const rtRunTimeErrorInfo *aInfo
 * Return Type  : void
 */
static void e_rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr,
          "The loop variable of class %.*s might overflow on the last iteration of the for loop. This could lead to an infinite loop.",
          b, c);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : double *t_tv_sec
 *                double *t_tv_nsec
 * Return Type  : void
 */
static void getTime(double *t_tv_sec, double *t_tv_nsec)
{
  int status;
  LARGE_INTEGER freqL;
  static const char fcn[25] = { 'Q', 'u', 'e', 'r', 'y', 'P', 'e', 'r', 'f', 'o',
    'r', 'm', 'a', 'n', 'c', 'e', 'F', 'r', 'e', 'q', 'u', 'e', 'n', 'c', 'y' };

  static const char b_fcn[23] = { 'Q', 'u', 'e', 'r', 'y', 'P', 'e', 'r', 'f',
    'o', 'r', 'm', 'a', 'n', 'c', 'e', 'C', 'o', 'u', 'n', 't', 'e', 'r' };

  double timeRemainder;
  boolean_T rEQ0;
  double q;
  if (!freq_not_empty) {
    status = QueryPerformanceFrequency(&freqL);
    if (status == 0) {
      rtErrorWithMessageID(25, fcn, &emlrtRTEI);
    }

    freq = (double)freqL.QuadPart;
    freq_not_empty = true;
  }

  status = QueryPerformanceCounter(&freqL);
  if (status == 0) {
    rtErrorWithMessageID(23, b_fcn, &emlrtRTEI);
  }

  timeRemainder = (double)freqL.QuadPart;
  if (freq == 0.0) {
    if ((double)freqL.QuadPart == 0.0) {
      timeRemainder = freq;
    }
  } else if (rtIsNaN((double)freqL.QuadPart) || rtIsNaN(freq) || rtIsInf((double)
              freqL.QuadPart)) {
    timeRemainder = rtNaN;
  } else if ((double)freqL.QuadPart == 0.0) {
    timeRemainder = 0.0 / freq;
  } else if (rtIsInf(freq)) {
    if ((freq < 0.0) != ((double)freqL.QuadPart < 0.0)) {
      timeRemainder = freq;
    }
  } else {
    timeRemainder = fmod((double)freqL.QuadPart, freq);
    rEQ0 = (timeRemainder == 0.0);
    if ((!rEQ0) && (freq > floor(freq))) {
      q = fabs((double)freqL.QuadPart / freq);
      rEQ0 = (fabs(q - floor(q + 0.5)) <= 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      timeRemainder = freq * 0.0;
    } else {
      if (((double)freqL.QuadPart < 0.0) != (freq < 0.0)) {
        timeRemainder += freq;
      }
    }
  }

  *t_tv_sec = ((double)freqL.QuadPart - timeRemainder) / freq;
  *t_tv_nsec = timeRemainder * 1.0E+9 / freq;
}

/*
 * Arguments    : char *aBuf
 *                const int aDim
 * Return Type  : void
 */
static void rtAddSizeString(char *aBuf, const int aDim)
{
  char dimStr[1024];
  char b_dimStr[1024];
  sprintf(&dimStr[0], "[%d]", aDim);
  if (strlen(&aBuf[0]) + strlen(&dimStr[0]) < 1024) {
    memcpy(&b_dimStr[0], &dimStr[0], 1024U * sizeof(char));
    strcat(aBuf, b_dimStr);
  }
}

/*
 * Arguments    : int aIndexValue
 *                int aLoBound
 *                int aHiBound
 *                const rtBoundsCheckInfo *aInfo
 * Return Type  : void
 */
static void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
  const rtBoundsCheckInfo *aInfo)
{
  if (aLoBound == 0) {
    aIndexValue++;
    aLoBound = 1;
    aHiBound++;
  }

  if (rtIsNullOrEmptyString(aInfo->aName)) {
    fprintf(stderr,
            "Index exceeds array dimensions.  Index value %d exceeds valid range [%d-%d].",
            aIndexValue, aLoBound, aHiBound);
    fprintf(stderr, "\n");
  } else {
    fprintf(stderr,
            "Index exceeds array dimensions.  Index value %d exceeds valid range [%d-%d] of array %s.",
            aIndexValue, aLoBound, aHiBound, aInfo->aName);
    fprintf(stderr, "\n");
  }

  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const int b
 *                const char *c
 *                const rtRunTimeErrorInfo *aInfo
 * Return Type  : void
 */
static void rtErrorWithMessageID(const int b, const char *c, const
  rtRunTimeErrorInfo *aInfo)
{
  fprintf(stderr, "Call to \'%.*s\' failed.", b, c);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const int aNDims
 *                const int *aDims
 *                char *aBuf
 * Return Type  : void
 */
static void rtGenSizeString(const int aNDims, const int *aDims, char *aBuf)
{
  int i;
  aBuf[0] = '\x00';
  for (i = 0; i < aNDims; i++) {
    rtAddSizeString(aBuf, aDims[i]);
  }
}

/*
 * Arguments    : const double aInteger
 *                const rtDoubleCheckInfo *aInfo
 * Return Type  : void
 */
static void rtIntegerError(const double aInteger, const rtDoubleCheckInfo *aInfo)
{
  fprintf(stderr,
          "Expected a value representable in the C type \'int\'.  Found %g instead.",
          aInteger);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const char *aString
 * Return Type  : boolean_T
 */
static boolean_T rtIsNullOrEmptyString(const char *aString)
{
  return (aString == NULL) || (*aString == '\x00');
}

/*
 * Arguments    : const double aPositive
 *                const rtDoubleCheckInfo *aInfo
 * Return Type  : void
 */
static void rtNonNegativeError(const double aPositive, const rtDoubleCheckInfo
  *aInfo)
{
  fprintf(stderr,
          "Value %g is not greater than or equal to zero.\nExiting to prevent memory corruption.",
          aPositive);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const char * aFcnName
 *                int aLineNo
 * Return Type  : void
 */
static void rtReportErrorLocation(const char * aFcnName, int aLineNo)
{
  fprintf(stderr, "Error in %s (line %d)", aFcnName, aLineNo);
  fprintf(stderr, "\n");
}

/*
 * Arguments    : const int aDim1
 *                const int aDim2
 *                const rtEqualityCheckInfo *aInfo
 * Return Type  : void
 */
static void rtSizeEq1DError(const int aDim1, const int aDim2, const
  rtEqualityCheckInfo *aInfo)
{
  fprintf(stderr, "Sizes mismatch: %d ~= %d.", aDim1, aDim2);
  fprintf(stderr, "\n");
  if (aInfo != NULL) {
    rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
  }

  fflush(stderr);
  abort();
}

/*
 * Arguments    : const int *aDims1
 *                const int aNDims1
 *                const int *aDims2
 *                const int aNDims2
 *                const rtEqualityCheckInfo *aInfo
 * Return Type  : void
 */
static void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1, const int
  *aDims2, const int aNDims2, const rtEqualityCheckInfo *aInfo)
{
  int i;
  int j;
  char dims1Str[1024];
  char dims2Str[1024];
  i = 0;
  j = 0;
  while ((i < aNDims1) && (j < aNDims2)) {
    while ((i < aNDims1) && (aDims1[i] == 1)) {
      i++;
    }

    while ((j < aNDims2) && (aDims2[j] == 1)) {
      j++;
    }

    if (((i < aNDims1) || (j < aNDims2)) && ((i == aNDims1) || ((j == aNDims2) ||
          ((aDims1[i] != -1) && ((aDims2[j] != -1) && (aDims1[i] != aDims2[j]))))))
    {
      rtGenSizeString(aNDims1, aDims1, dims1Str);
      rtGenSizeString(aNDims2, aDims2, dims2Str);
      fprintf(stderr, "Subscripted assignment dimension mismatch: %s ~= %s.",
              dims1Str, dims2Str);
      fprintf(stderr, "\n");
      if (aInfo != NULL) {
        rtReportErrorLocation(aInfo->fName, aInfo->lineNo);
      }

      fflush(stderr);
      abort();
    }

    i++;
    j++;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void tic(void)
{
  double t0_tv_sec;
  double t0_tv_nsec;
  getTime(&t0_tv_sec, &t0_tv_nsec);
  timeKeeper(t0_tv_sec, t0_tv_nsec);
}

/*
 * Arguments    : double newTime_tv_sec
 *                double newTime_tv_nsec
 * Return Type  : void
 */
static void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec)
{
  double d;
  double d1;
  if (!savedTime_not_empty) {
    getTime(&d, &d1);
    savedTime.tv_nsec = d1;
    savedTime.tv_sec = d;
    savedTime_not_empty = true;
  }

  savedTime.tv_sec = newTime_tv_sec;
  savedTime.tv_nsec = newTime_tv_nsec;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double toc(void)
{
  double tstart_tv_sec;
  double tstart_tv_nsec;
  double tnow_tv_sec;
  double tnow_tv_nsec;
  b_timeKeeper(&tstart_tv_sec, &tstart_tv_nsec);
  getTime(&tnow_tv_sec, &tnow_tv_nsec);
  return (tnow_tv_sec - tstart_tv_sec) + (tnow_tv_nsec - tstart_tv_nsec) /
    1.0E+9;
}

/*
 * EM algorithm to fit the parameters of HMM model (a.k.a Baum-Welch algorithm)
 *  Input:
 *    O: 1 x T observation matrix
 *    lambda: model containing A, B, pi
 *    maxIter: maximum number of E/M iterations
 *    tol: tolerance between E/M steps (minimum change in model), or finish
 *  Output:s
 *    lambdaN: trained model containing A, B, pi
 *    llh: loglikelihood of observation given model
 *  Written by Mo Chen (sth4nth@gmail.com).
 * Arguments    : const emxArray_real_T *O
 *                struct0_T *lambda
 *                double maxIter
 *                double tol
 *                emxArray_real_T *llh
 * Return Type  : void
 */
void hmmEM(const emxArray_real_T *O, struct0_T *lambda, double maxIter, double
           tol, emxArray_real_T *llh)
{
  int Q;
  int i;
  double denom;
  int loop_ub;
  emxArray_real_T *b_gamma;
  emxArray_real_T *xi;
  emxArray_real_T *c;
  emxArray_real_T *r;
  emxArray_real_T *alpha;
  emxArray_real_T *beta;
  int exitg1;
  int T;
  int N;
  int b_i;
  int i1;
  int i2;
  int t;
  int i3;
  int j;
  int i4;
  int i5;
  double numer;
  if (isInitialized_hmmEM == false) {
    hmmEM_initialize();
  }

  /*  Prohibit inlining to reduce code size. */
  Q = 0;
  i = llh->size[0] * llh->size[1];
  llh->size[0] = 1;
  emxEnsureCapacity_real_T(llh, i);
  if (!(maxIter >= 0.0)) {
    rtNonNegativeError(maxIter, &d_emlrtDCI);
  }

  denom = (int)floor(maxIter);
  if (maxIter != denom) {
    rtIntegerError(maxIter, &c_emlrtDCI);
  }

  i = llh->size[0] * llh->size[1];
  loop_ub = (int)maxIter;
  llh->size[1] = loop_ub;
  emxEnsureCapacity_real_T(llh, i);
  if (!(maxIter >= 0.0)) {
    rtNonNegativeError(maxIter, &g_emlrtDCI);
  }

  if (maxIter != denom) {
    rtIntegerError(maxIter, &f_emlrtDCI);
  }

  for (i = 0; i < loop_ub; i++) {
    llh->data[i] = 0.0;
  }

  /*  do until condition is met */
  emxInit_real_T(&b_gamma, 2);
  emxInit_real_T(&xi, 3);
  emxInit_real_T(&c, 2);
  emxInit_real_T(&r, 1);
  emxInit_real_T(&alpha, 2);
  emxInit_real_T(&beta, 2);
  do {
    exitg1 = 0;

    /*  iteration counter */
    if (Q > 2147483646) {
      Q = MAX_int32_T;
    } else {
      Q++;
    }

    tic();

    /*  determine parameters, Expectation step (E) */
    /*  Implmentation function HMM smoothing alogrithm. */
    /*  Unlike the method described in the book of PRML, the alpha returned is the normalized version: gamma(t)=p(z_t|x_{1:T}) */
    /*  Computing unnormalized version gamma(t)=p(z_t,x_{1:T}) is numerical unstable, which grows exponential fast to infinity. */
    /*  Input: */
    /*    O:  1 x T observation matrix */
    /*    A:  N x N transition probability matrix */
    /*    B:  M x N emission probability matrix */
    /*    pi: N x 1 start prior probability */
    /*  Output: */
    /*    gamma:   N x T      smoothed node marginals gamma(i,t)=p(O1:Ot, s_i | lambda) */
    /*    epsilon: N x N x T  smoothed edge marginals epsilon(i,j,t)=p(s_i, s_j | O, lambda) */
    /*    alpha: k x n matrix of posterior alpha(t)=p(z_t|x_{1:T}) */
    /*    beta: k x n matrix of posterior beta(t)=gamma(t)/alpha(t) */
    /*    c: loglikelihood */
    /*  Written by Mo Chen (sth4nth@gmail.com). */
    T = O->size[1];
    N = lambda->A->size[0] - 1;
    i = c->size[0] * c->size[1];
    c->size[0] = 1;
    c->size[1] = O->size[1];
    emxEnsureCapacity_real_T(c, i);
    loop_ub = O->size[1];
    for (i = 0; i < loop_ub; i++) {
      c->data[i] = 0.0;
    }

    /*  normalization constant */
    /*  alpha calc */
    i = alpha->size[0] * alpha->size[1];
    alpha->size[0] = lambda->A->size[0];
    alpha->size[1] = O->size[1];
    emxEnsureCapacity_real_T(alpha, i);
    loop_ub = lambda->A->size[0] * O->size[1];
    for (i = 0; i < loop_ub; i++) {
      alpha->data[i] = 0.0;
    }

    /* alpha_1 */
    i = lambda->A->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (1 > alpha->size[1]) {
        rtDynamicBoundsError(1, 1, alpha->size[1], &t_emlrtBCI);
      }

      i1 = lambda->B->size[0];
      if (1 > i1) {
        rtDynamicBoundsError(1, 1, i1, &r_emlrtBCI);
      }

      if (1 > O->size[1]) {
        rtDynamicBoundsError(1, 1, O->size[1], &s_emlrtBCI);
      }

      i1 = lambda->pi->size[0];
      i2 = (int)(b_i + 1U);
      if ((i2 < 1) || (i2 > i1)) {
        rtDynamicBoundsError(i2, 1, i1, &cb_emlrtBCI);
      }

      i1 = lambda->B->size[1];
      if (O->data[0] != (int)floor(O->data[0])) {
        rtIntegerError(O->data[0], &h_emlrtDCI);
      }

      i3 = (int)O->data[0];
      if ((i3 < 1) || (i3 > i1)) {
        rtDynamicBoundsError(i3, 1, i1, &db_emlrtBCI);
      }

      if (i2 > alpha->size[0]) {
        rtDynamicBoundsError(i2, 1, alpha->size[0], &eb_emlrtBCI);
      }

      alpha->data[i2 - 1] = lambda->pi->data[i2 - 1] * lambda->B->data[lambda->
        B->size[0] * (i3 - 1)];
      if (1 > T) {
        rtDynamicBoundsError(1, 1, T, &v_emlrtBCI);
      }

      if (1 > alpha->size[1]) {
        rtDynamicBoundsError(1, 1, alpha->size[1], &u_emlrtBCI);
      }

      if (i2 > alpha->size[0]) {
        rtDynamicBoundsError(i2, 1, alpha->size[0], &fb_emlrtBCI);
      }

      c->data[0] += alpha->data[i2 - 1];
    }

    /* scale alpha_1 */
    if (1 > O->size[1]) {
      rtDynamicBoundsError(1, 1, O->size[1], &w_emlrtBCI);
    }

    c->data[0] = 1.0 / c->data[0];
    i = lambda->A->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (1 > alpha->size[1]) {
        rtDynamicBoundsError(1, 1, alpha->size[1], &ab_emlrtBCI);
      }

      if (1 > T) {
        rtDynamicBoundsError(1, 1, T, &x_emlrtBCI);
      }

      if (1 > alpha->size[1]) {
        rtDynamicBoundsError(1, 1, alpha->size[1], &y_emlrtBCI);
      }

      i1 = (int)(b_i + 1U);
      if ((i1 < 1) || (i1 > alpha->size[0])) {
        rtDynamicBoundsError(i1, 1, alpha->size[0], &hb_emlrtBCI);
      }

      if (i1 > alpha->size[0]) {
        rtDynamicBoundsError(i1, 1, alpha->size[0], &ib_emlrtBCI);
      }

      alpha->data[i1 - 1] *= c->data[0];
    }

    /* compute alpha_t(i) */
    i = O->size[1];
    for (t = 0; t <= i - 2; t++) {
      i1 = t + 2;
      if ((i1 < 1) || (i1 > c->size[1])) {
        rtDynamicBoundsError(i1, 1, c->size[1], &gb_emlrtBCI);
      }

      c->data[i1 - 1] = 0.0;
      for (j = 0; j <= N; j++) {
        i1 = (int)(j + 1U);
        if ((i1 < 1) || (i1 > alpha->size[0])) {
          rtDynamicBoundsError(i1, 1, alpha->size[0], &jb_emlrtBCI);
        }

        i2 = t + 2;
        if ((i2 < 1) || (i2 > alpha->size[1])) {
          rtDynamicBoundsError(i2, 1, alpha->size[1], &jb_emlrtBCI);
        }

        alpha->data[(i1 + alpha->size[0] * (i2 - 1)) - 1] = 0.0;

        /* initialize alpha_t(j) */
        for (b_i = 0; b_i <= N; b_i++) {
          if (i1 > alpha->size[0]) {
            rtDynamicBoundsError(i1, 1, alpha->size[0], &mb_emlrtBCI);
          }

          i2 = t + 2;
          if ((i2 < 1) || (i2 > alpha->size[1])) {
            rtDynamicBoundsError(i2, 1, alpha->size[1], &mb_emlrtBCI);
          }

          i3 = (int)(b_i + 1U);
          if ((i3 < 1) || (i3 > alpha->size[0])) {
            rtDynamicBoundsError(i3, 1, alpha->size[0], &nb_emlrtBCI);
          }

          i4 = t + 1;
          if ((i4 < 1) || (i4 > alpha->size[1])) {
            rtDynamicBoundsError(i4, 1, alpha->size[1], &nb_emlrtBCI);
          }

          loop_ub = lambda->A->size[0];
          if (i3 > loop_ub) {
            rtDynamicBoundsError(i3, 1, loop_ub, &ob_emlrtBCI);
          }

          loop_ub = lambda->A->size[1];
          if (i1 > loop_ub) {
            rtDynamicBoundsError(i1, 1, loop_ub, &ob_emlrtBCI);
          }

          if (i1 > alpha->size[0]) {
            rtDynamicBoundsError(i1, 1, alpha->size[0], &pb_emlrtBCI);
          }

          loop_ub = t + 2;
          if ((loop_ub < 1) || (loop_ub > alpha->size[1])) {
            rtDynamicBoundsError(loop_ub, 1, alpha->size[1], &pb_emlrtBCI);
          }

          alpha->data[(i1 + alpha->size[0] * (loop_ub - 1)) - 1] = alpha->data
            [(i1 + alpha->size[0] * (i2 - 1)) - 1] + alpha->data[(i3 +
            alpha->size[0] * (i4 - 1)) - 1] * lambda->A->data[(i3 + lambda->
            A->size[0] * (i1 - 1)) - 1];
        }

        /* i */
        if (i1 > alpha->size[0]) {
          rtDynamicBoundsError(i1, 1, alpha->size[0], &qb_emlrtBCI);
        }

        i2 = t + 2;
        if ((i2 < 1) || (i2 > alpha->size[1])) {
          rtDynamicBoundsError(i2, 1, alpha->size[1], &qb_emlrtBCI);
        }

        i3 = lambda->B->size[0];
        if (i1 > i3) {
          rtDynamicBoundsError(i1, 1, i3, &rb_emlrtBCI);
        }

        i3 = lambda->B->size[1];
        i4 = t + 2;
        if ((i4 < 1) || (i4 > O->size[1])) {
          rtDynamicBoundsError(i4, 1, O->size[1], &sb_emlrtBCI);
        }

        denom = O->data[i4 - 1];
        if (denom != (int)floor(denom)) {
          rtIntegerError(denom, &i_emlrtDCI);
        }

        i4 = (int)denom;
        if ((i4 < 1) || (i4 > i3)) {
          rtDynamicBoundsError(i4, 1, i3, &rb_emlrtBCI);
        }

        if (i1 > alpha->size[0]) {
          rtDynamicBoundsError(i1, 1, alpha->size[0], &tb_emlrtBCI);
        }

        i3 = t + 2;
        if ((i3 < 1) || (i3 > alpha->size[1])) {
          rtDynamicBoundsError(i3, 1, alpha->size[1], &tb_emlrtBCI);
        }

        alpha->data[(i1 + alpha->size[0] * (i3 - 1)) - 1] = alpha->data[(i1 +
          alpha->size[0] * (i2 - 1)) - 1] * lambda->B->data[(i1 + lambda->
          B->size[0] * (i4 - 1)) - 1];
        i2 = t + 2;
        if ((i2 < 1) || (i2 > c->size[1])) {
          rtDynamicBoundsError(i2, 1, c->size[1], &ac_emlrtBCI);
        }

        if (i1 > alpha->size[0]) {
          rtDynamicBoundsError(i1, 1, alpha->size[0], &bc_emlrtBCI);
        }

        i3 = t + 2;
        if ((i3 < 1) || (i3 > alpha->size[1])) {
          rtDynamicBoundsError(i3, 1, alpha->size[1], &bc_emlrtBCI);
        }

        i4 = t + 2;
        if ((i4 < 1) || (i4 > c->size[1])) {
          rtDynamicBoundsError(i4, 1, c->size[1], &cc_emlrtBCI);
        }

        c->data[i4 - 1] = c->data[i2 - 1] + alpha->data[(i1 + alpha->size[0] *
          (i3 - 1)) - 1];
      }

      /* j */
      /* scale alpha_t */
      i1 = t + 2;
      if ((i1 < 1) || (i1 > c->size[1])) {
        rtDynamicBoundsError(i1, 1, c->size[1], &kb_emlrtBCI);
      }

      i2 = t + 2;
      if ((i2 < 1) || (i2 > c->size[1])) {
        rtDynamicBoundsError(i2, 1, c->size[1], &lb_emlrtBCI);
      }

      c->data[i2 - 1] = 1.0 / c->data[i1 - 1];
      for (j = 0; j <= N; j++) {
        i1 = t + 2;
        if ((i1 < 1) || (i1 > c->size[1])) {
          rtDynamicBoundsError(i1, 1, c->size[1], &wb_emlrtBCI);
        }

        i2 = (int)(j + 1U);
        if ((i2 < 1) || (i2 > alpha->size[0])) {
          rtDynamicBoundsError(i2, 1, alpha->size[0], &xb_emlrtBCI);
        }

        i3 = t + 2;
        if ((i3 < 1) || (i3 > alpha->size[1])) {
          rtDynamicBoundsError(i3, 1, alpha->size[1], &xb_emlrtBCI);
        }

        if (i2 > alpha->size[0]) {
          rtDynamicBoundsError(i2, 1, alpha->size[0], &yb_emlrtBCI);
        }

        i4 = t + 2;
        if ((i4 < 1) || (i4 > alpha->size[1])) {
          rtDynamicBoundsError(i4, 1, alpha->size[1], &yb_emlrtBCI);
        }

        alpha->data[(i2 + alpha->size[0] * (i4 - 1)) - 1] = c->data[i1 - 1] *
          alpha->data[(i2 + alpha->size[0] * (i3 - 1)) - 1];
      }
    }

    /* t */
    /*  beta calc */
    i = beta->size[0] * beta->size[1];
    beta->size[0] = lambda->A->size[0];
    beta->size[1] = O->size[1];
    emxEnsureCapacity_real_T(beta, i);
    loop_ub = lambda->A->size[0] * O->size[1];
    for (i = 0; i < loop_ub; i++) {
      beta->data[i] = 0.0;
    }

    /* beta_T scaling */
    i = lambda->A->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if ((T < 1) || (T > c->size[1])) {
        rtDynamicBoundsError(T, 1, c->size[1], &ub_emlrtBCI);
      }

      i1 = (int)(b_i + 1U);
      if ((i1 < 1) || (i1 > beta->size[0])) {
        rtDynamicBoundsError(i1, 1, beta->size[0], &vb_emlrtBCI);
      }

      if (T > beta->size[1]) {
        rtDynamicBoundsError(T, 1, beta->size[1], &vb_emlrtBCI);
      }

      beta->data[(i1 + beta->size[0] * (T - 1)) - 1] = c->data[T - 1];

      /*  initialization says beta_T = 1 */
    }

    /* beta_t(i) */
    i = (int)(((-1.0 - ((double)O->size[1] - 1.0)) + 1.0) / -1.0);
    for (t = 0; t < i; t++) {
      loop_ub = (T - t) - 1;
      for (b_i = 0; b_i <= N; b_i++) {
        i1 = (int)(b_i + 1U);
        if ((i1 < 1) || (i1 > beta->size[0])) {
          rtDynamicBoundsError(i1, 1, beta->size[0], &dc_emlrtBCI);
        }

        if ((loop_ub < 1) || (loop_ub > beta->size[1])) {
          rtDynamicBoundsError(loop_ub, 1, beta->size[1], &dc_emlrtBCI);
        }

        beta->data[(i1 + beta->size[0] * (loop_ub - 1)) - 1] = 0.0;
        for (j = 0; j <= N; j++) {
          if (i1 > beta->size[0]) {
            rtDynamicBoundsError(i1, 1, beta->size[0], &ec_emlrtBCI);
          }

          if (loop_ub > beta->size[1]) {
            rtDynamicBoundsError(loop_ub, 1, beta->size[1], &ec_emlrtBCI);
          }

          i2 = lambda->A->size[0];
          if (i1 > i2) {
            rtDynamicBoundsError(i1, 1, i2, &fc_emlrtBCI);
          }

          i2 = lambda->A->size[1];
          i3 = (int)(j + 1U);
          if ((i3 < 1) || (i3 > i2)) {
            rtDynamicBoundsError(i3, 1, i2, &fc_emlrtBCI);
          }

          i2 = lambda->B->size[0];
          if (i3 > i2) {
            rtDynamicBoundsError(i3, 1, i2, &gc_emlrtBCI);
          }

          i2 = lambda->B->size[1];
          i4 = loop_ub + 1;
          if ((i4 < 1) || (i4 > O->size[1])) {
            rtDynamicBoundsError(i4, 1, O->size[1], &hc_emlrtBCI);
          }

          denom = O->data[i4 - 1];
          if (denom != (int)floor(denom)) {
            rtIntegerError(denom, &k_emlrtDCI);
          }

          i4 = (int)denom;
          if ((i4 < 1) || (i4 > i2)) {
            rtDynamicBoundsError(i4, 1, i2, &gc_emlrtBCI);
          }

          if (i3 > beta->size[0]) {
            rtDynamicBoundsError(i3, 1, beta->size[0], &ic_emlrtBCI);
          }

          i2 = loop_ub + 1;
          if ((i2 < 1) || (i2 > beta->size[1])) {
            rtDynamicBoundsError(i2, 1, beta->size[1], &ic_emlrtBCI);
          }

          if (i1 > beta->size[0]) {
            rtDynamicBoundsError(i1, 1, beta->size[0], &jc_emlrtBCI);
          }

          if (loop_ub > beta->size[1]) {
            rtDynamicBoundsError(loop_ub, 1, beta->size[1], &jc_emlrtBCI);
          }

          beta->data[(i1 + beta->size[0] * (loop_ub - 1)) - 1] += lambda->
            A->data[(i1 + lambda->A->size[0] * (i3 - 1)) - 1] * lambda->B->data
            [(i3 + lambda->B->size[0] * (i4 - 1)) - 1] * beta->data[(i3 +
            beta->size[0] * (i2 - 1)) - 1];
        }

        /* j */
        /* scale beta_t with same c_t as alpha_t */
        if (loop_ub > c->size[1]) {
          rtDynamicBoundsError(loop_ub, 1, c->size[1], &kc_emlrtBCI);
        }

        if (i1 > beta->size[0]) {
          rtDynamicBoundsError(i1, 1, beta->size[0], &lc_emlrtBCI);
        }

        if (loop_ub > beta->size[1]) {
          rtDynamicBoundsError(loop_ub, 1, beta->size[1], &lc_emlrtBCI);
        }

        if (i1 > beta->size[0]) {
          rtDynamicBoundsError(i1, 1, beta->size[0], &mc_emlrtBCI);
        }

        if (loop_ub > beta->size[1]) {
          rtDynamicBoundsError(loop_ub, 1, beta->size[1], &mc_emlrtBCI);
        }

        beta->data[(i1 + beta->size[0] * (loop_ub - 1)) - 1] *= c->data[loop_ub
          - 1];
      }

      /* i */
    }

    /* t */
    /* compute epsilon_t and gamma_t (no need to normalize, alpha and beta are scaled) */
    i = xi->size[0] * xi->size[1] * xi->size[2];
    xi->size[0] = lambda->A->size[0];
    xi->size[1] = lambda->A->size[0];
    emxEnsureCapacity_real_T(xi, i);
    i = O->size[1] - 1;
    if (i < 0) {
      rtNonNegativeError(i, &e_emlrtDCI);
    }

    i1 = xi->size[0] * xi->size[1] * xi->size[2];
    xi->size[2] = i;
    emxEnsureCapacity_real_T(xi, i1);
    i = O->size[1] - 1;
    if (i < 0) {
      rtNonNegativeError(i, &j_emlrtDCI);
    }

    loop_ub = lambda->A->size[0] * lambda->A->size[0] * i;
    for (i = 0; i < loop_ub; i++) {
      xi->data[i] = 0.0;
    }

    /* also called "di-gamma" */
    i = b_gamma->size[0] * b_gamma->size[1];
    b_gamma->size[0] = lambda->A->size[0];
    b_gamma->size[1] = O->size[1];
    emxEnsureCapacity_real_T(b_gamma, i);
    loop_ub = lambda->A->size[0] * O->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_gamma->data[i] = 0.0;
    }

    i = O->size[1];
    for (t = 0; t <= i - 2; t++) {
      for (b_i = 0; b_i <= N; b_i++) {
        i1 = (int)(b_i + 1U);
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          rtDynamicBoundsError(i1, 1, b_gamma->size[0], &nc_emlrtBCI);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          rtDynamicBoundsError(i2, 1, b_gamma->size[1], &nc_emlrtBCI);
        }

        b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1] = 0.0;
        for (j = 0; j <= N; j++) {
          if (i1 > alpha->size[0]) {
            rtDynamicBoundsError(i1, 1, alpha->size[0], &qc_emlrtBCI);
          }

          i2 = t + 1;
          if ((i2 < 1) || (i2 > alpha->size[1])) {
            rtDynamicBoundsError(i2, 1, alpha->size[1], &qc_emlrtBCI);
          }

          i3 = lambda->A->size[0];
          if (i1 > i3) {
            rtDynamicBoundsError(i1, 1, i3, &rc_emlrtBCI);
          }

          i3 = lambda->A->size[1];
          i4 = (int)(j + 1U);
          if ((i4 < 1) || (i4 > i3)) {
            rtDynamicBoundsError(i4, 1, i3, &rc_emlrtBCI);
          }

          i3 = lambda->B->size[0];
          if (i4 > i3) {
            rtDynamicBoundsError(i4, 1, i3, &sc_emlrtBCI);
          }

          i3 = lambda->B->size[1];
          loop_ub = t + 2;
          if ((loop_ub < 1) || (loop_ub > O->size[1])) {
            rtDynamicBoundsError(loop_ub, 1, O->size[1], &tc_emlrtBCI);
          }

          denom = O->data[loop_ub - 1];
          if (denom != (int)floor(denom)) {
            rtIntegerError(denom, &l_emlrtDCI);
          }

          loop_ub = (int)denom;
          if ((loop_ub < 1) || (loop_ub > i3)) {
            rtDynamicBoundsError(loop_ub, 1, i3, &sc_emlrtBCI);
          }

          if (i4 > beta->size[0]) {
            rtDynamicBoundsError(i4, 1, beta->size[0], &uc_emlrtBCI);
          }

          i3 = t + 2;
          if ((i3 < 1) || (i3 > beta->size[1])) {
            rtDynamicBoundsError(i3, 1, beta->size[1], &uc_emlrtBCI);
          }

          if (i1 > xi->size[0]) {
            rtDynamicBoundsError(i1, 1, xi->size[0], &vc_emlrtBCI);
          }

          if (i4 > xi->size[1]) {
            rtDynamicBoundsError(i4, 1, xi->size[1], &vc_emlrtBCI);
          }

          i5 = t + 1;
          if ((i5 < 1) || (i5 > xi->size[2])) {
            rtDynamicBoundsError(i5, 1, xi->size[2], &vc_emlrtBCI);
          }

          xi->data[((i1 + xi->size[0] * (i4 - 1)) + xi->size[0] * xi->size[1] *
                    (i5 - 1)) - 1] = alpha->data[(i1 + alpha->size[0] * (i2 - 1))
            - 1] * lambda->A->data[(i1 + lambda->A->size[0] * (i4 - 1)) - 1] *
            lambda->B->data[(i4 + lambda->B->size[0] * (loop_ub - 1)) - 1] *
            beta->data[(i4 + beta->size[0] * (i3 - 1)) - 1];
          if (i1 > b_gamma->size[0]) {
            rtDynamicBoundsError(i1, 1, b_gamma->size[0], &wc_emlrtBCI);
          }

          i2 = t + 1;
          if ((i2 < 1) || (i2 > b_gamma->size[1])) {
            rtDynamicBoundsError(i2, 1, b_gamma->size[1], &wc_emlrtBCI);
          }

          if (i1 > xi->size[0]) {
            rtDynamicBoundsError(i1, 1, xi->size[0], &xc_emlrtBCI);
          }

          if (i4 > xi->size[1]) {
            rtDynamicBoundsError(i4, 1, xi->size[1], &xc_emlrtBCI);
          }

          i3 = t + 1;
          if ((i3 < 1) || (i3 > xi->size[2])) {
            rtDynamicBoundsError(i3, 1, xi->size[2], &xc_emlrtBCI);
          }

          if (i1 > b_gamma->size[0]) {
            rtDynamicBoundsError(i1, 1, b_gamma->size[0], &yc_emlrtBCI);
          }

          loop_ub = t + 1;
          if ((loop_ub < 1) || (loop_ub > b_gamma->size[1])) {
            rtDynamicBoundsError(loop_ub, 1, b_gamma->size[1], &yc_emlrtBCI);
          }

          b_gamma->data[(i1 + b_gamma->size[0] * (loop_ub - 1)) - 1] =
            b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1] + xi->data
            [((i1 + xi->size[0] * (i4 - 1)) + xi->size[0] * xi->size[1] * (i3 -
               1)) - 1];
        }

        /* j */
      }

      /* i */
    }

    /* t */
    /* special case gamma */
    i = lambda->A->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      i1 = (int)(b_i + 1U);
      if ((i1 < 1) || (i1 > alpha->size[0])) {
        rtDynamicBoundsError(i1, 1, alpha->size[0], &oc_emlrtBCI);
      }

      if ((T < 1) || (T > alpha->size[1])) {
        rtDynamicBoundsError(T, 1, alpha->size[1], &oc_emlrtBCI);
      }

      if (i1 > b_gamma->size[0]) {
        rtDynamicBoundsError(i1, 1, b_gamma->size[0], &pc_emlrtBCI);
      }

      if (T > b_gamma->size[1]) {
        rtDynamicBoundsError(T, 1, b_gamma->size[1], &pc_emlrtBCI);
      }

      b_gamma->data[(i1 + b_gamma->size[0] * (T - 1)) - 1] = alpha->data[(i1 +
        alpha->size[0] * (T - 1)) - 1];
    }

    denom = toc();
    printf("Smoother took %.2f seconds on interation %d \n", denom, Q);
    fflush(stdout);
    tic();

    /*  re-estimate parameters, Maximization step (M) */
    /*  EM algorithm to fit the parameters of HMM model (a.k.a Baum-Welch algorithm) */
    /*  Input: */
    /*    O: 1 x T observation matrix */
    /*    lambda: model containing A, B, pi */
    /*    maxIter: maximum number of E/M iterations */
    /*    tol: tolerance between E/M steps (minimum change in model), or finish */
    /*  Output:s */
    /*    lambdaN: trained model containing A, B, pi */
    /*    llh: loglikelihood of observation given model */
    /*  Written by Mo Chen (sth4nth@gmail.com). */
    /*  init with a model */
    i = alpha->size[0] * alpha->size[1];
    alpha->size[0] = lambda->A->size[0];
    alpha->size[1] = lambda->A->size[1];
    emxEnsureCapacity_real_T(alpha, i);
    loop_ub = lambda->A->size[0] * lambda->A->size[1];
    for (i = 0; i < loop_ub; i++) {
      alpha->data[i] = lambda->A->data[i];
    }

    i = beta->size[0] * beta->size[1];
    beta->size[0] = lambda->B->size[0];
    beta->size[1] = lambda->B->size[1];
    emxEnsureCapacity_real_T(beta, i);
    loop_ub = lambda->B->size[0] * lambda->B->size[1];
    for (i = 0; i < loop_ub; i++) {
      beta->data[i] = lambda->B->data[i];
    }

    i = r->size[0];
    r->size[0] = lambda->pi->size[0];
    emxEnsureCapacity_real_T(r, i);
    loop_ub = lambda->pi->size[0];
    for (i = 0; i < loop_ub; i++) {
      r->data[i] = lambda->pi->data[i];
    }

    T = O->size[1] - 2;

    /*  re-estimate pi */
    i = lambda->B->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (1 > b_gamma->size[1]) {
        rtDynamicBoundsError(1, 1, b_gamma->size[1], &bb_emlrtBCI);
      }

      i1 = (int)(b_i + 1U);
      if ((i1 < 1) || (i1 > b_gamma->size[0])) {
        rtDynamicBoundsError(i1, 1, b_gamma->size[0], &ad_emlrtBCI);
      }

      if (i1 > r->size[0]) {
        rtDynamicBoundsError(i1, 1, r->size[0], &bd_emlrtBCI);
      }

      r->data[i1 - 1] = b_gamma->data[i1 - 1];
    }

    tic();

    /*  re-estimate A */
    i = lambda->B->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      denom = 0.0;
      for (t = 0; t <= T; t++) {
        i1 = (int)(b_i + 1U);
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          rtDynamicBoundsError(i1, 1, b_gamma->size[0], &cd_emlrtBCI);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          rtDynamicBoundsError(i2, 1, b_gamma->size[1], &cd_emlrtBCI);
        }

        denom += b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1];
      }

      /* t */
      i1 = lambda->B->size[0];
      for (j = 0; j < i1; j++) {
        numer = 0.0;
        for (t = 0; t <= T; t++) {
          i2 = (int)(b_i + 1U);
          if ((i2 < 1) || (i2 > xi->size[0])) {
            rtDynamicBoundsError(i2, 1, xi->size[0], &ed_emlrtBCI);
          }

          i3 = (int)(j + 1U);
          if ((i3 < 1) || (i3 > xi->size[1])) {
            rtDynamicBoundsError(i3, 1, xi->size[1], &ed_emlrtBCI);
          }

          i4 = t + 1;
          if ((i4 < 1) || (i4 > xi->size[2])) {
            rtDynamicBoundsError(i4, 1, xi->size[2], &ed_emlrtBCI);
          }

          numer += xi->data[((i2 + xi->size[0] * (i3 - 1)) + xi->size[0] *
                             xi->size[1] * (i4 - 1)) - 1];
        }

        /* t */
        i2 = (int)(b_i + 1U);
        if ((i2 < 1) || (i2 > alpha->size[0])) {
          rtDynamicBoundsError(i2, 1, alpha->size[0], &fd_emlrtBCI);
        }

        i3 = (int)(j + 1U);
        if ((i3 < 1) || (i3 > alpha->size[1])) {
          rtDynamicBoundsError(i3, 1, alpha->size[1], &fd_emlrtBCI);
        }

        alpha->data[(i2 + alpha->size[0] * (i3 - 1)) - 1] = numer / denom;
      }

      /* j */
    }

    /* i */
    /*  re-estimate B */
    i = lambda->B->size[0];
    for (j = 0; j < i; j++) {
      denom = 0.0;
      for (t = 0; t <= T + 1; t++) {
        i1 = (int)(j + 1U);
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          rtDynamicBoundsError(i1, 1, b_gamma->size[0], &dd_emlrtBCI);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          rtDynamicBoundsError(i2, 1, b_gamma->size[1], &dd_emlrtBCI);
        }

        denom += b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1];
      }

      /* t */
      i1 = lambda->B->size[1];
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        numer = 0.0;
        for (t = 0; t <= T + 1; t++) {
          i2 = t + 1;
          if ((i2 < 1) || (i2 > O->size[1])) {
            rtDynamicBoundsError(i2, 1, O->size[1], &gd_emlrtBCI);
          }

          if (O->data[i2 - 1] == (double)loop_ub + 1.0) {
            i2 = (int)(j + 1U);
            if ((i2 < 1) || (i2 > b_gamma->size[0])) {
              rtDynamicBoundsError(i2, 1, b_gamma->size[0], &id_emlrtBCI);
            }

            i3 = t + 1;
            if ((i3 < 1) || (i3 > b_gamma->size[1])) {
              rtDynamicBoundsError(i3, 1, b_gamma->size[1], &id_emlrtBCI);
            }

            numer += b_gamma->data[(i2 + b_gamma->size[0] * (i3 - 1)) - 1];
          }
        }

        /* t */
        i2 = (int)(j + 1U);
        if ((i2 < 1) || (i2 > beta->size[0])) {
          rtDynamicBoundsError(i2, 1, beta->size[0], &hd_emlrtBCI);
        }

        i3 = (int)(loop_ub + 1U);
        if ((i3 < 1) || (i3 > beta->size[1])) {
          rtDynamicBoundsError(i3, 1, beta->size[1], &hd_emlrtBCI);
        }

        beta->data[(i2 + beta->size[0] * (i3 - 1)) - 1] = numer / denom;
      }

      /* k */
    }

    /* i */
    i = lambda->A->size[0] * lambda->A->size[1];
    lambda->A->size[0] = alpha->size[0];
    lambda->A->size[1] = alpha->size[1];
    emxEnsureCapacity_real_T(lambda->A, i);
    loop_ub = alpha->size[0] * alpha->size[1];
    for (i = 0; i < loop_ub; i++) {
      lambda->A->data[i] = alpha->data[i];
    }

    i = lambda->B->size[0] * lambda->B->size[1];
    lambda->B->size[0] = beta->size[0];
    lambda->B->size[1] = beta->size[1];
    emxEnsureCapacity_real_T(lambda->B, i);
    loop_ub = beta->size[0] * beta->size[1];
    for (i = 0; i < loop_ub; i++) {
      lambda->B->data[i] = beta->data[i];
    }

    i = lambda->pi->size[0];
    lambda->pi->size[0] = r->size[0];
    emxEnsureCapacity_real_T(lambda->pi, i);
    loop_ub = r->size[0];
    for (i = 0; i < loop_ub; i++) {
      lambda->pi->data[i] = r->data[i];
    }

    denom = toc();
    printf("Baum Welch took %.2f seconds on interation %d \n", denom, Q);
    fflush(stdout);

    /*  compute log(P(O|lambda)) */
    i = O->size[1];
    for (t = 0; t < i; t++) {
      i1 = t + 1;
      if ((i1 < 1) || (i1 > c->size[1])) {
        rtDynamicBoundsError(i1, 1, c->size[1], &q_emlrtBCI);
      }

      if (c->data[t] < 0.0) {
        c_rtErrorWithMessageID(3, "log", &c_emlrtRTEI);
      }

      if (Q > llh->size[1]) {
        rtDynamicBoundsError(Q, 1, llh->size[1], &pd_emlrtBCI);
      }

      if (Q > llh->size[1]) {
        rtDynamicBoundsError(Q, 1, llh->size[1], &qd_emlrtBCI);
      }

      llh->data[Q - 1] += log(c->data[t]);
    }

    /* t */
    if (Q > llh->size[1]) {
      rtDynamicBoundsError(Q, 1, llh->size[1], &jd_emlrtBCI);
    }

    if (Q > llh->size[1]) {
      rtDynamicBoundsError(Q, 1, llh->size[1], &kd_emlrtBCI);
    }

    llh->data[Q - 1] = -llh->data[Q - 1];

    /*  break when tolerance or maxIter is reached */
    if (Q >= maxIter) {
      exitg1 = 1;
    } else {
      if (Q != 1) {
        if (Q > llh->size[1]) {
          rtDynamicBoundsError(Q, 1, llh->size[1], &ld_emlrtBCI);
        }

        i = Q - 1;
        if (i > llh->size[1]) {
          rtDynamicBoundsError(i, 1, llh->size[1], &md_emlrtBCI);
        }

        if (llh->data[Q - 1] < llh->data[i - 1]) {
          exitg1 = 1;
        } else {
          if (Q > llh->size[1]) {
            rtDynamicBoundsError(Q, 1, llh->size[1], &nd_emlrtBCI);
          }

          i = Q - 1;
          if (i > llh->size[1]) {
            rtDynamicBoundsError(i, 1, llh->size[1], &od_emlrtBCI);
          }

          if (fabs(-llh->data[Q - 1] + llh->data[Q - 2]) <= tol) {
            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&beta);
  emxFree_real_T(&alpha);
  emxFree_real_T(&r);
  emxFree_real_T(&c);
  emxFree_real_T(&xi);
  emxFree_real_T(&b_gamma);

  /* while */
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_initialize(void)
{
  rt_InitInfAndNaN();
  savedTime_not_empty = false;
  freq_not_empty = false;
  isInitialized_hmmEM = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_hmmEM = false;
}

/*
 * Implmentation function of Viterbi algorithm.
 *  Input:
 *    O: 1 x T observation sequence
 *    A: k x k transition matrix
 *    B: N x M emmision data matrix
 *    s: k x 1 starting probability (prior)
 *  Output:
 *    z: 1 x n latent state
 *    p: 1 x n probability
 *  Written by Josh Parks
 * Arguments    : const emxArray_real_T *O
 *                const struct0_T *lambda
 *                emxArray_real_T *S
 *                double *logP
 * Return Type  : void
 */
void hmmViterbi(const emxArray_real_T *O, const struct0_T *lambda,
                emxArray_real_T *S, double *logP)
{
  emxArray_real_T *pi;
  int i;
  int nx;
  emxArray_real_T *logA;
  int N;
  emxArray_real_T *logB;
  boolean_T p;
  int k;
  int b_O;
  emxArray_real_T *psi;
  emxArray_real_T *delta;
  int c_O[1];
  double delta_max;
  int i1;
  int i2;
  double delta_temp;
  boolean_T exitg1;
  int a;
  double d;
  if (isInitialized_hmmEM == false) {
    hmmEM_initialize();
  }

  emxInit_real_T(&pi, 1);

  /*  Prohibit inlining to reduce code size. */
  /*  Use parameters */
  i = pi->size[0];
  pi->size[0] = lambda->pi->size[0];
  emxEnsureCapacity_real_T(pi, i);
  nx = lambda->pi->size[0];
  for (i = 0; i < nx; i++) {
    pi->data[i] = lambda->pi->data[i];
  }

  emxInit_real_T(&logA, 2);
  N = lambda->A->size[0] - 1;
  i = logA->size[0] * logA->size[1];
  logA->size[0] = lambda->A->size[0];
  logA->size[1] = lambda->A->size[1];
  emxEnsureCapacity_real_T(logA, i);
  nx = lambda->A->size[0] * lambda->A->size[1];
  for (i = 0; i < nx; i++) {
    logA->data[i] = lambda->A->data[i];
  }

  emxInit_real_T(&logB, 2);
  b_log(logA);
  i = logB->size[0] * logB->size[1];
  logB->size[0] = lambda->B->size[0];
  logB->size[1] = lambda->B->size[1];
  emxEnsureCapacity_real_T(logB, i);
  nx = lambda->B->size[0] * lambda->B->size[1];
  for (i = 0; i < nx; i++) {
    logB->data[i] = lambda->B->data[i];
  }

  b_log(logB);
  p = false;
  i = lambda->pi->size[0];
  for (k = 0; k < i; k++) {
    if (p || (lambda->pi->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    c_rtErrorWithMessageID(3, "log", &c_emlrtRTEI);
  }

  nx = lambda->pi->size[0];
  if ((1 <= lambda->pi->size[0]) && (lambda->pi->size[0] > 2147483646)) {
    check_forloop_overflow_error();
  }

  for (k = 0; k < nx; k++) {
    pi->data[k] = log(pi->data[k]);
  }

  if (1 > O->size[1]) {
    rtDynamicBoundsError(1, 1, O->size[1], &c_emlrtBCI);
  }

  if (O->data[0] != (int)floor(O->data[0])) {
    rtIntegerError(O->data[0], &emlrtDCI);
  }

  b_O = (int)O->data[0];
  if ((b_O < 1) || (b_O > logB->size[1])) {
    rtDynamicBoundsError(b_O, 1, logB->size[1], &b_emlrtBCI);
  }

  if (pi->size[0] != logB->size[0]) {
    rtSizeEq1DError(pi->size[0], logB->size[0], &b_emlrtECI);
  }

  nx = pi->size[0];
  for (i = 0; i < nx; i++) {
    pi->data[i] += logB->data[i + logB->size[0] * (b_O - 1)];
  }

  emxInit_real_T(&psi, 2);
  i = psi->size[0] * psi->size[1];
  psi->size[0] = lambda->A->size[0];
  psi->size[1] = O->size[1];
  emxEnsureCapacity_real_T(psi, i);
  nx = lambda->A->size[0] * O->size[1];
  for (i = 0; i < nx; i++) {
    psi->data[i] = 0.0;
  }

  emxInit_real_T(&delta, 2);
  i = delta->size[0] * delta->size[1];
  delta->size[0] = lambda->A->size[0];
  delta->size[1] = O->size[1];
  emxEnsureCapacity_real_T(delta, i);
  nx = lambda->A->size[0] * O->size[1];
  for (i = 0; i < nx; i++) {
    delta->data[i] = 0.0;
  }

  /*  actually this is log(delta) --> phi, but leave as  */
  /*    delta for clarity (phi != psi) */
  i = S->size[0] * S->size[1];
  S->size[0] = 1;
  S->size[1] = O->size[1];
  emxEnsureCapacity_real_T(S, i);
  nx = O->size[1];
  for (i = 0; i < nx; i++) {
    S->data[i] = 0.0;
  }

  /*  initialization */
  if (1 > O->size[1]) {
    rtDynamicBoundsError(1, 1, O->size[1], &emlrtBCI);
  }

  c_O[0] = lambda->A->size[0];
  rtSubAssignSizeCheck(&c_O[0], 1, &pi->size[0], 1, &emlrtECI);
  nx = pi->size[0];
  for (i = 0; i < nx; i++) {
    delta->data[i] = pi->data[i];
  }

  /*  decode all time points */
  i = O->size[1];
  for (k = 0; k <= i - 2; k++) {
    for (nx = 0; nx <= N; nx++) {
      /*  avoid max with loop */
      delta_max = rtMinusInf;
      i1 = nx + 1;
      if ((i1 < 1) || (i1 > psi->size[0])) {
        rtDynamicBoundsError(i1, 1, psi->size[0], &d_emlrtBCI);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > psi->size[1])) {
        rtDynamicBoundsError(i2, 1, psi->size[1], &d_emlrtBCI);
      }

      psi->data[(i1 + psi->size[0] * (i2 - 1)) - 1] = 0.0;
      for (b_O = 0; b_O <= N; b_O++) {
        i1 = b_O + 1;
        if ((i1 < 1) || (i1 > pi->size[0])) {
          rtDynamicBoundsError(i1, 1, pi->size[0], &e_emlrtBCI);
        }

        i2 = b_O + 1;
        if ((i2 < 1) || (i2 > logA->size[0])) {
          rtDynamicBoundsError(i2, 1, logA->size[0], &f_emlrtBCI);
        }

        a = nx + 1;
        if ((a < 1) || (a > logA->size[1])) {
          rtDynamicBoundsError(a, 1, logA->size[1], &f_emlrtBCI);
        }

        delta_temp = pi->data[i1 - 1] + logA->data[(i2 + logA->size[0] * (a - 1))
          - 1];
        if (delta_temp > delta_max) {
          delta_max = delta_temp;
          i1 = nx + 1;
          if ((i1 < 1) || (i1 > psi->size[0])) {
            rtDynamicBoundsError(i1, 1, psi->size[0], &d_emlrtBCI);
          }

          i2 = k + 2;
          if ((i2 < 1) || (i2 > psi->size[1])) {
            rtDynamicBoundsError(i2, 1, psi->size[1], &d_emlrtBCI);
          }

          psi->data[(i1 + psi->size[0] * (i2 - 1)) - 1] = (double)b_O + 1.0;
        }
      }

      /*  save best state for backtracking */
      i1 = nx + 1;
      if ((i1 < 1) || (i1 > delta->size[0])) {
        rtDynamicBoundsError(i1, 1, delta->size[0], &g_emlrtBCI);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > delta->size[1])) {
        rtDynamicBoundsError(i2, 1, delta->size[1], &g_emlrtBCI);
      }

      delta->data[(i1 + delta->size[0] * (i2 - 1)) - 1] = delta_max;

      /*  update probability */
      i1 = nx + 1;
      if ((i1 < 1) || (i1 > logB->size[0])) {
        rtDynamicBoundsError(i1, 1, logB->size[0], &h_emlrtBCI);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > O->size[1])) {
        rtDynamicBoundsError(i2, 1, O->size[1], &i_emlrtBCI);
      }

      d = O->data[i2 - 1];
      if (d != (int)floor(d)) {
        rtIntegerError(d, &b_emlrtDCI);
      }

      i2 = (int)d;
      if ((i2 < 1) || (i2 > logB->size[1])) {
        rtDynamicBoundsError(i2, 1, logB->size[1], &h_emlrtBCI);
      }

      a = nx + 1;
      if ((a < 1) || (a > pi->size[0])) {
        rtDynamicBoundsError(a, 1, pi->size[0], &j_emlrtBCI);
      }

      pi->data[a - 1] = logB->data[(i1 + logB->size[0] * (i2 - 1)) - 1] +
        delta_max;
    }
  }

  emxFree_real_T(&delta);
  emxFree_real_T(&logB);
  emxFree_real_T(&logA);

  /* decide final state from max P */
  if (pi->size[0] < 1) {
    d_rtErrorWithMessageID(&d_emlrtRTEI);
  }

  nx = pi->size[0];
  if (pi->size[0] <= 2) {
    if (pi->size[0] == 1) {
      delta_temp = pi->data[0];
      b_O = 1;
    } else if ((pi->data[0] < pi->data[1]) || (rtIsNaN(pi->data[0]) && (!rtIsNaN
                 (pi->data[1])))) {
      delta_temp = pi->data[1];
      b_O = 2;
    } else {
      delta_temp = pi->data[0];
      b_O = 1;
    }
  } else {
    if (!rtIsNaN(pi->data[0])) {
      b_O = 1;
    } else {
      b_O = 0;
      if (pi->size[0] > 2147483646) {
        check_forloop_overflow_error();
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= pi->size[0])) {
        if (!rtIsNaN(pi->data[k - 1])) {
          b_O = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_O == 0) {
      delta_temp = pi->data[0];
      b_O = 1;
    } else {
      delta_temp = pi->data[b_O - 1];
      a = b_O + 1;
      if ((b_O + 1 <= pi->size[0]) && (pi->size[0] > 2147483646)) {
        check_forloop_overflow_error();
      }

      for (k = a; k <= nx; k++) {
        d = pi->data[k - 1];
        if (delta_temp < d) {
          delta_temp = d;
          b_O = k;
        }
      }
    }
  }

  emxFree_real_T(&pi);
  if (O->size[1] < 1) {
    rtDynamicBoundsError(O->size[1], 1, O->size[1], &k_emlrtBCI);
  }

  S->data[O->size[1] - 1] = b_O;

  /*  Now back trace through the model */
  i = (int)(((-1.0 - ((double)O->size[1] - 1.0)) + 1.0) / -1.0);
  for (k = 0; k < i; k++) {
    nx = O->size[1] - k;
    if ((nx < 1) || (nx > S->size[1])) {
      rtDynamicBoundsError(nx, 1, S->size[1], &m_emlrtBCI);
    }

    i1 = (int)S->data[nx - 1];
    if ((i1 < 1) || (i1 > psi->size[0])) {
      rtDynamicBoundsError(i1, 1, psi->size[0], &l_emlrtBCI);
    }

    if (nx > psi->size[1]) {
      rtDynamicBoundsError(nx, 1, psi->size[1], &l_emlrtBCI);
    }

    i2 = nx - 1;
    if ((i2 < 1) || (i2 > S->size[1])) {
      rtDynamicBoundsError(i2, 1, S->size[1], &n_emlrtBCI);
    }

    S->data[i2 - 1] = psi->data[(i1 + psi->size[0] * (nx - 1)) - 1];
    if (nx > S->size[1]) {
      rtDynamicBoundsError(nx, 1, S->size[1], &p_emlrtBCI);
    }

    i1 = (int)S->data[nx - 1];
    if ((i1 < 1) || (i1 > psi->size[0])) {
      rtDynamicBoundsError(i1, 1, psi->size[0], &o_emlrtBCI);
    }

    if (nx > psi->size[1]) {
      rtDynamicBoundsError(nx, 1, psi->size[1], &o_emlrtBCI);
    }

    if (psi->data[(i1 + psi->size[0] * (nx - 1)) - 1] == 0.0) {
      printf("Error: transition probability equals 0, needs more input data");
      fflush(stdout);
    }
  }

  emxFree_real_T(&psi);
  *logP = delta_temp;
}

/*
 * File trailer for hmmEM.c
 *
 * [EOF]
 */
