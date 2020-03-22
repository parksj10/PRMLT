/*
 * hmmEM.c
 *
 * Code generation for function 'hmmEM'
 *
 */

/* Include files */
#include "hmmEM.h"
#include "_coder_hmmEM_api.h"
#include "hmmEM_data.h"
#include "hmmEM_emxutil.h"
#include "hmmEM_mexutil.h"
#include "hmmSmoother.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 30,  /* lineNo */
  5,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRSInfo emlrtRSI = { 26,    /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 28,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 29,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 30,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 32,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 34,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 35,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 36,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 40,  /* lineNo */
  "hmmEM",                             /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 38,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 26,  /* lineNo */
  "hmmReestimate",                     /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 60,    /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pName */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  33,                                  /* colNo */
  "c",                                 /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  21,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 14,/* lineNo */
  9,                                   /* colNo */
  "log",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pName */
};

static emlrtDCInfo g_emlrtDCI = { 18,  /* lineNo */
  15,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 18,  /* lineNo */
  15,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 18,  /* lineNo */
  1,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  13,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  23,                                  /* lineNo */
  5,                                   /* colNo */
  "pi",                                /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  31,                                  /* lineNo */
  25,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  25,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  29,                                  /* colNo */
  "xi",                                /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  9,                                   /* colNo */
  "A",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "O",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  55,                                  /* lineNo */
  9,                                   /* colNo */
  "B",                                 /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  33,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  15,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  5,                                   /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  22,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  31,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  48,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  57,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  18,                                  /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  9,                                   /* colNo */
  "llh",                               /* aName */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 18,/* lineNo */
  1,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 15,/* lineNo */
  1,                                   /* colNo */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "hmmReestimate",                     /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmReestimate.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 34,/* lineNo */
  6,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 34,/* lineNo */
  16,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 34,/* lineNo */
  26,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 28,/* lineNo */
  6,                                   /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 28,/* lineNo */
  13,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 1, /* lineNo */
  26,                                  /* colNo */
  "hmmEM",                             /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmEM.m"/* pName */
};

static emlrtRSInfo r_emlrtRSI = { 60,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

/* Function Declarations */
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location);

/* Function Definitions */
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, const mxArray *f, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[5];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  pArrays[4] = f;
  return emlrtCallMATLABR2012b(sp, 1, &m, 5, pArrays, "feval", true, location);
}

