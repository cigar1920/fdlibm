#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(log1p)
#include "testdriver.h"



static test_f_f_data const flognp1_data[] = {
	{ __LINE__, ZERO_P, ZERO_P, 0 },
	{ __LINE__, ZERO_M, ZERO_M, FLAG_FAIL_ARANYM }, /* hm, flognp1(-0.0) = flogn(1.0), that should just be +zero? does not make much sense... */
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), INF_M, 0 }, /* Documentation says NaN is returned, but is wrong */
	{ __LINE__, HEXCONSTE(-2.0, 0xc000, 0x80000000L, 0x00000000L), QNAN_P, 0 },
	{ __LINE__, MIN_M, MIN_M, FLAG_MINVAL },
	{ __LINE__, MAX_M, QNAN_P, 0 },
	{ __LINE__, SUBNORM_P, SUBNORM_P, FLAG_SUBNORM },
	{ __LINE__, SUBNORM_M, SUBNORM_M, FLAG_SUBNORM },
	{ __LINE__, INF_P, INF_P, FLAG_FAIL_ARANYM },
	{ __LINE__, INF_M, QNAN_P, 0 },
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },

	{ __LINE__, HEXCONSTE(1.71828186511993408203e+00, 0x3fff, 0xdbf0a900L, 0x00000000L), HEXCONSTE(1.00000001348678721079e+00, 0x3fff, 0x8000001cL, 0xf6708edbL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.71828174591064453125e+00, 0x3fff, 0xdbf0a800L, 0x00000000L), HEXCONSTE(9.99999969632140018282e-01, 0x3ffe, 0xffffff7dL, 0x922f51a3L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.71828182845904531284e+00, 0x3fff, 0xdbf0a8b1L, 0x45769800L), HEXCONSTE(1.00000000000000002851e+00, 0x3fff, 0x80000000L, 0x00000107L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.71828182845904509080e+00, 0x3fff, 0xdbf0a8b1L, 0x45769000L), HEXCONSTE(9.99999999999999946820e-01, 0x3ffe, 0xffffffffL, 0xfffffc2bL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.71828182845904523532e+00, 0x3fff, 0xdbf0a8b1L, 0x45769535L), HEXCONSTE(9.99999999999999946820e-01, 0x3ffe, 0xffffffffL, 0xffffffffL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(1.71828182845904523543e+00, 0x3fff, 0xdbf0a8b1L, 0x45769536L), HEXCONSTE(1.00000000000000000000e+00, 0x3fff, 0x80000000L, 0x00000000L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-2.50000000000000000000e-01, 0xbffd, 0x80000000L, 0x00000000L), HEXCONSTE(-2.87682072451780927443e-01, 0xbffd, 0x934b1089L, 0xa6dc93c2L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-8.75000000000000000000e-01, 0xbffe, 0xe0000000L, 0x00000000L), HEXCONSTE(-2.07944154167983592829e+00, 0xc000, 0x851591f9L, 0xdd5b9b41L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(3.12500000000000000000e-02, 0x3ffa, 0x80000000L, 0x00000000L), HEXCONSTE(3.07716586667536883714e-02, 0x3ff9, 0xfc14d873L, 0xc1980268L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(9.76562500000000000000e-04, 0x3ff5, 0x80000000L, 0x00000000L), HEXCONSTE(9.76085973055458895953e-04, 0x3ff4, 0xffe00554L, 0x55887de0L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(3.05175781250000000000e-05, 0x3ff0, 0x80000000L, 0x00000000L), HEXCONSTE(3.05171124731863785698e-05, 0x3fef, 0xffff0001L, 0x55535559L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(9.53674316406250000000e-07, 0x3feb, 0x80000000L, 0x00000000L), HEXCONSTE(9.53673861659188233891e-07, 0x3fea, 0xfffff800L, 0x00555551L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.98023223876953125000e-08, 0x3fe6, 0x80000000L, 0x00000000L), HEXCONSTE(2.98023219436061114727e-08, 0x3fe5, 0xffffffc0L, 0x00001555L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(9.31322574615478515625e-10, 0x3fe1, 0x80000000L, 0x00000000L), HEXCONSTE(9.31322574181797646883e-10, 0x3fe0, 0xfffffffeL, 0x00000005L), 0 },
	{ __LINE__, HEXCONSTE(2.91038304567337036133e-11, 0x3fdc, 0x80000000L, 0x00000000L), HEXCONSTE(2.91038304563101871397e-11, 0x3fdb, 0xffffffffL, 0xf0000000L), 0 },
	{ __LINE__, HEXCONSTE(9.09494701772928237915e-13, 0x3fd7, 0x80000000L, 0x00000000L), HEXCONSTE(9.09494701772514647609e-13, 0x3fd6, 0xffffffffL, 0xff800000L), 0 },
	{ __LINE__, HEXCONSTE(2.84217094304040074348e-14, 0x3fd2, 0x80000000L, 0x00000000L), HEXCONSTE(2.84217094304036035381e-14, 0x3fd1, 0xffffffffL, 0xfffc0000L), 0 },
	{ __LINE__, HEXCONSTE(8.88178419700125232339e-16, 0x3fcd, 0x80000000L, 0x00000000L), HEXCONSTE(8.88178419700124837908e-16, 0x3fcc, 0xffffffffL, 0xffffe000L), 0 },
	{ __LINE__, HEXCONSTE(2.77555756156289135106e-17, 0x3fc8, 0x80000000L, 0x00000000L), HEXCONSTE(2.77555756156289131254e-17, 0x3fc7, 0xffffffffL, 0xffffff00L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.67361737988403547206e-19, 0x3fc3, 0x80000000L, 0x00000000L), HEXCONSTE(8.67361737988403546830e-19, 0x3fc2, 0xffffffffL, 0xfffffff8L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.40991986510288411774e-181, 0x3da7, 0x80000000L, 0x00000000L), HEXCONSTE(2.40991986510288411774e-181, 0x3da7, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(5.01237274920645200930e-3011, 0x18ef, 0x80000000L, 0x00000000L), HEXCONSTE(5.01237274920645200930e-3011, 0x18ef, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), HEXCONSTE(1.17549435082228750797e-38, 0x3f81, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.22507385850720138309e-308, 0x3c01, 0x80000000L, 0x00000000L), HEXCONSTE(2.22507385850720138309e-308, 0x3c01, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(3.36210314311209350626e-4932, 0x0001, 0x80000000L, 0x00000000L), HEXCONSTE(3.36210314311209350626e-4932, 0x0001, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), HEXCONSTE(1.68105157155604675313e-4932, 0x0000, 0x40000000L, 0x00000000L), 0 },
#endif
	{ __LINE__, HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), HEXCONSTE(2.00416836000897277800e-292, 0x3c36, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), HEXCONSTE(1.40129846432481707092e-45, 0x3f6a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(3.64519953188247460253e-4951, 0x0000, 0x00000000L, 0x00000001L), HEXCONSTE(3.64519953188247460253e-4951, 0x0000, 0x00000000L, 0x00000001L), 0 },
#endif
	{ __LINE__, HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), HEXCONSTE(0.00000000000000000000e+00, 0x0000, 0x00000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), HEXCONSTE(-1.17549435082228750797e-38, 0xbf81, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.22507385850720138309e-308, 0xbc01, 0x80000000L, 0x00000000L), HEXCONSTE(-2.22507385850720138309e-308, 0xbc01, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(-3.36210314311209350626e-4932, 0x8001, 0x80000000L, 0x00000000L), HEXCONSTE(-3.36210314311209350626e-4932, 0x8001, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), HEXCONSTE(-1.68105157155604675313e-4932, 0x8000, 0x40000000L, 0x00000000L), 0 },
#endif
	{ __LINE__, HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), HEXCONSTE(-2.00416836000897277800e-292, 0xbc36, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), HEXCONSTE(-1.40129846432481707092e-45, 0xbf6a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), HEXCONSTE(-4.94065645841246544177e-324, 0xbbcd, 0x80000000L, 0x00000000L), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(-3.64519953188247460253e-4951, 0x8000, 0x00000000L, 0x00000001L), HEXCONSTE(-3.64519953188247460253e-4951, 0x8000, 0x00000000L, 0x00000001L), 0 },
#endif
	{ __LINE__, HEXCONSTE(1.02400000000000000000e+03, 0x4009, 0x80000000L, 0x00000000L), HEXCONSTE(6.93244789157250855321e+00, 0x4001, 0xddd69cf5L, 0xf0e6045bL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.04857600000000000000e+06, 0x4013, 0x80000000L, 0x00000000L), HEXCONSTE(1.38629445648727678475e+01, 0x4002, 0xddce9ef5L, 0xc63b5817L), 0 },
	{ __LINE__, HEXCONSTE(1.07374182400000000000e+09, 0x401d, 0x80000000L, 0x00000000L), HEXCONSTE(2.07944154177296818570e+01, 0x4003, 0xa65af678L, 0x74b28211L), 0 },
	{ __LINE__, HEXCONSTE(1.12589990684262400000e+15, 0x4031, 0x80000000L, 0x00000000L), HEXCONSTE(3.46573590279972663583e+01, 0x4004, 0x8aa122b9L, 0x9bea180eL), 0 },
	{ __LINE__, HEXCONSTE(1.15292150460684697600e+18, 0x403b, 0x80000000L, 0x00000000L), HEXCONSTE(4.15888308335967185649e+01, 0x4004, 0xa65af678L, 0x54b28211L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.26765060022822940150e+30, 0x4063, 0x80000000L, 0x00000000L), HEXCONSTE(6.93147180559945309403e+01, 0x4005, 0x8aa122b9L, 0x9bea170eL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.87228390520683530551e+01, 0x4005, 0xb17217f5L, 0xd1cf78acL), 0 },
	{ __LINE__, HEXCONSTE(1.07150860718626732095e+301, 0x43e7, 0x80000000L, 0x00000000L), HEXCONSTE(6.93147180559945309430e+02, 0x4008, 0xad496b68L, 0x02e49cd2L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(3.40282346638528859812e+38, 0x407e, 0xffffff00L, 0x00000000L), HEXCONSTE(8.87228390520683530551e+01, 0x4005, 0xb17217f5L, 0xd1cf78acL), 0 },
	{ __LINE__, HEXCONSTE(1.79769313486231570815e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(7.09782712893383996744e+02, 0x4008, 0xb17217f7L, 0xd1cf79aaL), 0 },
#ifdef TEST_LDOUBLE
	{ __LINE__, HEXCONSTE(1.18973149535723176502e+4932, 0x7ffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(1.13565234062941439497e+04, 0x400c, 0xb17217f7L, 0xd1cf79acL), 0 },
#endif
	{ __LINE__, HEXCONSTE(4.47818189859390258789e-01, 0x3ffd, 0xe5486d00L, 0x00000000L), HEXCONSTE(3.70057726590900684178e-01, 0x3ffd, 0xbd7834d2L, 0xae1826bbL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.26667302846908569336e-01, 0x3ffd, 0xda742300L, 0x00000000L), HEXCONSTE(3.55341166846226615687e-01, 0x3ffd, 0xb5ef4705L, 0x0dd5ede1L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(5.01541376113891601562e+00, 0x4001, 0xa07e4500L, 0x00000000L), HEXCONSTE(1.79432513528011229479e+00, 0x3fff, 0xe5ac722fL, 0x359d2474L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(4.46847349405288696289e-01, 0x3ffd, 0xe4c92d00L, 0x00000000L), HEXCONSTE(3.69386947547633246711e-01, 0x3ffd, 0xbd204936L, 0x929cc151L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.46847319602966308594e-01, 0x3ffd, 0xe4c92c00L, 0x00000000L), HEXCONSTE(3.69386926949521976113e-01, 0x3ffd, 0xbd204885L, 0xa2e2f98cL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.46847332765786697806e-01, 0x3ffd, 0xe4c92c71L, 0x11592000L), HEXCONSTE(3.69386936047109642068e-01, 0x3ffd, 0xbd2048d3L, 0xc8b18710L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.29399693012237548828e-01, 0x3ffe, 0x8786bd00L, 0x00000000L), HEXCONSTE(4.24875300903655772161e-01, 0x3ffd, 0xd9894164L, 0x84caefefL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.71157163381576538086e-01, 0x3ffd, 0xf13b8300L, 0x00000000L), HEXCONSTE(3.86049277096128215124e-01, 0x3ffd, 0xc5a84037L, 0x8b6c8c58L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.71157133579254150391e-01, 0x3ffd, 0xf13b8200L, 0x00000000L), HEXCONSTE(3.86049256838385921264e-01, 0x3ffd, 0xc5a83f89L, 0x882d77acL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.71157161417916026114e-01, 0x3ffd, 0xf13b82efL, 0x21dd6800L), HEXCONSTE(3.86049275761355451100e-01, 0x3ffd, 0xc5a8402cL, 0x143a486bL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.94189643859863281250e-01, 0x3ffe, 0x981cd000L, 0x00000000L), HEXCONSTE(4.66365546854507051499e-01, 0x3ffd, 0xeec77707L, 0x7149719aL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.94189584255218505859e-01, 0x3ffe, 0x981ccf00L, 0x00000000L), HEXCONSTE(4.66365509465827405238e-01, 0x3ffd, 0xeec775c6L, 0x46b5fa79L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(5.94189616043658164202e-01, 0x3ffe, 0x981ccf88L, 0x87c25000L), HEXCONSTE(4.66365529406014981035e-01, 0x3ffd, 0xeec77671L, 0x8fa5a53aL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.94189616043658053179e-01, 0x3ffe, 0x981ccf88L, 0x87c24800L), HEXCONSTE(4.66365529406014911402e-01, 0x3ffd, 0xeec77671L, 0x8fa59b31L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(5.94189616043658087603e-01, 0x3ffe, 0x981ccf88L, 0x87c24a7bL), HEXCONSTE(4.66365529406014932978e-01, 0x3ffd, 0xeec77671L, 0x8fa59e4dL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.44569814205169677734e-01, 0x3ffe, 0xa5028700L, 0x00000000L), HEXCONSTE(4.97478838895861903924e-01, 0x3ffd, 0xfeb58bdfL, 0x0501d5d5L), FLAG_INEXACT5 },
	{ __LINE__, HEXCONSTE(6.44569754600524902344e-01, 0x3ffe, 0xa5028600L, 0x00000000L), HEXCONSTE(4.97478802652556608717e-01, 0x3ffd, 0xfeb58aa7L, 0xb122ceb9L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.44569756635426815983e-01, 0x3ffe, 0xa5028608L, 0xbd65f800L), HEXCONSTE(4.97478803889902672434e-01, 0x3ffd, 0xfeb58ab2L, 0x5216b769L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.44569756635426704960e-01, 0x3ffe, 0xa5028608L, 0xbd65f000L), HEXCONSTE(4.97478803889902604943e-01, 0x3ffd, 0xfeb58ab2L, 0x5216adafL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(6.44569756635426754237e-01, 0x3ffe, 0xa5028608L, 0xbd65f38dL), HEXCONSTE(4.97478803889902634894e-01, 0x3ffd, 0xfeb58ab2L, 0x5216b200L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.59245806932449340820e-01, 0x3ffd, 0xb7ef1100L, 0x00000000L), HEXCONSTE(3.06929992200031935768e-01, 0x3ffd, 0x9d25ed8dL, 0x5243a23bL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.59245777130126953125e-01, 0x3ffd, 0xb7ef1000L, 0x00000000L), HEXCONSTE(3.06929970274400410965e-01, 0x3ffd, 0x9d25ecd0L, 0xfb4a635aL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(3.59245804111232969191e-01, 0x3ffd, 0xb7ef10e7L, 0xc4146000L), HEXCONSTE(3.06929990124457113186e-01, 0x3ffd, 0x9d25ed7bL, 0x7e06e24fL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(3.59245804111232913680e-01, 0x3ffd, 0xb7ef10e7L, 0xc4145800L), HEXCONSTE(3.06929990124457072339e-01, 0x3ffd, 0x9d25ed7bL, 0x7e06dc6cL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(3.59245804111232931380e-01, 0x3ffd, 0xb7ef10e7L, 0xc4145a8dL), HEXCONSTE(3.06929990124457085376e-01, 0x3ffd, 0x9d25ed7bL, 0x7e06de4dL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.79081720113754272461e-01, 0x3ffd, 0xf54a3300L, 0x00000000L), HEXCONSTE(3.91421435828846050320e-01, 0x3ffd, 0xc86863f3L, 0xad2ff2b3L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(2.33715248107910156250e+00, 0x4000, 0x9593e800L, 0x00000000L), HEXCONSTE(1.20511789278555936367e+00, 0x3fff, 0x9a414d98L, 0xab511400L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.99057948589324951172e-01, 0x3ffd, 0xff848600L, 0x00000000L), HEXCONSTE(4.04836876538246344951e-01, 0x3ffd, 0xcf46c771L, 0xe4a3377bL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.99057918787002563477e-01, 0x3ffd, 0xff848500L, 0x00000000L), HEXCONSTE(4.04836856657545460795e-01, 0x3ffd, 0xcf46c6c7L, 0x1e83947bL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.99057926735368584392e-01, 0x3ffd, 0xff848544L, 0x46a44800L), HEXCONSTE(4.04836861959786221640e-01, 0x3ffd, 0xcf46c6f4L, 0xaa43c4f4L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.99057926735368528881e-01, 0x3ffd, 0xff848544L, 0x46a44000L), HEXCONSTE(4.04836861959786184587e-01, 0x3ffd, 0xcf46c6f4L, 0xaa43bf9dL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.99057926735368569620e-01, 0x3ffd, 0xff848544L, 0x46a445dfL), HEXCONSTE(4.04836861959786211774e-01, 0x3ffd, 0xcf46c6f4L, 0xaa43c388L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.09445589780807495117e-01, 0xbffd, 0x9e6fa700L, 0x00000000L), HEXCONSTE(-3.70260510947288434342e-01, 0xbffd, 0xbd92c923L, 0x09a734bbL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.09445619583129882812e-01, 0xbffd, 0x9e6fa800L, 0x00000000L), HEXCONSTE(-3.70260554104384515060e-01, 0xbffd, 0xbd92ca95L, 0xc11c6f36L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.09445606964839747821e-01, 0xbffd, 0x9e6fa793L, 0x9c162800L), HEXCONSTE(-3.70260535831688870011e-01, 0xbffd, 0xbd92c9f8L, 0xcb0745acL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.09445606964839803332e-01, 0xbffd, 0x9e6fa793L, 0x9c163000L), HEXCONSTE(-3.70260535831688950405e-01, 0xbffd, 0xbd92c9f8L, 0xcb075142L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.09445606964839758094e-01, 0xbffd, 0x9e6fa793L, 0x9c16297bL), HEXCONSTE(-3.70260535831688884892e-01, 0xbffd, 0xbd92c9f8L, 0xcb0747d1L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.09445606964839758121e-01, 0xbffd, 0x9e6fa793L, 0x9c16297cL), HEXCONSTE(-3.70260535831688884919e-01, 0xbffd, 0xbd92c9f8L, 0xcb0747d2L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.48923438787460327148e-01, 0x3ffd, 0xe5d94b00L, 0x00000000L), HEXCONSTE(3.70820824666872537312e-01, 0x3ffd, 0xbddc3a25L, 0x3d6c6619L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.48923408985137939453e-01, 0x3ffd, 0xe5d94a00L, 0x00000000L), HEXCONSTE(3.70820804098275262698e-01, 0x3ffd, 0xbddc3974L, 0x8e998569L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.48923411849659392825e-01, 0x3ffd, 0xe5d94a18L, 0x9b263800L), HEXCONSTE(3.70820806075275173646e-01, 0x3ffd, 0xbddc3985L, 0x8a118767L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.48923411849659337314e-01, 0x3ffd, 0xe5d94a18L, 0x9b263000L), HEXCONSTE(3.70820806075275135320e-01, 0x3ffd, 0xbddc3985L, 0x8a1181e1L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.48923411849659356585e-01, 0x3ffd, 0xe5d94a18L, 0x9b2632c7L), HEXCONSTE(3.70820806075275148628e-01, 0x3ffd, 0xbddc3985L, 0x8a1183ccL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.48923411849659356558e-01, 0x3ffd, 0xe5d94a18L, 0x9b2632c6L), HEXCONSTE(3.70820806075275148601e-01, 0x3ffd, 0xbddc3985L, 0x8a1183cbL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.90608966350555419922e-01, 0xbffd, 0xc7fde600L, 0x00000000L), HEXCONSTE(-4.95295125946312517749e-01, 0xbffd, 0xfd97529fL, 0x9d7f7e14L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.90608996152877807617e-01, 0xbffd, 0xc7fde700L, 0x00000000L), HEXCONSTE(-4.95295174851402141355e-01, 0xbffd, 0xfd975443L, 0xb4ed6b0dL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.90608967853182387220e-01, 0xbffd, 0xc7fde60cL, 0xe84fc800L), HEXCONSTE(-4.95295128412097024231e-01, 0xbffd, 0xfd9752b4L, 0xcbd0c3fcL), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.90608967853182442731e-01, 0xbffd, 0xc7fde60cL, 0xe84fd000L), HEXCONSTE(-4.95295128412097115304e-01, 0xbffd, 0xfd9752b4L, 0xcbd0d11cL), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(-3.90608967853182390554e-01, 0xbffd, 0xc7fde60cL, 0xe84fc87bL), HEXCONSTE(-4.95295128412097029706e-01, 0xbffd, 0xfd9752b4L, 0xcbd0c4c6L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(-3.90608967853182390581e-01, 0xbffd, 0xc7fde60cL, 0xe84fc87cL), HEXCONSTE(-4.95295128412097029734e-01, 0xbffd, 0xfd9752b4L, 0xcbd0c4c7L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.17804569005966186523e-01, 0x3ffd, 0xd5ea7b00L, 0x00000000L), HEXCONSTE(3.49109597036187463659e-01, 0x3ffd, 0xb2be7e3bL, 0xfaf6bc09L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.17804539203643798828e-01, 0x3ffd, 0xd5ea7a00L, 0x00000000L), HEXCONSTE(3.49109576016137625751e-01, 0x3ffd, 0xb2be7d87L, 0x6b62a848L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.17804539433889066125e-01, 0x3ffd, 0xd5ea7a01L, 0xfa509000L), HEXCONSTE(3.49109576178533259909e-01, 0x3ffd, 0xb2be7d88L, 0xd07f45a4L), FLAG_INEXACT2 },
	{ __LINE__, HEXCONSTE(4.17804539433889010613e-01, 0x3ffd, 0xd5ea7a01L, 0xfa508800L), HEXCONSTE(3.49109576178533220769e-01, 0x3ffd, 0xb2be7d88L, 0xd07f4000L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.17804539433889036011e-01, 0x3ffd, 0xd5ea7a01L, 0xfa508ba9L), HEXCONSTE(3.49109576178533238659e-01, 0x3ffd, 0xb2be7d88L, 0xd07f4294L), FLAG_INEXACT3 },
	{ __LINE__, HEXCONSTE(4.17804539433889035984e-01, 0x3ffd, 0xd5ea7a01L, 0xfa508ba8L), HEXCONSTE(3.49109576178533238659e-01, 0x3ffd, 0xb2be7d88L, 0xd07f4294L), FLAG_INEXACT3 },
};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(flognp1_data, ARRAY_SIZE(flognp1_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
