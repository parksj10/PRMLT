/*
 * hmmViterbi.c
 *
 * Code generation for function 'hmmViterbi'
 *
 */

/* Include files */
#include "hmmViterbi.h"
#include "eml_int_forloop_overflow_check.h"
#include "hmmViterbi_data.h"
#include "hmmViterbi_emxutil.h"
#include "hmmViterbi_mexutil.h"
#include "log.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 62,  /* lineNo */
  9,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRSInfo emlrtRSI = { 23,    /* lineNo */
  "hmmViterbi",                        /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 24,  /* lineNo */
  "hmmViterbi",                        /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 25,  /* lineNo */
  "hmmViterbi",                        /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 56,  /* lineNo */
  "hmmViterbi",                        /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 62,  /* lineNo */
  "hmmViterbi",                        /* fcnName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 16,  /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 17,  /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 43,  /* lineNo */
  "unaryOrBinaryDispatch",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 131, /* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 932, /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 924, /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 975, /* lineNo */
  "findFirst",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 992, /* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 35,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 60,    /* lineNo */
  18,                                  /* colNo */
  "fprintf",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 95,/* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  32,                                  /* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "delta",                             /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  25,                                  /* lineNo */
  5,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  23,                                  /* colNo */
  "logB",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 25,    /* lineNo */
  23,                                  /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  25,                                  /* colNo */
  "O",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  49,                                  /* lineNo */
  9,                                   /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  26,                                  /* colNo */
  "P",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  33,                                  /* colNo */
  "logA",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  9,                                   /* colNo */
  "delta",                             /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "logB",                              /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 51,  /* lineNo */
  16,                                  /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  16,                                  /* colNo */
  "O",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  51,                                  /* lineNo */
  9,                                   /* colNo */
  "P",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  1,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  12,                                  /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  12,                                  /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  5,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  8,                                   /* colNo */
  "psi",                               /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  8,                                   /* colNo */
  "S",                                 /* aName */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 23,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 24,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 26,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 27,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "hmmViterbi",                        /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmViterbi.m"/* pName */
};

