/*
 * hmmSmoother.c
 *
 * Code generation for function 'hmmSmoother'
 *
 */

/* Include files */
#include "hmmSmoother.h"
#include "hmmEM.h"
#include "hmmEM_data.h"
#include "hmmEM_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  26,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  30,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  7,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  3,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  20,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  31,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 65,/* lineNo */
  9,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 77,    /* lineNo */
  16,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  18,                                  /* colNo */
  "pi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  24,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 29,  /* lineNo */
  24,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  5,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  30,                                  /* lineNo */
  19,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  5,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  23,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  14,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  5,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  26,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  39,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  52,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  13,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  22,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 46,  /* lineNo */
  33,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  33,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  46,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  17,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  5,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  22,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  27,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  52,                                  /* lineNo */
  9,                                   /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  16,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  23,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  9,                                   /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  9,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 77,  /* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  25,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  37,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  44,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 69,  /* lineNo */
  44,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  44,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  56,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  13,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  21,                                  /* colNo */
  "c",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  26,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  9,                                   /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  9,                                   /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  18,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  91,                                  /* lineNo */
  5,                                   /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "alpha",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  36,                                  /* colNo */
  "A",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  43,                                  /* colNo */
  "B",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 83,  /* lineNo */
  43,                                  /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  43,                                  /* colNo */
  "O",                                 /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  55,                                  /* colNo */
  "beta",                              /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  13,                                  /* colNo */
  "xi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  26,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  39,                                  /* colNo */
  "xi",                                /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  13,                                  /* colNo */
  "gamma",                             /* aName */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 22,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 77,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 78,/* lineNo */
  1,                                   /* colNo */
  "hmmSmoother",                       /* fName */
  "Z:\\Projects\\Fluxus\\PRMLT\\chapter13\\HMM - matlab fex\\hmmSmoother.m"/* pName */
};

