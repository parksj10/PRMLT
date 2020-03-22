/*
 * _coder_hmmEM_api.c
 *
 * Code generation for function '_coder_hmmEM_api'
 *
 */

/* Include files */
#include "_coder_hmmEM_api.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "hmmEM_emxutil.h"
#include "hmmEM_mexutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_hmmEM_api",                  /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *O, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lambda,
  const char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const struct0_T u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  int32_T iv[2];
  const mxArray *m;
  real_T *pData;
  int32_T i;
  int32_T b_i;
  int32_T c_i;
  y = NULL;
  iv[0] = u->size[0];
  iv[1] = u->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u->size[1]; b_i++) {
    for (c_i = 0; c_i < u->size[0]; c_i++) {
      pData[i] = u->data[c_i + u->size[0] * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *O, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(O), &thisId, y);
  emlrtDestroyArray(&O);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 2);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lambda,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(lambda), &thisId, y);
  emlrtDestroyArray(&lambda);
}

static const mxArray *emlrt_marshallOut(const struct0_T u)
{
  const mxArray *y;
  static const char * sv[3] = { "A", "B", "pi" };

  const mxArray *b_y;
  int32_T iv[1];
  const mxArray *m;
  real_T *pData;
  int32_T i;
  int32_T b_i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv));
  emlrtSetFieldR2017b(y, 0, "A", b_emlrt_marshallOut(u.A), 0);
  emlrtSetFieldR2017b(y, 0, "B", b_emlrt_marshallOut(u.B), 1);
  b_y = NULL;
  iv[0] = u.pi->size[0];
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < u.pi->size[0]; b_i++) {
    pData[i] = u.pi->data[b_i];
    i++;
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "pi", b_y, 2);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "A", "B", "pi" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "A";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "A")),
                     &thisId, y->A);
  thisId.fIdentifier = "B";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "B")),
                     &thisId, y->B);
  thisId.fIdentifier = "pi";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "pi")),
                     &thisId, y->pi);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv[2] = { false, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv[2] = { true, true };

  int32_T iv[2];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv[1] = { true };

  int32_T iv[1];
  int32_T i;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv[0],
    iv);
  i = ret->size[0];
  ret->size[0] = iv[0];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void hmmEM_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray *plhs
               [2])
{
  emxArray_real_T *O;
  struct0_T lambda;
  emxArray_real_T *llh;
  real_T maxIter;
  real_T tol;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &O, 2, &l_emlrtRTEI, true);
  emxInitStruct_struct0_T(&st, &lambda, &l_emlrtRTEI, true);
  emxInit_real_T(&st, &llh, 2, &l_emlrtRTEI, true);

  /* Marshall function inputs */
  O->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "O", O);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "lambda", &lambda);
  maxIter = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "maxIter");
  tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tol");

  /* Invoke the target function */
  hmmEM(&st, O, &lambda, maxIter, tol, llh);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(lambda);
  emxFreeStruct_struct0_T(&lambda);
  emxFree_real_T(&O);
  if (nlhs > 1) {
    llh->canFreeData = false;
    plhs[1] = c_emlrt_marshallOut(llh);
  }

  emxFree_real_T(&llh);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_hmmEM_api.c) */