static emlrtRSInfo r_emlrtRSI = { 60,  /* lineNo */
  "fprintf",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2019b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"/* pathName */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *a__output_of_feval_, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(a__output_of_feval_), &thisId);
  emlrtDestroyArray(&a__output_of_feval_);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m, 3, pArrays, "feval", true, location);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void hmmViterbi(const emlrtStack *sp, const emxArray_real_T *O, const struct0_T *
                lambda, emxArray_real_T *S, real_T *logP)
{
  emxArray_real_T *pi;
  int32_T i;
  int32_T nx;
  emxArray_real_T *logA;
  int32_T N;
  emxArray_real_T *logB;
  boolean_T p;
  int32_T k;
  int32_T b_O;
  emxArray_real_T *psi;
  emxArray_real_T *delta;
  int32_T c_O[1];
  real_T delta_max;
  int32_T i1;
  int32_T i2;
  int32_T a;
  real_T delta_temp;
  boolean_T exitg1;
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 1, 7 };

  static const char_T u[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  const mxArray *b_y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 1, 61 };

  static const char_T b_u[61] = { 'E', 'r', 'r', 'o', 'r', ':', ' ', 't', 'r',
    'a', 'n', 's', 'i', 't', 'i', 'o', 'n', ' ', 'p', 'r', 'o', 'b', 'a', 'b',
    'i', 'l', 'i', 't', 'y', ' ', 'e', 'q', 'u', 'a', 'l', 's', ' ', '0', ',',
    ' ', 'n', 'e', 'e', 'd', 's', ' ', 'm', 'o', 'r', 'e', ' ', 'i', 'n', 'p',
    'u', 't', ' ', 'd', 'a', 't', 'a' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &pi, 1, &g_emlrtRTEI, true);

  /*  Implmentation function of Viterbi algorithm.  */
  /*  Input: */
  /*    O: 1 x T observation sequence */
  /*    A: k x k transition matrix */
  /*    B: N x M emmision data matrix */
  /*    s: k x 1 starting probability (prior) */
  /*  Output: */
  /*    z: 1 x n latent state */
  /*    p: 1 x n probability */
  /*  Written by Josh Parks */
  /*  Prohibit inlining to reduce code size. */
  /*  Use parameters */
  i = pi->size[0];
  pi->size[0] = lambda->pi->size[0];
  emxEnsureCapacity_real_T(sp, pi, i, &g_emlrtRTEI);
  nx = lambda->pi->size[0];
  for (i = 0; i < nx; i++) {
    pi->data[i] = lambda->pi->data[i];
  }

  emxInit_real_T(sp, &logA, 2, &h_emlrtRTEI, true);
  N = lambda->A->size[0] - 1;
  i = logA->size[0] * logA->size[1];
  logA->size[0] = lambda->A->size[0];
  logA->size[1] = lambda->A->size[1];
  emxEnsureCapacity_real_T(sp, logA, i, &h_emlrtRTEI);
  nx = lambda->A->size[0] * lambda->A->size[1];
  for (i = 0; i < nx; i++) {
    logA->data[i] = lambda->A->data[i];
  }

  emxInit_real_T(sp, &logB, 2, &i_emlrtRTEI, true);
  st.site = &emlrtRSI;
  b_log(&st, logA);
  i = logB->size[0] * logB->size[1];
  logB->size[0] = lambda->B->size[0];
  logB->size[1] = lambda->B->size[1];
  emxEnsureCapacity_real_T(sp, logB, i, &i_emlrtRTEI);
  nx = lambda->B->size[0] * lambda->B->size[1];
  for (i = 0; i < nx; i++) {
    logB->data[i] = lambda->B->data[i];
  }

  st.site = &b_emlrtRSI;
  b_log(&st, logB);
  st.site = &c_emlrtRSI;
  p = false;
  i = lambda->pi->size[0];
  for (k = 0; k < i; k++) {
    if (p || (lambda->pi->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      3, "log");
  }

  b_st.site = &f_emlrtRSI;
  nx = lambda->pi->size[0];
  c_st.site = &g_emlrtRSI;
  if ((1 <= lambda->pi->size[0]) && (lambda->pi->size[0] > 2147483646)) {
    d_st.site = &h_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < nx; k++) {
    pi->data[k] = muDoubleScalarLog(pi->data[k]);
  }

  if (1 > O->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, O->size[1], &c_emlrtBCI, sp);
  }

  if (O->data[0] != (int32_T)muDoubleScalarFloor(O->data[0])) {
    emlrtIntegerCheckR2012b(O->data[0], &emlrtDCI, sp);
  }

  b_O = (int32_T)O->data[0];
  if ((b_O < 1) || (b_O > logB->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_O, 1, logB->size[1], &b_emlrtBCI, sp);
  }

  if (pi->size[0] != logB->size[0]) {
    emlrtSizeEqCheck1DR2012b(pi->size[0], logB->size[0], &b_emlrtECI, sp);
  }

  nx = pi->size[0];
  for (i = 0; i < nx; i++) {
    pi->data[i] += logB->data[i + logB->size[0] * (b_O - 1)];
  }

  emxInit_real_T(sp, &psi, 2, &j_emlrtRTEI, true);
  i = psi->size[0] * psi->size[1];
  psi->size[0] = lambda->A->size[0];
  psi->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, psi, i, &j_emlrtRTEI);
  nx = lambda->A->size[0] * O->size[1];
  for (i = 0; i < nx; i++) {
    psi->data[i] = 0.0;
  }

  emxInit_real_T(sp, &delta, 2, &k_emlrtRTEI, true);
  i = delta->size[0] * delta->size[1];
  delta->size[0] = lambda->A->size[0];
  delta->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, delta, i, &k_emlrtRTEI);
  nx = lambda->A->size[0] * O->size[1];
  for (i = 0; i < nx; i++) {
    delta->data[i] = 0.0;
  }

  /*  actually this is log(delta) --> phi, but leave as  */
  /*    delta for clarity (phi != psi) */
  i = S->size[0] * S->size[1];
  S->size[0] = 1;
  S->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, S, i, &l_emlrtRTEI);
  nx = O->size[1];
  for (i = 0; i < nx; i++) {
    S->data[i] = 0.0;
  }

  /*  initialization */
  if (1 > O->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, O->size[1], &emlrtBCI, sp);
  }

  c_O[0] = lambda->A->size[0];
  emlrtSubAssignSizeCheckR2012b(&c_O[0], 1, &pi->size[0], 1, &emlrtECI, sp);
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
        emlrtDynamicBoundsCheckR2012b(i1, 1, psi->size[0], &d_emlrtBCI, sp);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > psi->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, psi->size[1], &d_emlrtBCI, sp);
      }

      psi->data[(i1 + psi->size[0] * (i2 - 1)) - 1] = 0.0;
      for (b_O = 0; b_O <= N; b_O++) {
        i1 = b_O + 1;
        if ((i1 < 1) || (i1 > pi->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, pi->size[0], &e_emlrtBCI, sp);
        }

        i2 = b_O + 1;
        if ((i2 < 1) || (i2 > logA->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, logA->size[0], &f_emlrtBCI, sp);
        }

        a = nx + 1;
        if ((a < 1) || (a > logA->size[1])) {
          emlrtDynamicBoundsCheckR2012b(a, 1, logA->size[1], &f_emlrtBCI, sp);
        }

        delta_temp = pi->data[i1 - 1] + logA->data[(i2 + logA->size[0] * (a - 1))
          - 1];
        if (delta_temp > delta_max) {
          delta_max = delta_temp;
          i1 = nx + 1;
          if ((i1 < 1) || (i1 > psi->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, psi->size[0], &d_emlrtBCI, sp);
          }

          i2 = k + 2;
          if ((i2 < 1) || (i2 > psi->size[1])) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, psi->size[1], &d_emlrtBCI, sp);
          }

          psi->data[(i1 + psi->size[0] * (i2 - 1)) - 1] = (real_T)b_O + 1.0;
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /*  save best state for backtracking */
      i1 = nx + 1;
      if ((i1 < 1) || (i1 > delta->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, delta->size[0], &g_emlrtBCI, sp);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > delta->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, delta->size[1], &g_emlrtBCI, sp);
      }

      delta->data[(i1 + delta->size[0] * (i2 - 1)) - 1] = delta_max;

      /*  update probability */
      i1 = nx + 1;
      if ((i1 < 1) || (i1 > logB->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, logB->size[0], &h_emlrtBCI, sp);
      }

      i2 = k + 2;
      if ((i2 < 1) || (i2 > O->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, O->size[1], &i_emlrtBCI, sp);
      }

      delta_temp = O->data[i2 - 1];
      if (delta_temp != (int32_T)muDoubleScalarFloor(delta_temp)) {
        emlrtIntegerCheckR2012b(delta_temp, &b_emlrtDCI, sp);
      }

      i2 = (int32_T)delta_temp;
      if ((i2 < 1) || (i2 > logB->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, logB->size[1], &h_emlrtBCI, sp);
      }

      a = nx + 1;
      if ((a < 1) || (a > pi->size[0])) {
        emlrtDynamicBoundsCheckR2012b(a, 1, pi->size[0], &j_emlrtBCI, sp);
      }

      pi->data[a - 1] = logB->data[(i1 + logB->size[0] * (i2 - 1)) - 1] +
        delta_max;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&delta);
  emxFree_real_T(&logB);
  emxFree_real_T(&logA);

  /* decide final state from max P */
  st.site = &d_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  if (pi->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &l_emlrtRSI;
  nx = pi->size[0];
  if (pi->size[0] <= 2) {
    if (pi->size[0] == 1) {
      delta_max = pi->data[0];
      b_O = 1;
    } else if ((pi->data[0] < pi->data[1]) || (muDoubleScalarIsNaN(pi->data[0]) &&
                (!muDoubleScalarIsNaN(pi->data[1])))) {
      delta_max = pi->data[1];
      b_O = 2;
    } else {
      delta_max = pi->data[0];
      b_O = 1;
    }
  } else {
    f_st.site = &n_emlrtRSI;
    if (!muDoubleScalarIsNaN(pi->data[0])) {
      b_O = 1;
    } else {
      b_O = 0;
      g_st.site = &o_emlrtRSI;
      if (pi->size[0] > 2147483646) {
        h_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= pi->size[0])) {
        if (!muDoubleScalarIsNaN(pi->data[k - 1])) {
          b_O = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_O == 0) {
      delta_max = pi->data[0];
      b_O = 1;
    } else {
      f_st.site = &m_emlrtRSI;
      delta_max = pi->data[b_O - 1];
      a = b_O + 1;
      g_st.site = &p_emlrtRSI;
      if ((b_O + 1 <= pi->size[0]) && (pi->size[0] > 2147483646)) {
        h_st.site = &h_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }

      for (k = a; k <= nx; k++) {
        delta_temp = pi->data[k - 1];
        if (delta_max < delta_temp) {
          delta_max = delta_temp;
          b_O = k;
        }
      }
    }
  }

  emxFree_real_T(&pi);
  if (O->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(O->size[1], 1, O->size[1], &k_emlrtBCI, &b_st);
  }

  S->data[O->size[1] - 1] = b_O;

  /*  Now back trace through the model */
  i = (int32_T)(((-1.0 - ((real_T)O->size[1] - 1.0)) + 1.0) / -1.0);
  emlrtForLoopVectorCheckR2012b((real_T)O->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, i, &e_emlrtRTEI, sp);
  for (k = 0; k < i; k++) {
    nx = O->size[1] - k;
    if ((nx < 1) || (nx > S->size[1])) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, S->size[1], &m_emlrtBCI, sp);
    }

    i1 = (int32_T)S->data[nx - 1];
    if ((i1 < 1) || (i1 > psi->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, psi->size[0], &l_emlrtBCI, sp);
    }

    if (nx > psi->size[1]) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, psi->size[1], &l_emlrtBCI, sp);
    }

    i2 = nx - 1;
    if ((i2 < 1) || (i2 > S->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, S->size[1], &n_emlrtBCI, sp);
    }

    S->data[i2 - 1] = psi->data[(i1 + psi->size[0] * (nx - 1)) - 1];
    if (nx > S->size[1]) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, S->size[1], &p_emlrtBCI, sp);
    }

    i1 = (int32_T)S->data[nx - 1];
    if ((i1 < 1) || (i1 > psi->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, psi->size[0], &o_emlrtBCI, sp);
    }

    if (nx > psi->size[1]) {
      emlrtDynamicBoundsCheckR2012b(nx, 1, psi->size[1], &o_emlrtBCI, sp);
    }

    if (psi->data[(i1 + psi->size[0] * (nx - 1)) - 1] == 0.0) {
      st.site = &e_emlrtRSI;
      b_st.site = &q_emlrtRSI;
      y = NULL;
      m = emlrtCreateCharArray(2, iv);
      emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m1 = emlrtCreateCharArray(2, iv1);
      emlrtInitCharArrayR2013a(&b_st, 61, m1, &b_u[0]);
      emlrtAssign(&b_y, m1);
      c_st.site = &r_emlrtRSI;
      delta_temp = emlrt_marshallIn(&c_st, feval(&c_st, y, emlrt_marshallOut(1.0),
        b_y, &emlrtMCI), "<output of feval>");
      emlrtDisplayR2012b(emlrt_marshallOut(delta_temp), "ans", &emlrtRTEI, sp);
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&psi);
  *logP = delta_max;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (hmmViterbi.c) */