/* Function Definitions */
void hmmSmoother(const emlrtStack *sp, const emxArray_real_T *O, const
                 emxArray_real_T *lambda_A, const emxArray_real_T *lambda_B,
                 const emxArray_real_T *lambda_pi, emxArray_real_T *b_gamma,
                 emxArray_real_T *xi, emxArray_real_T *c)
{
  int32_T T;
  int32_T N;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *alpha;
  int32_T b_i;
  int32_T i1;
  int32_T t;
  emxArray_real_T *beta;
  int32_T i2;
  int32_T i3;
  int32_T j;
  int32_T i4;
  int32_T i5;
  real_T d;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

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
  N = lambda_A->size[0] - 1;
  i = c->size[0] * c->size[1];
  c->size[0] = 1;
  c->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, c, i, &g_emlrtRTEI);
  loop_ub = O->size[1];
  for (i = 0; i < loop_ub; i++) {
    c->data[i] = 0.0;
  }

  emxInit_real_T(sp, &alpha, 2, &h_emlrtRTEI, true);

  /*  normalization constant */
  /*  alpha calc */
  i = alpha->size[0] * alpha->size[1];
  alpha->size[0] = lambda_A->size[0];
  alpha->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, alpha, i, &h_emlrtRTEI);
  loop_ub = lambda_A->size[0] * O->size[1];
  for (i = 0; i < loop_ub; i++) {
    alpha->data[i] = 0.0;
  }

  /* alpha_1 */
  i = lambda_A->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (1 > alpha->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, alpha->size[1], &c_emlrtBCI, sp);
    }

    if (1 > lambda_B->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, lambda_B->size[0], &emlrtBCI, sp);
    }

    if (1 > O->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, O->size[1], &b_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > lambda_pi->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, lambda_pi->size[0], &j_emlrtBCI, sp);
    }

    if (O->data[0] != (int32_T)muDoubleScalarFloor(O->data[0])) {
      emlrtIntegerCheckR2012b(O->data[0], &b_emlrtDCI, sp);
    }

    i2 = (int32_T)O->data[0];
    if ((i2 < 1) || (i2 > lambda_B->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, lambda_B->size[1], &k_emlrtBCI, sp);
    }

    i3 = b_i + 1;
    if ((i3 < 1) || (i3 > alpha->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, alpha->size[0], &l_emlrtBCI, sp);
    }

    alpha->data[i3 - 1] = lambda_pi->data[i1 - 1] * lambda_B->data
      [lambda_B->size[0] * (i2 - 1)];
    if (1 > T) {
      emlrtDynamicBoundsCheckR2012b(1, 1, T, &e_emlrtBCI, sp);
    }

    if (1 > alpha->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, alpha->size[1], &d_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > alpha->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &m_emlrtBCI, sp);
    }

    c->data[0] += alpha->data[i1 - 1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* scale alpha_1 */
  if (1 > O->size[1]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, O->size[1], &f_emlrtBCI, sp);
  }

  c->data[0] = 1.0 / c->data[0];
  i = lambda_A->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if (1 > alpha->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, alpha->size[1], &i_emlrtBCI, sp);
    }

    if (1 > T) {
      emlrtDynamicBoundsCheckR2012b(1, 1, T, &g_emlrtBCI, sp);
    }

    if (1 > alpha->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, alpha->size[1], &h_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > alpha->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &o_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > alpha->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[0], &p_emlrtBCI, sp);
    }

    alpha->data[i2 - 1] = c->data[0] * alpha->data[i1 - 1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* compute alpha_t(i) */
  i = O->size[1];
  for (t = 0; t <= i - 2; t++) {
    i1 = t + 2;
    if ((i1 < 1) || (i1 > c->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, c->size[1], &n_emlrtBCI, sp);
    }

    c->data[i1 - 1] = 0.0;
    for (j = 0; j <= N; j++) {
      i1 = j + 1;
      if ((i1 < 1) || (i1 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &q_emlrtBCI, sp);
      }

      i2 = t + 2;
      if ((i2 < 1) || (i2 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[1], &q_emlrtBCI, sp);
      }

      alpha->data[(i1 + alpha->size[0] * (i2 - 1)) - 1] = 0.0;

      /* initialize alpha_t(j) */
      for (b_i = 0; b_i <= N; b_i++) {
        i1 = j + 1;
        if ((i1 < 1) || (i1 > alpha->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &t_emlrtBCI, sp);
        }

        i2 = t + 2;
        if ((i2 < 1) || (i2 > alpha->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[1], &t_emlrtBCI, sp);
        }

        i3 = b_i + 1;
        if ((i3 < 1) || (i3 > alpha->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, alpha->size[0], &u_emlrtBCI, sp);
        }

        i4 = t + 1;
        if ((i4 < 1) || (i4 > alpha->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, alpha->size[1], &u_emlrtBCI, sp);
        }

        i5 = b_i + 1;
        if ((i5 < 1) || (i5 > lambda_A->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, lambda_A->size[0], &v_emlrtBCI,
            sp);
        }

        i6 = j + 1;
        if ((i6 < 1) || (i6 > lambda_A->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, lambda_A->size[1], &v_emlrtBCI,
            sp);
        }

        i7 = j + 1;
        if ((i7 < 1) || (i7 > alpha->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i7, 1, alpha->size[0], &w_emlrtBCI, sp);
        }

        i8 = t + 2;
        if ((i8 < 1) || (i8 > alpha->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, alpha->size[1], &w_emlrtBCI, sp);
        }

        alpha->data[(i7 + alpha->size[0] * (i8 - 1)) - 1] = alpha->data[(i1 +
          alpha->size[0] * (i2 - 1)) - 1] + alpha->data[(i3 + alpha->size[0] *
          (i4 - 1)) - 1] * lambda_A->data[(i5 + lambda_A->size[0] * (i6 - 1)) -
          1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* i */
      i1 = j + 1;
      if ((i1 < 1) || (i1 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &x_emlrtBCI, sp);
      }

      i2 = t + 2;
      if ((i2 < 1) || (i2 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[1], &x_emlrtBCI, sp);
      }

      i3 = j + 1;
      if ((i3 < 1) || (i3 > lambda_B->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, lambda_B->size[0], &y_emlrtBCI, sp);
      }

      i4 = t + 2;
      if ((i4 < 1) || (i4 > O->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, O->size[1], &ab_emlrtBCI, sp);
      }

      d = O->data[i4 - 1];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &c_emlrtDCI, sp);
      }

      i4 = (int32_T)d;
      if ((i4 < 1) || (i4 > lambda_B->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, lambda_B->size[1], &y_emlrtBCI, sp);
      }

      i5 = j + 1;
      if ((i5 < 1) || (i5 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, alpha->size[0], &bb_emlrtBCI, sp);
      }

      i6 = t + 2;
      if ((i6 < 1) || (i6 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, alpha->size[1], &bb_emlrtBCI, sp);
      }

      alpha->data[(i5 + alpha->size[0] * (i6 - 1)) - 1] = alpha->data[(i1 +
        alpha->size[0] * (i2 - 1)) - 1] * lambda_B->data[(i3 + lambda_B->size[0]
        * (i4 - 1)) - 1];
      i1 = t + 2;
      if ((i1 < 1) || (i1 > c->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, c->size[1], &hb_emlrtBCI, sp);
      }

      i2 = j + 1;
      if ((i2 < 1) || (i2 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[0], &ib_emlrtBCI, sp);
      }

      i3 = t + 2;
      if ((i3 < 1) || (i3 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, alpha->size[1], &ib_emlrtBCI, sp);
      }

      i4 = t + 2;
      if ((i4 < 1) || (i4 > c->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, c->size[1], &jb_emlrtBCI, sp);
      }

      c->data[i4 - 1] = c->data[i1 - 1] + alpha->data[(i2 + alpha->size[0] * (i3
        - 1)) - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* j */
    /* scale alpha_t */
    i1 = t + 2;
    if ((i1 < 1) || (i1 > c->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, c->size[1], &r_emlrtBCI, sp);
    }

    i2 = t + 2;
    if ((i2 < 1) || (i2 > c->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, c->size[1], &s_emlrtBCI, sp);
    }

    c->data[i2 - 1] = 1.0 / c->data[i1 - 1];
    for (j = 0; j <= N; j++) {
      i1 = t + 2;
      if ((i1 < 1) || (i1 > c->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, c->size[1], &eb_emlrtBCI, sp);
      }

      i2 = j + 1;
      if ((i2 < 1) || (i2 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[0], &fb_emlrtBCI, sp);
      }

      i3 = t + 2;
      if ((i3 < 1) || (i3 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, alpha->size[1], &fb_emlrtBCI, sp);
      }

      i4 = j + 1;
      if ((i4 < 1) || (i4 > alpha->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, alpha->size[0], &gb_emlrtBCI, sp);
      }

      i5 = t + 2;
      if ((i5 < 1) || (i5 > alpha->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, alpha->size[1], &gb_emlrtBCI, sp);
      }

      alpha->data[(i4 + alpha->size[0] * (i5 - 1)) - 1] = c->data[i1 - 1] *
        alpha->data[(i2 + alpha->size[0] * (i3 - 1)) - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &beta, 2, &i_emlrtRTEI, true);

  /* t */
  /*  beta calc */
  i = beta->size[0] * beta->size[1];
  beta->size[0] = lambda_A->size[0];
  beta->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, beta, i, &i_emlrtRTEI);
  loop_ub = lambda_A->size[0] * O->size[1];
  for (i = 0; i < loop_ub; i++) {
    beta->data[i] = 0.0;
  }

  /* beta_T scaling */
  i = lambda_A->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    if ((T < 1) || (T > c->size[1])) {
      emlrtDynamicBoundsCheckR2012b(T, 1, c->size[1], &cb_emlrtBCI, sp);
    }

    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > beta->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, beta->size[0], &db_emlrtBCI, sp);
    }

    if (T > beta->size[1]) {
      emlrtDynamicBoundsCheckR2012b(T, 1, beta->size[1], &db_emlrtBCI, sp);
    }

    beta->data[(i1 + beta->size[0] * (T - 1)) - 1] = c->data[T - 1];

    /*  initialization says beta_T = 1 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* beta_t(i) */
  i = (int32_T)(((-1.0 - ((real_T)O->size[1] - 1.0)) + 1.0) / -1.0);
  emlrtForLoopVectorCheckR2012b((real_T)O->size[1] - 1.0, -1.0, 1.0,
    mxDOUBLE_CLASS, i, &d_emlrtRTEI, sp);
  for (t = 0; t < i; t++) {
    loop_ub = (T - t) - 1;
    for (b_i = 0; b_i <= N; b_i++) {
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > beta->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, beta->size[0], &kb_emlrtBCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > beta->size[1])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, beta->size[1], &kb_emlrtBCI,
          sp);
      }

      beta->data[(i1 + beta->size[0] * (loop_ub - 1)) - 1] = 0.0;
      for (j = 0; j <= N; j++) {
        i1 = b_i + 1;
        if ((i1 < 1) || (i1 > beta->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, beta->size[0], &lb_emlrtBCI, sp);
        }

        if (loop_ub > beta->size[1]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, beta->size[1], &lb_emlrtBCI,
            sp);
        }

        i2 = b_i + 1;
        if ((i2 < 1) || (i2 > lambda_A->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, lambda_A->size[0], &mb_emlrtBCI,
            sp);
        }

        i3 = j + 1;
        if ((i3 < 1) || (i3 > lambda_A->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, lambda_A->size[1], &mb_emlrtBCI,
            sp);
        }

        i4 = j + 1;
        if ((i4 < 1) || (i4 > lambda_B->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, lambda_B->size[0], &nb_emlrtBCI,
            sp);
        }

        i5 = loop_ub + 1;
        if ((i5 < 1) || (i5 > O->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, O->size[1], &ob_emlrtBCI, sp);
        }

        d = O->data[i5 - 1];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &e_emlrtDCI, sp);
        }

        i5 = (int32_T)d;
        if ((i5 < 1) || (i5 > lambda_B->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, lambda_B->size[1], &nb_emlrtBCI,
            sp);
        }

        i6 = j + 1;
        if ((i6 < 1) || (i6 > beta->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, beta->size[0], &pb_emlrtBCI, sp);
        }

        i7 = loop_ub + 1;
        if ((i7 < 1) || (i7 > beta->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i7, 1, beta->size[1], &pb_emlrtBCI, sp);
        }

        i8 = b_i + 1;
        if ((i8 < 1) || (i8 > beta->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, beta->size[0], &qb_emlrtBCI, sp);
        }

        if (loop_ub > beta->size[1]) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, beta->size[1], &qb_emlrtBCI,
            sp);
        }

        beta->data[(i8 + beta->size[0] * (loop_ub - 1)) - 1] = beta->data[(i1 +
          beta->size[0] * (loop_ub - 1)) - 1] + lambda_A->data[(i2 +
          lambda_A->size[0] * (i3 - 1)) - 1] * lambda_B->data[(i4 +
          lambda_B->size[0] * (i5 - 1)) - 1] * beta->data[(i6 + beta->size[0] *
          (i7 - 1)) - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* j */
      /* scale beta_t with same c_t as alpha_t */
      if (loop_ub > c->size[1]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c->size[1], &rb_emlrtBCI, sp);
      }

      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > beta->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, beta->size[0], &sb_emlrtBCI, sp);
      }

      if (loop_ub > beta->size[1]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, beta->size[1], &sb_emlrtBCI,
          sp);
      }

      i2 = b_i + 1;
      if ((i2 < 1) || (i2 > beta->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, beta->size[0], &tb_emlrtBCI, sp);
      }

      if (loop_ub > beta->size[1]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, beta->size[1], &tb_emlrtBCI,
          sp);
      }

      beta->data[(i2 + beta->size[0] * (loop_ub - 1)) - 1] = c->data[loop_ub - 1]
        * beta->data[(i1 + beta->size[0] * (loop_ub - 1)) - 1];
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* i */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* t */
  /* compute epsilon_t and gamma_t (no need to normalize, alpha and beta are scaled) */
  i = xi->size[0] * xi->size[1] * xi->size[2];
  xi->size[0] = lambda_A->size[0];
  xi->size[1] = lambda_A->size[0];
  emxEnsureCapacity_real_T(sp, xi, i, &j_emlrtRTEI);
  i = O->size[1] - 1;
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(i, &emlrtDCI, sp);
  }

  i1 = xi->size[0] * xi->size[1] * xi->size[2];
  xi->size[2] = i;
  emxEnsureCapacity_real_T(sp, xi, i1, &j_emlrtRTEI);
  i = O->size[1] - 1;
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(i, &d_emlrtDCI, sp);
  }

  loop_ub = lambda_A->size[0] * lambda_A->size[0] * i;
  for (i = 0; i < loop_ub; i++) {
    xi->data[i] = 0.0;
  }

  /* also called "di-gamma" */
  i = b_gamma->size[0] * b_gamma->size[1];
  b_gamma->size[0] = lambda_A->size[0];
  b_gamma->size[1] = O->size[1];
  emxEnsureCapacity_real_T(sp, b_gamma, i, &k_emlrtRTEI);
  loop_ub = lambda_A->size[0] * O->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_gamma->data[i] = 0.0;
  }

  i = O->size[1];
  for (t = 0; t <= i - 2; t++) {
    for (b_i = 0; b_i <= N; b_i++) {
      i1 = b_i + 1;
      if ((i1 < 1) || (i1 > b_gamma->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_gamma->size[0], &ub_emlrtBCI, sp);
      }

      i2 = t + 1;
      if ((i2 < 1) || (i2 > b_gamma->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[1], &ub_emlrtBCI, sp);
      }

      b_gamma->data[(i1 + b_gamma->size[0] * (i2 - 1)) - 1] = 0.0;
      for (j = 0; j <= N; j++) {
        i1 = b_i + 1;
        if ((i1 < 1) || (i1 > alpha->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &xb_emlrtBCI, sp);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > alpha->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, alpha->size[1], &xb_emlrtBCI, sp);
        }

        i3 = b_i + 1;
        if ((i3 < 1) || (i3 > lambda_A->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, lambda_A->size[0], &yb_emlrtBCI,
            sp);
        }

        i4 = j + 1;
        if ((i4 < 1) || (i4 > lambda_A->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, lambda_A->size[1], &yb_emlrtBCI,
            sp);
        }

        i5 = j + 1;
        if ((i5 < 1) || (i5 > lambda_B->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, lambda_B->size[0], &ac_emlrtBCI,
            sp);
        }

        i6 = t + 2;
        if ((i6 < 1) || (i6 > O->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, O->size[1], &bc_emlrtBCI, sp);
        }

        d = O->data[i6 - 1];
        if (d != (int32_T)muDoubleScalarFloor(d)) {
          emlrtIntegerCheckR2012b(d, &f_emlrtDCI, sp);
        }

        i6 = (int32_T)d;
        if ((i6 < 1) || (i6 > lambda_B->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, lambda_B->size[1], &ac_emlrtBCI,
            sp);
        }

        i7 = j + 1;
        if ((i7 < 1) || (i7 > beta->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i7, 1, beta->size[0], &cc_emlrtBCI, sp);
        }

        i8 = t + 2;
        if ((i8 < 1) || (i8 > beta->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i8, 1, beta->size[1], &cc_emlrtBCI, sp);
        }

        loop_ub = b_i + 1;
        if ((loop_ub < 1) || (loop_ub > xi->size[0])) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, xi->size[0], &dc_emlrtBCI,
            sp);
        }

        i9 = j + 1;
        if ((i9 < 1) || (i9 > xi->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i9, 1, xi->size[1], &dc_emlrtBCI, sp);
        }

        i10 = t + 1;
        if ((i10 < 1) || (i10 > xi->size[2])) {
          emlrtDynamicBoundsCheckR2012b(i10, 1, xi->size[2], &dc_emlrtBCI, sp);
        }

        xi->data[((loop_ub + xi->size[0] * (i9 - 1)) + xi->size[0] * xi->size[1]
                  * (i10 - 1)) - 1] = alpha->data[(i1 + alpha->size[0] * (i2 - 1))
          - 1] * lambda_A->data[(i3 + lambda_A->size[0] * (i4 - 1)) - 1] *
          lambda_B->data[(i5 + lambda_B->size[0] * (i6 - 1)) - 1] * beta->data
          [(i7 + beta->size[0] * (i8 - 1)) - 1];
        i1 = b_i + 1;
        if ((i1 < 1) || (i1 > b_gamma->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_gamma->size[0], &ec_emlrtBCI,
            sp);
        }

        i2 = t + 1;
        if ((i2 < 1) || (i2 > b_gamma->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[1], &ec_emlrtBCI,
            sp);
        }

        i3 = b_i + 1;
        if ((i3 < 1) || (i3 > xi->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, xi->size[0], &fc_emlrtBCI, sp);
        }

        i4 = j + 1;
        if ((i4 < 1) || (i4 > xi->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, xi->size[1], &fc_emlrtBCI, sp);
        }

        i5 = t + 1;
        if ((i5 < 1) || (i5 > xi->size[2])) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, xi->size[2], &fc_emlrtBCI, sp);
        }

        i6 = b_i + 1;
        if ((i6 < 1) || (i6 > b_gamma->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i6, 1, b_gamma->size[0], &gc_emlrtBCI,
            sp);
        }

        i7 = t + 1;
        if ((i7 < 1) || (i7 > b_gamma->size[1])) {
          emlrtDynamicBoundsCheckR2012b(i7, 1, b_gamma->size[1], &gc_emlrtBCI,
            sp);
        }

        b_gamma->data[(i6 + b_gamma->size[0] * (i7 - 1)) - 1] = b_gamma->data
          [(i1 + b_gamma->size[0] * (i2 - 1)) - 1] + xi->data[((i3 + xi->size[0]
          * (i4 - 1)) + xi->size[0] * xi->size[1] * (i5 - 1)) - 1];
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* j */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* i */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&beta);

  /* t */
  /* special case gamma */
  i = lambda_A->size[0];
  for (b_i = 0; b_i < i; b_i++) {
    i1 = b_i + 1;
    if ((i1 < 1) || (i1 > alpha->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, alpha->size[0], &vb_emlrtBCI, sp);
    }

    if ((T < 1) || (T > alpha->size[1])) {
      emlrtDynamicBoundsCheckR2012b(T, 1, alpha->size[1], &vb_emlrtBCI, sp);
    }

    i2 = b_i + 1;
    if ((i2 < 1) || (i2 > b_gamma->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, b_gamma->size[0], &wb_emlrtBCI, sp);
    }

    if (T > b_gamma->size[1]) {
      emlrtDynamicBoundsCheckR2012b(T, 1, b_gamma->size[1], &wb_emlrtBCI, sp);
    }

    b_gamma->data[(i2 + b_gamma->size[0] * (T - 1)) - 1] = alpha->data[(i1 +
      alpha->size[0] * (T - 1)) - 1];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&alpha);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (hmmSmoother.c) */