void hmmEM(const emlrtStack *sp, const emxArray_real_T *O, struct0_T *lambda,
           real_T maxIter, real_T tol, emxArray_real_T *llh)
{
  int32_T Q;
  int32_T i;
  real_T denom;
  int32_T loop_ub;
  emxArray_real_T *b_gamma;
  emxArray_real_T *xi;
  emxArray_real_T *c;
  emxArray_real_T *r;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  int32_T exitg1;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 7 };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *m1;
  const mxArray *c_y;
  const mxArray *m2;
  static const int32_T iv1[2] = { 1, 46 };

  static const char_T b_u[46] = { 'S', 'm', 'o', 'o', 't', 'h', 'e', 'r', ' ',
    't', 'o', 'o', 'k', ' ', '%', '.', '2', 'f', ' ', 's', 'e', 'c', 'o', 'n',
    'd', 's', ' ', 'o', 'n', ' ', 'i', 'n', 't', 'e', 'r', 'a', 't', 'i', 'o',
    'n', ' ', '%', 'd', ' ', '\\', 'n' };

  const mxArray *d_y;
  const mxArray *m3;
  const mxArray *e_y;
  const mxArray *m4;
  const mxArray *m5;
  int32_T T;
  int32_T i1;
  int32_T t;
  int32_T j;
  int32_T i2;
  real_T numer;
  int32_T i3;
  int32_T i4;
  const mxArray *m6;
  static const int32_T iv2[2] = { 1, 7 };

  const mxArray *m7;
  const mxArray *m8;
  static const int32_T iv3[2] = { 1, 48 };

  static const char_T c_u[48] = { 'B', 'a', 'u', 'm', ' ', 'W', 'e', 'l', 'c',
    'h', ' ', 't', 'o', 'o', 'k', ' ', '%', '.', '2', 'f', ' ', 's', 'e', 'c',
    'o', 'n', 'd', 's', ' ', 'o', 'n', ' ', 'i', 'n', 't', 'e', 'r', 'a', 't',
    'i', 'o', 'n', ' ', '%', 'd', ' ', '\\', 'n' };

  const mxArray *m9;
  const mxArray *m10;
  const mxArray *m11;
  boolean_T guard1 = false;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  /*  Prohibit inlining to reduce code size. */
  Q = 0;
  i = llh->size[0] * llh->size[1];
  llh->size[0] = 1;
  emxEnsureCapacity_real_T(sp, llh, i, &m_emlrtRTEI);
  if (!(maxIter >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxIter, &h_emlrtDCI, sp);
  }

  denom = (int32_T)muDoubleScalarFloor(maxIter);
  if (maxIter != denom) {
    emlrtIntegerCheckR2012b(maxIter, &g_emlrtDCI, sp);
  }

  i = llh->size[0] * llh->size[1];
  loop_ub = (int32_T)maxIter;
  llh->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, llh, i, &m_emlrtRTEI);
  if (maxIter != denom) {
    emlrtIntegerCheckR2012b(maxIter, &i_emlrtDCI, sp);
  }

  for (i = 0; i < loop_ub; i++) {
    llh->data[i] = 0.0;
  }

  /*  do until condition is met */
  emxInit_real_T(sp, &b_gamma, 2, &t_emlrtRTEI, true);
  emxInit_real_T(sp, &xi, 3, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &c, 2, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &r, 2, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &r2, 1, &v_emlrtRTEI, true);
  do {
    exitg1 = 0;

    /*  iteration counter */
    if (Q > 2147483646) {
      Q = MAX_int32_T;
    } else {
      Q++;
    }

    st.site = &emlrtRSI;
    tic(&st);

    /*  determine parameters, Expectation step (E) */
    st.site = &b_emlrtRSI;
    hmmSmoother(&st, O, lambda->A, lambda->B, lambda->pi, b_gamma, xi, c);
    st.site = &c_emlrtRSI;
    denom = toc(&st);
    st.site = &d_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    y = NULL;
    m = emlrtCreateCharArray(2, iv);
    emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
    emlrtAssign(&y, m);
    b_y = NULL;
    m1 = emlrtCreateDoubleScalar(1.0);
    emlrtAssign(&b_y, m1);
    c_y = NULL;
    m2 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(&b_st, 46, m2, &b_u[0]);
    emlrtAssign(&c_y, m2);
    d_y = NULL;
    m3 = emlrtCreateDoubleScalar(denom);
    emlrtAssign(&d_y, m3);
    e_y = NULL;
    m4 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)emlrtMxGetData(m4) = Q;
    emlrtAssign(&e_y, m4);
    c_st.site = &r_emlrtRSI;
    denom = emlrt_marshallIn(&c_st, feval(&c_st, y, b_y, c_y, d_y, e_y,
      &emlrtMCI), "<output of feval>");
    y = NULL;
    m5 = emlrtCreateDoubleScalar(denom);
    emlrtAssign(&y, m5);
    emlrtDisplayR2012b(y, "ans", &emlrtRTEI, sp);
    st.site = &e_emlrtRSI;
    tic(&st);

    /*  re-estimate parameters, Maximization step (M) */
    st.site = &f_emlrtRSI;

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
    i = r->size[0] * r->size[1];
    r->size[0] = lambda->A->size[0];
    r->size[1] = lambda->A->size[1];
    emxEnsureCapacity_real_T(&st, r, i, &n_emlrtRTEI);
    loop_ub = lambda->A->size[0] * lambda->A->size[1];
    for (i = 0; i < loop_ub; i++) {
      r->data[i] = lambda->A->data[i];
    }

    i = r1->size[0] * r1->size[1];
    r1->size[0] = lambda->B->size[0];
    r1->size[1] = lambda->B->size[1];
    emxEnsureCapacity_real_T(&st, r1, i, &o_emlrtRTEI);
    loop_ub = lambda->B->size[0] * lambda->B->size[1];
    for (i = 0; i < loop_ub; i++) {
      r1->data[i] = lambda->B->data[i];
    }

    i = r2->size[0];
    r2->size[0] = lambda->pi->size[0];
    emxEnsureCapacity_real_T(&st, r2, i, &p_emlrtRTEI);
    loop_ub = lambda->pi->size[0];
    for (i = 0; i < loop_ub; i++) {
      r2->data[i] = lambda->pi->data[i];
    }

    T = O->size[1] - 2;

    /*  re-estimate pi */
    i = lambda->B->size[0];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      if (1 > b_gamma->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_gamma->size[1], &ic_emlrtBCI, &st);
      }

      i1 = (int32_T)(loop_ub + 1U);
      if ((i1 < 1) || (i1 > b_gamma->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_gamma->size[0], &jc_emlrtBCI, &st);
      }

      if (i1 > r2->size[0]) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, r2->size[0], &kc_emlrtBCI, &st);
      }

      r2->data[i1 - 1] = b_gamma->data[i1 - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    b_st.site = &q_emlrtRSI;
    tic(&b_st);

    /*  re-estimate A */
    i = lambda->B->size[0];
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      denom = 0.0;
      for (t = 0; t <= T; t++) {
        i1 = (int32_T)(loop_ub + 1U);
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_gamma->size[0], &lc_emlrtBCI,
            &st);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[1], &lc_emlrtBCI,
            &st);
        }

        denom += b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* t */
      i1 = lambda->B->size[0];
      for (j = 0; j < i1; j++) {
        numer = 0.0;
        for (t = 0; t <= T; t++) {
          i2 = (int32_T)(loop_ub + 1U);
          if ((i2 < 1) || (i2 > xi->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, xi->size[0], &nc_emlrtBCI, &st);
          }

          i3 = (int32_T)(j + 1U);
          if ((i3 < 1) || (i3 > xi->size[1])) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, xi->size[1], &nc_emlrtBCI, &st);
          }

          i4 = t + 1;
          if ((i4 < 1) || (i4 > xi->size[2])) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, xi->size[2], &nc_emlrtBCI, &st);
          }

          numer += xi->data[((i2 + xi->size[0] * (i3 - 1)) + xi->size[0] *
                             xi->size[1] * (i4 - 1)) - 1];
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        /* t */
        i2 = (int32_T)(loop_ub + 1U);
        if ((i2 < 1) || (i2 > r->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, r->size[0], &oc_emlrtBCI, &st);
        }

        i3 = (int32_T)(j + 1U);
        if ((i3 < 1) || (i3 > r->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, r->size[1], &oc_emlrtBCI, &st);
        }

        r->data[(i2 + r->size[0] * (i3 - 1)) - 1] = numer / denom;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* j */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* i */
    /*  re-estimate B */
    i = lambda->B->size[0];
    for (j = 0; j < i; j++) {
      denom = 0.0;
      for (t = 0; t <= T + 1; t++) {
        i1 = (int32_T)(j + 1U);
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_gamma->size[0], &mc_emlrtBCI,
            &st);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[1], &mc_emlrtBCI,
            &st);
        }

        denom += b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* t */
      i1 = lambda->B->size[1];
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        numer = 0.0;
        for (t = 0; t <= T + 1; t++) {
          i2 = t + 1;
          if ((i2 < 1) || (i2 > O->size[1])) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, O->size[1], &pc_emlrtBCI, &st);
          }

          if (O->data[i2 - 1] == (real_T)loop_ub + 1.0) {
            i2 = (int32_T)(j + 1U);
            if ((i2 < 1) || (i2 > b_gamma->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[0],
                &rc_emlrtBCI, &st);
            }

            i3 = t + 1;
            if ((i3 < 1) || (i3 > b_gamma->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i3, 1, b_gamma->size[1],
                &rc_emlrtBCI, &st);
            }

            numer += b_gamma->data[(i2 + b_gamma->size[0] * (i3 - 1)) - 1];
          }

          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        /* t */
        i2 = (int32_T)(j + 1U);
        if ((i2 < 1) || (i2 > r1->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, r1->size[0], &qc_emlrtBCI, &st);
        }

        i3 = (int32_T)(loop_ub + 1U);
        if ((i3 < 1) || (i3 > r1->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, r1->size[1], &qc_emlrtBCI, &st);
        }

        r1->data[(i2 + r1->size[0] * (i3 - 1)) - 1] = numer / denom;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      /* k */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    /* i */
    i = lambda->A->size[0] * lambda->A->size[1];
    lambda->A->size[0] = r->size[0];
    lambda->A->size[1] = r->size[1];
    emxEnsureCapacity_real_T(sp, lambda->A, i, &q_emlrtRTEI);
    loop_ub = r->size[0] * r->size[1];
    for (i = 0; i < loop_ub; i++) {
      lambda->A->data[i] = r->data[i];
    }

    i = lambda->B->size[0] * lambda->B->size[1];
    lambda->B->size[0] = r1->size[0];
    lambda->B->size[1] = r1->size[1];
    emxEnsureCapacity_real_T(sp, lambda->B, i, &r_emlrtRTEI);
    loop_ub = r1->size[0] * r1->size[1];
    for (i = 0; i < loop_ub; i++) {
      lambda->B->data[i] = r1->data[i];
    }

    i = lambda->pi->size[0];
    lambda->pi->size[0] = r2->size[0];
    emxEnsureCapacity_real_T(sp, lambda->pi, i, &s_emlrtRTEI);
    loop_ub = r2->size[0];
    for (i = 0; i < loop_ub; i++) {
      lambda->pi->data[i] = r2->data[i];
    }

    st.site = &g_emlrtRSI;
    denom = toc(&st);
    st.site = &h_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    y = NULL;
    m6 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(&b_st, 7, m6, &u[0]);
    emlrtAssign(&y, m6);
    b_y = NULL;
    m7 = emlrtCreateDoubleScalar(1.0);
    emlrtAssign(&b_y, m7);
    c_y = NULL;
    m8 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(&b_st, 48, m8, &c_u[0]);
    emlrtAssign(&c_y, m8);
    d_y = NULL;
    m9 = emlrtCreateDoubleScalar(denom);
    emlrtAssign(&d_y, m9);
    e_y = NULL;
    m10 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)emlrtMxGetData(m10) = Q;
    emlrtAssign(&e_y, m10);
    c_st.site = &r_emlrtRSI;
    denom = emlrt_marshallIn(&c_st, feval(&c_st, y, b_y, c_y, d_y, e_y,
      &emlrtMCI), "<output of feval>");
    y = NULL;
    m11 = emlrtCreateDoubleScalar(denom);
    emlrtAssign(&y, m11);
    emlrtDisplayR2012b(y, "ans", &b_emlrtRTEI, sp);

    /*  compute log(P(O|lambda)) */
    i = O->size[1];
    for (t = 0; t < i; t++) {
      st.site = &i_emlrtRSI;
      i1 = t + 1;
      if ((i1 < 1) || (i1 > c->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, c->size[1], &hc_emlrtBCI, &st);
      }

      if (c->data[t] < 0.0) {
        emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
          "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3,
          4, 3, "log");
      }

      if (Q > llh->size[1]) {
        emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &yc_emlrtBCI, sp);
      }

      if (Q > llh->size[1]) {
        emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &ad_emlrtBCI, sp);
      }

      llh->data[Q - 1] += muDoubleScalarLog(c->data[t]);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* t */
    if (Q > llh->size[1]) {
      emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &sc_emlrtBCI, sp);
    }

    if (Q > llh->size[1]) {
      emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &tc_emlrtBCI, sp);
    }

    llh->data[Q - 1] = -llh->data[Q - 1];

    /*  break when tolerance or maxIter is reached */
    if (Q >= maxIter) {
      exitg1 = 1;
    } else {
      guard1 = false;
      if (Q != 1) {
        if (Q > llh->size[1]) {
          emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &uc_emlrtBCI, sp);
        }

        i = Q - 1;
        if (i > llh->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i, 1, llh->size[1], &vc_emlrtBCI, sp);
        }

        if (llh->data[Q - 1] < llh->data[i - 1]) {
          exitg1 = 1;
        } else {
          if (Q > llh->size[1]) {
            emlrtDynamicBoundsCheckR2012b(Q, 1, llh->size[1], &wc_emlrtBCI, sp);
          }

          i = Q - 1;
          if (i > llh->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i, 1, llh->size[1], &xc_emlrtBCI, sp);
          }

          if (muDoubleScalarAbs(-llh->data[Q - 1] + llh->data[Q - 2]) <= tol) {
            exitg1 = 1;
          } else {
            guard1 = true;
          }
        }
      } else {
        guard1 = true;
      }

      if (guard1 && (*emlrtBreakCheckR2012bFlagVar != 0)) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  } while (exitg1 == 0);

  emxFree_real_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&r);
  emxFree_real_T(&c);
  emxFree_real_T(&xi);
  emxFree_real_T(&b_gamma);

  /* while */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (hmmEM.c) */
