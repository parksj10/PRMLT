/*
 * File: _coder_hmmEM_api.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 17-Mar-2020 11:47:11
 */

/* Include Files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_hmmEM_api.h"
#include "_coder_hmmEM_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "hmmEM",                             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lambda,
  const char_T *identifier, struct0_T *y);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *e_emlrt_marshallOut(const real_T u);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *O, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct0_T u);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *maxIter,
  const char_T *identifier);
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  real_T *pData;
  int32_T i1;
  int32_T i;
  int32_T b_i;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[2])u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m1);
  i1 = 0;
  for (i = 0; i < u->size[1]; i++) {
    for (b_i = 0; b_i < u->size[0]; b_i++) {
      pData[i1] = u->data[b_i + u->size[0] * i];
      i1++;
    }
  }

  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *lambda
 *                const char_T *identifier
 *                struct0_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lambda,
  const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(lambda), &thisId, y);
  emlrtDestroyArray(&lambda);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m2, &u->data[0]);
  emlrtSetDimensions((mxArray *)m2, u->size, 2);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct0_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "A", "B", "pi" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, &dims);
  thisId.fIdentifier = "A";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "A")),
                     &thisId, y->A);
  thisId.fIdentifier = "B";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "B")),
                     &thisId, y->B);
  thisId.fIdentifier = "pi";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "pi")),
                     &thisId, y->pi);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv2[3] = { 0, 0, 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(3, iv2, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, &u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 3);
  emlrtAssign(&y, m4);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *e_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m5);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *O
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *O, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(O), &thisId, y);
  emlrtDestroyArray(&O);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const struct0_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct0_T u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  static const char * sv0[3] = { "A", "B", "pi" };

  int32_T i0;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  real_T *pData;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 1, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv0));
  emlrtSetFieldR2017b(y, 0, "A", b_emlrt_marshallOut(u.A), 0);
  emlrtSetFieldR2017b(y, 0, "B", b_emlrt_marshallOut(u.B), 1);
  i0 = b_u->size[0];
  b_u->size[0] = u.pi->size[0];
  emxEnsureCapacity_real_T(b_u, i0);
  loop_ub = u.pi->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_u->data[i0] = u.pi->data[i0];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(1, *(int32_T (*)[2])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i0 = 0;
  loop_ub = 0;
  emxFree_real_T(&b_u);
  while (loop_ub < u.pi->size[0]) {
    pData[i0] = u.pi->data[loop_ub];
    i0++;
    loop_ub++;
  }

  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "pi", b_y, 2);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : struct0_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_real_T(&pStruct->A);
  emxFree_real_T(&pStruct->B);
  emxFree_real_T(&pStruct->pi);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct0_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->A, 2, doPush);
  emxInit_real_T(sp, &pStruct->B, 2, doPush);
  emxInit_real_T(sp, &pStruct->pi, 1, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *maxIter
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *maxIter,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(maxIter), &thisId);
  emlrtDestroyArray(&maxIter);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv3[2];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv3);
  ret->allocatedSize = iv3[0] * iv3[1];
  i2 = ret->size[0] * ret->size[1];
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  emxEnsureCapacity_real_T(ret, i2);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv1[2] = { true, true };

  int32_T iv4[2];
  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv4);
  i3 = ret->size[0] * ret->size[1];
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  emxEnsureCapacity_real_T(ret, i3);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv2[1] = { true };

  int32_T iv5[1];
  int32_T i4;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv2[0],
    iv5);
  i4 = ret->size[0];
  ret->size[0] = iv5[0];
  emxEnsureCapacity_real_T(ret, i4);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[4]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
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
  emxInit_real_T(&st, &O, 2, true);
  emxInitStruct_struct0_T(&st, &lambda, true);
  emxInit_real_T(&st, &llh, 2, true);

  /* Marshall function inputs */
  O->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "O", O);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "lambda", &lambda);
  maxIter = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "maxIter");
  tol = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "tol");

  /* Invoke the target function */
  hmmEM(O, &lambda, maxIter, tol, llh);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, lambda);
  emxFreeStruct_struct0_T(&lambda);
  emxFree_real_T(&O);
  if (nlhs > 1) {
    llh->canFreeData = false;
    plhs[1] = c_emlrt_marshallOut(llh);
  }

  emxFree_real_T(&llh);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  hmmEM_xil_terminate();
  hmmEM_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void hmmEM_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[5]
 * Return Type  : void
 */
void hmmSmoother__api(const mxArray * const prhs[2], int32_T nlhs, const mxArray
                      *plhs[5])
{
  emxArray_real_T *O;
  struct0_T lambda;
  emxArray_real_T *b_gamma;
  emxArray_real_T *epsilon;
  emxArray_real_T *alpha;
  emxArray_real_T *beta;
  emxArray_real_T *c;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &O, 2, true);
  emxInitStruct_struct0_T(&st, &lambda, true);
  emxInit_real_T(&st, &b_gamma, 2, true);
  emxInit_real_T(&st, &epsilon, 3, true);
  emxInit_real_T(&st, &alpha, 2, true);
  emxInit_real_T(&st, &beta, 2, true);
  emxInit_real_T(&st, &c, 2, true);

  /* Marshall function inputs */
  O->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "O", O);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "lambda", &lambda);

  /* Invoke the target function */
  hmmSmoother_(O, &lambda, b_gamma, epsilon, alpha, beta, c);

  /* Marshall function outputs */
  b_gamma->canFreeData = false;
  plhs[0] = c_emlrt_marshallOut(b_gamma);
  emxFree_real_T(&b_gamma);
  emxFreeStruct_struct0_T(&lambda);
  emxFree_real_T(&O);
  if (nlhs > 1) {
    epsilon->canFreeData = false;
    plhs[1] = d_emlrt_marshallOut(epsilon);
  }

  emxFree_real_T(&epsilon);
  if (nlhs > 2) {
    alpha->canFreeData = false;
    plhs[2] = c_emlrt_marshallOut(alpha);
  }

  emxFree_real_T(&alpha);
  if (nlhs > 3) {
    beta->canFreeData = false;
    plhs[3] = c_emlrt_marshallOut(beta);
  }

  emxFree_real_T(&beta);
  if (nlhs > 4) {
    c->canFreeData = false;
    plhs[4] = c_emlrt_marshallOut(c);
  }

  emxFree_real_T(&c);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void hmmViterbi__api(const mxArray * const prhs[2], int32_T nlhs, const mxArray *
                     plhs[2])
{
  emxArray_real_T *O;
  struct0_T lambda;
  emxArray_real_T *S;
  real_T logP;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &O, 2, true);
  emxInitStruct_struct0_T(&st, &lambda, true);
  emxInit_real_T(&st, &S, 2, true);

  /* Marshall function inputs */
  O->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "O", O);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "lambda", &lambda);

  /* Invoke the target function */
  hmmViterbi_(O, &lambda, S, &logP);

  /* Marshall function outputs */
  S->canFreeData = false;
  plhs[0] = c_emlrt_marshallOut(S);
  emxFree_real_T(&S);
  emxFreeStruct_struct0_T(&lambda);
  emxFree_real_T(&O);
  if (nlhs > 1) {
    plhs[1] = e_emlrt_marshallOut(logP);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * File trailer for _coder_hmmEM_api.c
 *
 * [EOF]
 */
