/*
 * File: hmmEM_emxutil.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 20-Mar-2020 21:34:12
 */

#ifndef HMMEM_EMXUTIL_H
#define HMMEM_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "hmmEM_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
  extern void emxFreeStruct_struct0_T(struct0_T *pStruct);
  extern void emxFree_real_T(emxArray_real_T **pEmxArray);
  extern void emxInitStruct_struct0_T(struct0_T *pStruct);
  extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for hmmEM_emxutil.h
 *
 * [EOF]
 */
