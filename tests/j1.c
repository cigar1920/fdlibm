#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(j1)
#include "testdriver.h"



static test_f_f_data const j1_data[] = {
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },
	{ __LINE__, INF_P, ZERO_P, 0 },
#if 0 /* ZERO_P also ok */
	{ __LINE__, INF_M, ZERO_M, 0 },
#endif
	{ __LINE__, ZERO_P, ZERO_P, 0 },
#if 0 /* ZERO_P also ok */
	{ __LINE__, ZERO_M, ZERO_M, 0 },
#endif
	{ __LINE__, SUBNORM_P, ZERO_P, FLAG_SUBNORM },
	{ __LINE__, SUBNORM_M, ZERO_M, FLAG_SUBNORM },
	{ __LINE__, MIN_P, ZERO_P, 0 },
	{ __LINE__, MIN_M, ZERO_M, 0 },
	{ __LINE__, MAX_P, MAX_P, 0 },
	{ __LINE__, MAX_M, MAX_M, 0 },

	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-0.440050585744933515959682203718914913L, 0xbffd, 0xe14e4f74L, 0xb863629bL), 0 },
	{ __LINE__, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(0.0623780091344946810942311355879361177L, 0x3ffa, 0xff801553L, 0x8e4fa438L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(0.349243602174862192523281016426251335L, 0x3ffd, 0xb2d00eb3L, 0x5b45e3bcL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.440050585744933515959682203718914913L, 0x3ffd, 0xe14e4f74L, 0xb863629bL), 0 },
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(0.557936507910099641990121213156089400L, 0x3ffe, 0x8ed4ed4eL, 0xb7e408abL), 0 },
	{ __LINE__, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(0.576724807756873387202448242269137087L, 0x3ffe, 0x93a43cacL, 0x1b8f7ed8L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.0, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(0.234636346853914624381276651590454612L, 0x3ffc, 0xf04482b0L, 0xc30c16a5L), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* seems to be precision error */
	{ __LINE__, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(0.0434727461688614366697487680258592883L, 0x3ffa, 0xb2107a71L, 0x00488615L), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* seems to be precision error */

	{ __LINE__, HEXCONSTE(2.36072207283297986806e+22, 0x4049, 0x9ff80000L, 0x00000000L), HEXCONSTE(1.818984347516051243459364437186082741567e-12L, 0x3fd7, 0xffffd15dL, 0xc983090bL), FLAG_INEXACT },

#ifndef TEST_FLOAT
	{ __LINE__, HEXCONSTE(1.46344799023407084313e+253, 0x4347, 0xff800000L, 0x00001000L), HEXCONSTE(1.846591691699331493194965158699937660696e-127L, 0x3e59, 0xffffdb5eL, 0x5de330edL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.98846567431157953865e+307, 0x43fe, 0x80000000L, 0x00000000L), HEXCONSTE(8.2687542933709649327986678723012001545638e-155L, 0x3dff, 0x8de88730L, 0x43bf1671L), FLAG_INEXACT },
#endif

#if defined(TEST_LDOUBLE) && LDBL_MAX_EXP >= 16384
	{ __LINE__, HEXCONSTE(2.97432873839307941271e+4931, 0x7ffd, 0x80000000L, 0x00000000L), HEXCONSTE(8.0839224448726336195866026476176740513439e-2467L, 0x1ffe, 0xe1ba855bL, 0xa7e7ba4aL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(5.94865747678615882543e+4931, 0x7ffe, 0x80000000L, 0x00000000L), HEXCONSTE(-3.8895531955766020648617743624167352352217e-2467L, 0x9ffd, 0xd937989aL, 0x926f460eL), OVERFLOW_EXCEPTION_OK },
#endif

#ifdef TEST_FLOAT
	{ __LINE__, HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-4.40050572156906127930e-01, 0xbffd, 0xe14e4f00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.25000000000000000000e-01, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(6.23780079185962677002e-02, 0x3ffa, 0xff801500L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(7.50000000000000000000e-01, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(3.49243611097335815430e-01, 0x3ffd, 0xb2d00f00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(4.40050572156906127930e-01, 0x3ffd, 0xe14e4f00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.50000000000000000000e+00, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(5.57936489582061767578e-01, 0x3ffe, 0x8ed4ed00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.00000000000000000000e+00, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(5.76724827289581298828e-01, 0x3ffe, 0x93a43d00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.00000000000000000000e+00, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(2.34636351466178894043e-01, 0x3ffc, 0xf0448300L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+01, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(4.34727445244789123535e-02, 0x3ffa, 0xb2107a00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.36072207283297986806e+22, 0x4049, 0x9ff80000L, 0x00000000L), HEXCONSTE(1.81898430779564579396e-12, 0x3fd7, 0xffffd100L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509381294835813262e-20, 0xbfbe, 0xc6947700L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509381294835813262e-20, 0xbfbe, 0xc6947700L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509381294835813262e-20, 0xbfbe, 0xc6947700L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509381294835813262e-20, 0xbfbe, 0xc6947700L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.12500000000000000000e-02, 0x3ffa, 0x80000000L, 0x00000000L), HEXCONSTE(1.56230926513671875000e-02, 0x3ff8, 0xfff80000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.76562500000000000000e-04, 0x3ff5, 0x80000000L, 0x00000000L), HEXCONSTE(4.88281191792339086533e-04, 0x3ff3, 0xfffffe00L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.05175781250000000000e-05, 0x3ff0, 0x80000000L, 0x00000000L), HEXCONSTE(1.52587890625000000000e-05, 0x3fef, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.53674316406250000000e-07, 0x3feb, 0x80000000L, 0x00000000L), HEXCONSTE(4.76837158203125000000e-07, 0x3fea, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.98023223876953125000e-08, 0x3fe6, 0x80000000L, 0x00000000L), HEXCONSTE(1.49011611938476562500e-08, 0x3fe5, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.31322574615478515625e-10, 0x3fe1, 0x80000000L, 0x00000000L), HEXCONSTE(4.65661287307739257812e-10, 0x3fe0, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.91038304567337036133e-11, 0x3fdc, 0x80000000L, 0x00000000L), HEXCONSTE(1.45519152283668518066e-11, 0x3fdb, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.09494701772928237915e-13, 0x3fd7, 0x80000000L, 0x00000000L), HEXCONSTE(4.54747350886464118958e-13, 0x3fd6, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.84217094304040074348e-14, 0x3fd2, 0x80000000L, 0x00000000L), HEXCONSTE(1.42108547152020037174e-14, 0x3fd1, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.88178419700125232339e-16, 0x3fcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.44089209850062616169e-16, 0x3fcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.77555756156289135106e-17, 0x3fc8, 0x80000000L, 0x00000000L), HEXCONSTE(1.38777878078144567553e-17, 0x3fc7, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.67361737988403547206e-19, 0x3fc3, 0x80000000L, 0x00000000L), HEXCONSTE(4.33680868994201773603e-19, 0x3fc2, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), HEXCONSTE(3.94430452610505902706e-31, 0x3f9a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(5.87747175411143753984e-39, 0x3f80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(-5.87747175411143753984e-39, 0xbf80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(-0.0, 0x8000, 0x00000000L, 0x00000000L), 0 },
#endif

#ifdef TEST_DOUBLE
	{ __LINE__, HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-4.40050585744933497878e-01, 0xbffd, 0xe14e4f74L, 0xb8636000L), 0 },
	{ __LINE__, HEXCONSTE(0.125, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(6.23780091344946843734e-02, 0x3ffa, 0xff801553L, 0x8e4fa800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(0.75, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(3.49243602174862166621e-01, 0x3ffd, 0xb2d00eb3L, 0x5b45e000L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(4.40050585744933497878e-01, 0x3ffd, 0xe14e4f74L, 0xb8636000L), 0 },
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(5.57936507910099632745e-01, 0x3ffe, 0x8ed4ed4eL, 0xb7e40800L), 0 },
	{ __LINE__, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(5.76724807756873403264e-01, 0x3ffe, 0x93a43cacL, 0x1b8f8000L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.0, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(2.34636346853914629085e-01, 0x3ffc, 0xf04482b0L, 0xc30c1800L), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* seems to be precision error */
	{ __LINE__, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(4.34727461688614383317e-02, 0x3ffa, 0xb2107a71L, 0x00488800L), FLAG_INEXACT|FLAG_FAIL_ARANYM }, /* seems to be precision error */
	{ __LINE__, HEXCONSTE(2.36072207283297986806e+22, 0x4049, 0x9ff80000L, 0x00000000L), HEXCONSTE(1.81898434751605121714e-12, 0x3fd7, 0xffffd15dL, 0xc9830800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757104137e-20, 0xbfbe, 0xc6947737L, 0xb0589800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.46344799023407084313e+253, 0x4347, 0xff800000L, 0x00001000L), HEXCONSTE(1.84659169169933146950e-127, 0x3e59, 0xffffdb5eL, 0x5de33000L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757104137e-20, 0xbfbe, 0xc6947737L, 0xb0589800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.98846567431157953865e+307, 0x43fe, 0x80000000L, 0x00000000L), HEXCONSTE(8.26875429337096525540e-155, 0x3dff, 0x8de88730L, 0x43bf1800L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757104137e-20, 0xbfbe, 0xc6947737L, 0xb0589800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.22874584882999497959e-155, 0x3dfe, 0x9125bd84L, 0x36acc000L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757104137e-20, 0xbfbe, 0xc6947737L, 0xb0589800L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.22874584882999497959e-155, 0x3dfe, 0x9125bd84L, 0x36acc000L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.12500000000000000000e-02, 0x3ffa, 0x80000000L, 0x00000000L), HEXCONSTE(1.56230927289758222964e-02, 0x3ff8, 0xfff80015L, 0x5538e000L), 0 },
	{ __LINE__, HEXCONSTE(9.76562500000000000000e-04, 0x3ff5, 0x80000000L, 0x00000000L), HEXCONSTE(4.88281191792341417567e-04, 0x3ff3, 0xfffffe00L, 0x00015800L), 0 },
	{ __LINE__, HEXCONSTE(3.05175781250000000000e-05, 0x3ff0, 0x80000000L, 0x00000000L), HEXCONSTE(1.52587890607236431606e-05, 0x3fee, 0xffffffffL, 0x80000000L), 0 },
	{ __LINE__, HEXCONSTE(9.53674316406250000000e-07, 0x3feb, 0x80000000L, 0x00000000L), HEXCONSTE(4.76837158203070789891e-07, 0x3fe9, 0xffffffffL, 0xffe00000L), 0 },
	{ __LINE__, HEXCONSTE(2.98023223876953125000e-08, 0x3fe6, 0x80000000L, 0x00000000L), HEXCONSTE(1.49011611938476545956e-08, 0x3fe4, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9.31322574615478515625e-10, 0x3fe1, 0x80000000L, 0x00000000L), HEXCONSTE(4.65661287307739257812e-10, 0x3fe0, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.91038304567337036133e-11, 0x3fdc, 0x80000000L, 0x00000000L), HEXCONSTE(1.45519152283668518066e-11, 0x3fdb, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.09494701772928237915e-13, 0x3fd7, 0x80000000L, 0x00000000L), HEXCONSTE(4.54747350886464118958e-13, 0x3fd6, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.84217094304040074348e-14, 0x3fd2, 0x80000000L, 0x00000000L), HEXCONSTE(1.42108547152020037174e-14, 0x3fd1, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.88178419700125232339e-16, 0x3fcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.44089209850062616169e-16, 0x3fcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.77555756156289135106e-17, 0x3fc8, 0x80000000L, 0x00000000L), HEXCONSTE(1.38777878078144567553e-17, 0x3fc7, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.67361737988403547206e-19, 0x3fc3, 0x80000000L, 0x00000000L), HEXCONSTE(4.33680868994201773603e-19, 0x3fc2, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), HEXCONSTE(3.94430452610505902706e-31, 0x3f9a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.40991986510288411774e-181, 0x3da7, 0x80000000L, 0x00000000L), HEXCONSTE(1.20495993255144205887e-181, 0x3da6, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(5.87747175411143753984e-39, 0x3f80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), HEXCONSTE(1.00208418000448638900e-292, 0x3c35, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(-5.87747175411143753984e-39, 0xbf80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00208418000448638900e-292, 0xbc35, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(-7.00649232162408535462e-46, 0xbf69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), HEXCONSTE(-0.0, 0x8000, 0x00000000L, 0x00000000L), 0 },
#endif

#if defined(TEST_LDOUBLE) && LDBL_MAX_EXP >= 16384
	{ __LINE__, HEXCONSTE(-1.00000000000000000000e+00, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-4.40050585744933515957e-01, 0xbffd, 0xe14e4f74L, 0xb863629bL), 0 },
	{ __LINE__, HEXCONSTE(1.25000000000000000000e-01, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(6.23780091344946810937e-02, 0x3ffa, 0xff801553L, 0x8e4fa438L), 0 },
	{ __LINE__, HEXCONSTE(7.50000000000000000000e-01, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(3.49243602174862192533e-01, 0x3ffd, 0xb2d00eb3L, 0x5b45e3bcL), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(4.40050585744933515957e-01, 0x3ffd, 0xe14e4f74L, 0xb863629bL), 0 },
	{ __LINE__, HEXCONSTE(1.50000000000000000000e+00, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(5.57936507910099642015e-01, 0x3ffe, 0x8ed4ed4eL, 0xb7e408abL), 0 },
	{ __LINE__, HEXCONSTE(2.00000000000000000000e+00, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(5.76724807756873387218e-01, 0x3ffe, 0x93a43cacL, 0x1b8f7ed8L), 0 },
	{ __LINE__, HEXCONSTE(8.00000000000000000000e+00, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(2.34636346853914624382e-01, 0x3ffc, 0xf04482b0L, 0xc30c16a5L), 0 },
	{ __LINE__, HEXCONSTE(1.00000000000000000000e+01, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(4.34727461688614366681e-02, 0x3ffa, 0xb2107a71L, 0x00488615L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.36072207283297986806e+22, 0x4049, 0x9ff80000L, 0x00000000L), HEXCONSTE(1.81898434751605124347e-12, 0x3fd7, 0xffffd15dL, 0xc983090bL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757114188e-20, 0xbfbe, 0xc6947737L, 0xb0589956L), 0 },
	{ __LINE__, HEXCONSTE(1.46344799023407084313e+253, 0x4347, 0xff800000L, 0x00001000L), HEXCONSTE(1.84659169169933149323e-127, 0x3e59, 0xffffdb5eL, 0x5de330edL), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757114188e-20, 0xbfbe, 0xc6947737L, 0xb0589956L), 0 },
	{ __LINE__, HEXCONSTE(8.98846567431157953865e+307, 0x43fe, 0x80000000L, 0x00000000L), HEXCONSTE(8.26875429337096493275e-155, 0x3dff, 0x8de88730L, 0x43bf1671L), 0 },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757114188e-20, 0xbfbe, 0xc6947737L, 0xb0589956L), 0 },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.22874584882999520196e-155, 0x3dfe, 0x9125bd84L, 0x36acc226L), 0 },
	{ __LINE__, HEXCONSTE(2.97432873839307941271e+4931, 0x7ffd, 0x80000000L, 0x00000000L), HEXCONSTE(8.08392244487263361951e-2467, 0x1ffe, 0xe1ba855bL, 0xa7e7ba4aL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(-4.20509388323757114188e-20, 0xbfbe, 0xc6947737L, 0xb0589956L), 0 },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(4.22874584882999520196e-155, 0x3dfe, 0x9125bd84L, 0x36acc226L), 0 },
	{ __LINE__, HEXCONSTE(5.94865747678615882543e+4931, 0x7ffe, 0x80000000L, 0x00000000L), HEXCONSTE(-3.88955319557660206490e-2467, 0x9ffd, 0xd937989aL, 0x926f460eL), 0 },
	{ __LINE__, HEXCONSTE(3.12500000000000000000e-02, 0x3ffa, 0x80000000L, 0x00000000L), HEXCONSTE(1.56230927289758230867e-02, 0x3ff8, 0xfff80015L, 0x5538e3a5L), 0 },
	{ __LINE__, HEXCONSTE(9.76562500000000000000e-04, 0x3ff5, 0x80000000L, 0x00000000L), HEXCONSTE(4.88281191792341399488e-04, 0x3ff3, 0xfffffe00L, 0x00015555L), 0 },
	{ __LINE__, HEXCONSTE(3.05175781250000000000e-05, 0x3ff0, 0x80000000L, 0x00000000L), HEXCONSTE(1.52587890607236431606e-05, 0x3fee, 0xffffffffL, 0x80000000L), 0 },
	{ __LINE__, HEXCONSTE(9.53674316406250000000e-07, 0x3feb, 0x80000000L, 0x00000000L), HEXCONSTE(4.76837158203070789891e-07, 0x3fe9, 0xffffffffL, 0xffe00000L), 0 },
	{ __LINE__, HEXCONSTE(2.98023223876953125000e-08, 0x3fe6, 0x80000000L, 0x00000000L), HEXCONSTE(1.49011611938476545956e-08, 0x3fe4, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9.31322574615478515625e-10, 0x3fe1, 0x80000000L, 0x00000000L), HEXCONSTE(4.65661287307739257762e-10, 0x3fdf, 0xffffffffL, 0xfffffffeL), 0 },
	{ __LINE__, HEXCONSTE(2.91038304567337036133e-11, 0x3fdc, 0x80000000L, 0x00000000L), HEXCONSTE(1.45519152283668518066e-11, 0x3fdb, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9.09494701772928237915e-13, 0x3fd7, 0x80000000L, 0x00000000L), HEXCONSTE(4.54747350886464118958e-13, 0x3fd6, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.84217094304040074348e-14, 0x3fd2, 0x80000000L, 0x00000000L), HEXCONSTE(1.42108547152020037174e-14, 0x3fd1, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.88178419700125232339e-16, 0x3fcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.44089209850062616169e-16, 0x3fcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.77555756156289135106e-17, 0x3fc8, 0x80000000L, 0x00000000L), HEXCONSTE(1.38777878078144567553e-17, 0x3fc7, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.67361737988403547206e-19, 0x3fc3, 0x80000000L, 0x00000000L), HEXCONSTE(4.33680868994201773603e-19, 0x3fc2, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), HEXCONSTE(3.94430452610505902706e-31, 0x3f9a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.40991986510288411774e-181, 0x3da7, 0x80000000L, 0x00000000L), HEXCONSTE(1.20495993255144205887e-181, 0x3da6, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(2.47032822920623272088e-324, 0x3bcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(5.01237274920645200930e-3011, 0x18ef, 0x80000000L, 0x00000000L), HEXCONSTE(2.50618637460322600465e-3011, 0x18ee, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(5.87747175411143753984e-39, 0x3f80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.22507385850720138309e-308, 0x3c01, 0x80000000L, 0x00000000L), HEXCONSTE(1.11253692925360069155e-308, 0x3c00, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.36210314311209350626e-4932, 0x0001, 0x80000000L, 0x00000000L), HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), HEXCONSTE(8.40525785778023376566e-4933, 0x0000, 0x20000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), HEXCONSTE(1.00208418000448638900e-292, 0x3c35, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(-5.87747175411143753984e-39, 0xbf80, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.22507385850720138309e-308, 0xbc01, 0x80000000L, 0x00000000L), HEXCONSTE(-1.11253692925360069155e-308, 0xbc00, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3.36210314311209350626e-4932, 0x8001, 0x80000000L, 0x00000000L), HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), HEXCONSTE(-8.40525785778023376566e-4933, 0x8000, 0x20000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00208418000448638900e-292, 0xbc35, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(7.00649232162408535462e-46, 0x3f69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(2.47032822920623272088e-324, 0x3bcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.64519953188247460253e-4951, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(-7.00649232162408535462e-46, 0xbf69, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), HEXCONSTE(-2.47032822920623272088e-324, 0xbbcc, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3.64519953188247460253e-4951, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(-0.0, 0x8000, 0x00000000L, 0x00000000L), 0 },
#endif

};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(j1_data, ARRAY_SIZE(j1_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
