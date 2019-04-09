#include "testconfig.h"
#ifdef HAVE_TRUNC
#define TEST_FUNC_F_F __MATH_PRECNAME(trunc)
#include "testdriver.h"



static test_f_f_data const fintrz_data[] = {
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },
	{ __LINE__, INF_P, INF_P, FLAG_XFAIL_LINUX }, /* generates NaN */
	{ __LINE__, INF_M, INF_M, FLAG_XFAIL_LINUX }, /* generates NaN */
	{ __LINE__, ZERO_P, ZERO_P, 0 },
	{ __LINE__, ZERO_M, ZERO_M, FLAG_FAIL_ARANYM2 },
	{ __LINE__, SUBNORM_P, ZERO_P, 0 },
	{ __LINE__, SUBNORM_M, ZERO_M, 0 },
	{ __LINE__, MIN_P, ZERO_P, FLAG_MINVAL }, /* generates NaN */
	{ __LINE__, MIN_M, ZERO_M, FLAG_MINVAL }, /* generates NaN */
	{ __LINE__, MAX_P, MAX_P, 0 },
	{ __LINE__, MAX_M, MAX_M, 0 },
	
	{ __LINE__, HEXCONSTE(4.5, 0x4001, 0x90000000L, 0x00000000L), HEXCONSTE(4.0, 0x4001, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.5, 0x4000, 0xe0000000L, 0x00000000L), HEXCONSTE(3.0, 0x4000, 0xc0000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.5, 0x4000, 0xa0000000L, 0x00000000L), HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.5, 0x3ffe, 0x80000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.5, 0xbffe, 0x80000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.5, 0xbfff, 0xc0000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.0, 0xc000, 0x80000000L, 0x00000000L), HEXCONSTE(-2.0, 0xc000, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.5, 0xc000, 0xa0000000L, 0x00000000L), HEXCONSTE(-2.0, 0xc000, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3.5, 0xc000, 0xe0000000L, 0x00000000L), HEXCONSTE(-3.0, 0xc000, 0xc0000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.5, 0xc001, 0x90000000L, 0x00000000L), HEXCONSTE(-4.0, 0xc001, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.1, 0x3ffb, 0xccccccccL, 0xcccccccdL), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.25, 0x3ffd, 0x80000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.625, 0x3ffe, 0xa0000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(1.625, 0x3fff, 0xd0000000L, 0x00000000L), HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-0.1, 0xbffb, 0xccccccccL, 0xcccccccdL), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-0.25, 0xbffd, 0x80000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-0.625, 0xbffe, 0xa0000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-1.625, 0xbfff, 0xd0000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(262144.75, 0x4011, 0x80001800L, 0x00000000L), HEXCONSTE(262144.0, 0x4011, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(262142.75, 0x4010, 0xffffb000L, 0x00000000L), HEXCONSTE(262142.0, 0x4010, 0xffff8000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(524286.75, 0x4011, 0xffffd800L, 0x00000000L), HEXCONSTE(524286.0, 0x4011, 0xffffc000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(524288.75, 0x4012, 0x80000c00L, 0x00000000L), HEXCONSTE(524288.0, 0x4012, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1048576.75, 0x4013, 0x80000600L, 0x00000000L), HEXCONSTE(1048576.0, 0x4013, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1048580.625, 0x4013, 0x80002500L, 0x00000000L), HEXCONSTE(1048580, 0x4013, 0x80002000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2097152.75, 0x4014, 0x80000300L, 0x00000000L), HEXCONSTE(2097152.0, 0x4014, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2492472.75, 0x4014, 0x9820e300L, 0x00000000L), HEXCONSTE(2492472.0, 0x4014, 0x9820e000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2886220.75, 0x4014, 0xb0293300L, 0x00000000L), HEXCONSTE(2886220.0, 0x4014, 0xb0293000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3058792.75, 0x4014, 0xbab1a300L, 0x00000000L), HEXCONSTE(3058792.0, 0x4014, 0xbab1a000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8388610.125, 0x4016, 0x80000220L, 0x00000000L), HEXCONSTE(8388610.0, 0x4016, 0x80000200L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4294967296.625, 0x401f, 0x80000000L, 0x50000000L), HEXCONSTE(4294967296.0, 0x401f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1048580.625, 0xc013, 0x80002500L, 0x00000000L), HEXCONSTE(-1048580, 0xc013, 0x80002000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1048576.75, 0xc013, 0x80000600L, 0x00000000L), HEXCONSTE(-1048576.0, 0xc013, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2097152.75, 0xc014, 0x80000300L, 0x00000000L), HEXCONSTE(-2097152.0, 0xc014, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2492472.75, 0xc014, 0x9820e300L, 0x00000000L), HEXCONSTE(-2492472.0, 0xc014, 0x9820e000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2886220.75, 0xc014, 0xb0293300L, 0x00000000L), HEXCONSTE(-2886220.0, 0xc014, 0xb0293000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3058792.75, 0xc014, 0xbab1a300L, 0x00000000L), HEXCONSTE(-3058792.0, 0xc014, 0xbab1a000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-8388610.125, 0xc016, 0x80000220L, 0x00000000L), HEXCONSTE(-8388610.0, 0xc016, 0x80000200L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4294967296.625, 0xc01f, 0x80000000L, 0x50000000L), HEXCONSTE(-4294967296.0, 0xc01f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(70368744177664.75, 0x402d, 0x80000000L, 0x00018000L), HEXCONSTE(70368744177664.0, 0x402d, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(140737488355328.75, 0x402e, 0x80000000L, 0x0000c000L), HEXCONSTE(140737488355328.0, 0x402e, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(281474976710656.75, 0x402f, 0x80000000L, 0x00006000L), HEXCONSTE(281474976710656.0, 0x402f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(562949953421312.75, 0x4030, 0x80000000L, 0x00003000L), HEXCONSTE(562949953421312.0, 0x4030, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1125899906842624.75, 0x4031, 0x80000000L, 0x00001800L), HEXCONSTE(1125899906842624.0, 0x4031, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-70368744177664.75, 0xc02d, 0x80000000L, 0x00018000L), HEXCONSTE(-70368744177664.0, 0xc02d, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-140737488355328.75, 0xc02e, 0x80000000L, 0x0000c000L), HEXCONSTE(-140737488355328.0, 0xc02e, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-281474976710656.75, 0xc02f, 0x80000000L, 0x00006000L), HEXCONSTE(-281474976710656.0, 0xc02f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-562949953421312.75, 0xc030, 0x80000000L, 0x00003000L), HEXCONSTE(-562949953421312.0, 0xc030, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1125899906842624.75, 0xc031, 0x80000000L, 0x00001800L), HEXCONSTE(-1125899906842624.0, 0xc031, 0x80000000L, 0x00000000L), 0 },

	{ __LINE__, HEXCONSTE(8.38860800000000000000e+06, 0x4016, 0x80000000L, 0x00000000L), HEXCONSTE(8.38860800000000000000e+06, 0x4016, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.67772160000000000000e+07, 0x4017, 0x80000000L, 0x00000000L), HEXCONSTE(1.67772160000000000000e+07, 0x4017, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.35544320000000000000e+07, 0x4018, 0x80000000L, 0x00000000L), HEXCONSTE(3.35544320000000000000e+07, 0x4018, 0x80000000L, 0x00000000L), 0 },

	{ __LINE__, HEXCONSTE(4.50359962737049600000e+15, 0x4033, 0x80000000L, 0x00000000L), HEXCONSTE(4.50359962737049600000e+15, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370495.5, 0x4032, 0xffffffffL, 0xfffff800L), HEXCONSTE(4503599627370495.0, 0x4032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.25, 0x4033, 0x80000000L, 0x00000200L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.5, 0x4033, 0x80000000L, 0x00000400L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.75, 0x4033, 0x80000000L, 0x00000600L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370497.5, 0x4033, 0x80000000L, 0x00000c00L), HEXCONSTE(4503599627370497.0, 0x4033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(9.00719925474099200000e+15, 0x4034, 0x80000000L, 0x00000000L), HEXCONSTE(9.00719925474099200000e+15, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.80143985094819840000e+16, 0x4035, 0x80000000L, 0x00000000L), HEXCONSTE(1.80143985094819840000e+16, 0x4035, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927935.5, 0x4036, 0xffffffffL, 0xffffff80L), HEXCONSTE(72057594037927935.0, 0x4036, 0xffffffffL, 0xffffff00L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.25, 0x4037, 0x80000000L, 0x00000020L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.5, 0x4037, 0x80000000L, 0x00000040L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.75, 0x4037, 0x80000000L, 0x00000060L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927937.5, 0x4037, 0x80000000L, 0x000000c0L), HEXCONSTE(72057594037927937.0, 0x4037, 0x80000000L, 0x00000080L), 0 },
	{ __LINE__, HEXCONSTE(9.22337203685477580800e+18, 0x403e, 0x80000000L, 0x00000000L), HEXCONSTE(9.22337203685477580800e+18, 0x403e, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.84467440737095516160e+19, 0x403f, 0x80000000L, 0x00000000L), HEXCONSTE(1.84467440737095516160e+19, 0x403f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(3.68934881474191032320e+19, 0x4040, 0x80000000L, 0x00000000L), HEXCONSTE(3.68934881474191032320e+19, 0x4040, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4.05648192073033408479e+31, 0x4068, 0x80000000L, 0x00000000L), HEXCONSTE(4.05648192073033408479e+31, 0x4068, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(8.11296384146066816958e+31, 0x4069, 0x80000000L, 0x00000000L), HEXCONSTE(8.11296384146066816958e+31, 0x4069, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.62259276829213363392e+32, 0x406a, 0x80000000L, 0x00000000L), HEXCONSTE(1.62259276829213363392e+32, 0x406a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(5.19229685853482762853e+33, 0x406f, 0x80000000L, 0x00000000L), HEXCONSTE(5.19229685853482762853e+33, 0x406f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(1.03845937170696552571e+34, 0x4070, 0x80000000L, 0x00000000L), HEXCONSTE(1.03845937170696552571e+34, 0x4070, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(2.07691874341393105141e+34, 0x4071, 0x80000000L, 0x00000000L), HEXCONSTE(2.07691874341393105141e+34, 0x4071, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-8.38860800000000000000e+06, 0xc016, 0x80000000L, 0x00000000L), HEXCONSTE(-8.38860800000000000000e+06, 0xc016, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.67772160000000000000e+07, 0xc017, 0x80000000L, 0x00000000L), HEXCONSTE(-1.67772160000000000000e+07, 0xc017, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3.35544320000000000000e+07, 0xc018, 0x80000000L, 0x00000000L), HEXCONSTE(-3.35544320000000000000e+07, 0xc018, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.50359962737049600000e+15, 0xc033, 0x80000000L, 0x00000000L), HEXCONSTE(-4.50359962737049600000e+15, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370495.5, 0xc032, 0xffffffffL, 0xfffff800L), HEXCONSTE(-4503599627370495.0, 0xc032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.25, 0xc033, 0x80000000L, 0x00000200L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.5, 0xc033, 0x80000000L, 0x00000400L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.75, 0xc033, 0x80000000L, 0x00000600L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370497.5, 0xc033, 0x80000000L, 0x00000c00L), HEXCONSTE(-4503599627370497.0, 0xc033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740991.5, 0xc033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(-9007199254740991.0, 0xc033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.25, 0xc034, 0x80000000L, 0x00000100L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.5, 0xc034, 0x80000000L, 0x00000200L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.75, 0xc034, 0x80000000L, 0x00000300L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740993.5, 0xc034, 0x80000000L, 0x00000600L), HEXCONSTE(-9007199254740993.0, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9.00719925474099200000e+15, 0xc034, 0x80000000L, 0x00000000L), HEXCONSTE(-9.00719925474099200000e+15, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.80143985094819840000e+16, 0xc035, 0x80000000L, 0x00000000L), HEXCONSTE(-1.80143985094819840000e+16, 0xc035, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927935.5, 0xc036, 0xffffffffL, 0xffffff80L), HEXCONSTE(-72057594037927935.0, 0xc036, 0xffffffffL, 0xffffff00L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.25, 0xc037, 0x80000000L, 0x00000020L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.5, 0xc037, 0x80000000L, 0x00000040L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.75, 0xc037, 0x80000000L, 0x00000060L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927937.5, 0xc037, 0x80000000L, 0x000000c0L), HEXCONSTE(-72057594037927937.0, 0xc037, 0x80000000L, 0x00000080L), 0 },
	{ __LINE__, HEXCONSTE(-9.22337203685477580800e+18, 0xc03e, 0x80000000L, 0x00000000L), HEXCONSTE(-9.22337203685477580800e+18, 0xc03e, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.84467440737095516160e+19, 0xc03f, 0x80000000L, 0x00000000L), HEXCONSTE(-1.84467440737095516160e+19, 0xc03f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-3.68934881474191032320e+19, 0xc040, 0x80000000L, 0x00000000L), HEXCONSTE(-3.68934881474191032320e+19, 0xc040, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4.05648192073033408479e+31, 0xc068, 0x80000000L, 0x00000000L), HEXCONSTE(-4.05648192073033408479e+31, 0xc068, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-8.11296384146066816958e+31, 0xc069, 0x80000000L, 0x00000000L), HEXCONSTE(-8.11296384146066816958e+31, 0xc069, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.62259276829213363392e+32, 0xc06a, 0x80000000L, 0x00000000L), HEXCONSTE(-1.62259276829213363392e+32, 0xc06a, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-5.19229685853482762853e+33, 0xc06f, 0x80000000L, 0x00000000L), HEXCONSTE(-5.19229685853482762853e+33, 0xc06f, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.03845937170696552571e+34, 0xc070, 0x80000000L, 0x00000000L), HEXCONSTE(-1.03845937170696552571e+34, 0xc070, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2.07691874341393105141e+34, 0xc071, 0x80000000L, 0x00000000L), HEXCONSTE(-2.07691874341393105141e+34, 0xc071, 0x80000000L, 0x00000000L), 0 },
	
	{ __LINE__, HEXCONSTE(0.2, 0x3ffc, 0xccccccccL, 0xcccccccdL), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.2, 0xbffc, 0xccccccccL, 0xcccccccdL), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(0.5, 0x3ffe, 0x80000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.5, 0xbffe, 0x80000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(0.8, 0x3ffe, 0xccccccccL, 0xcccccccdL), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.8, 0xbffe, 0xccccccccL, 0xcccccccdL), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-1.5, 0xbfff, 0xc0000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(0.1, 0x3ffb, 0xccccccccL, 0xcccccccdL), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.25, 0x3ffd, 0x80000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.625, 0x3ffe, 0xa0000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.1, 0xbffb, 0xccccccccL, 0xcccccccdL), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-0.25, 0xbffd, 0x80000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(-0.625, 0xbffe, 0xa0000000L, 0x00000000L), ZERO_M, 0 },
	{ __LINE__, HEXCONSTE(2097152.5, 0x4014, 0x80000200L, 0x00000000L), HEXCONSTE(2097152, 0x4014, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-2097152.5, 0xc014, 0x80000200L, 0x00000000L), HEXCONSTE(-2097152, 0xc014, 0x80000000L, 0x00000000L), 0 },
	
	{ __LINE__, HEXCONSTE(2.81474976710655000000e+14, 0x402e, 0xffffffffL, 0xffff0000L), HEXCONSTE(2.81474976710655000000e+14, 0x402e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(2.81474976710655250000e+14, 0x402e, 0xffffffffL, 0xffff4000L), HEXCONSTE(2.81474976710655000000e+14, 0x402e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(2.81474976710655500000e+14, 0x402e, 0xffffffffL, 0xffff8000L), HEXCONSTE(2.81474976710655000000e+14, 0x402e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(2.81474976710655750000e+14, 0x402e, 0xffffffffL, 0xffffc000L), HEXCONSTE(2.81474976710655000000e+14, 0x402e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(-2.81474976710655000000e+14, 0xc02e, 0xffffffffL, 0xffff0000L), HEXCONSTE(-2.81474976710655000000e+14, 0xc02e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(-2.81474976710655250000e+14, 0xc02e, 0xffffffffL, 0xffff4000L), HEXCONSTE(-2.81474976710655000000e+14, 0xc02e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(-2.81474976710655500000e+14, 0xc02e, 0xffffffffL, 0xffff8000L), HEXCONSTE(-2.81474976710655000000e+14, 0xc02e, 0xffffffffL, 0xffff0000L), 0 },
	{ __LINE__, HEXCONSTE(-2.81474976710655750000e+14, 0xc02e, 0xffffffffL, 0xffffc000L), HEXCONSTE(-2.81474976710655000000e+14, 0xc02e, 0xffffffffL, 0xffff0000L), 0 },
	
	/* The result can only be represented in long double. */
	{ __LINE__, HEXCONSTE(4503599627370495.5, 0x4032, 0xffffffffL, 0xfffff800L), HEXCONSTE(4503599627370495.0, 0x4032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.25, 0x4033, 0x80000000L, 0x00000200L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.5, 0x4033, 0x80000000L, 0x00000400L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.75, 0x4033, 0x80000000L, 0x00000600L), HEXCONSTE(4503599627370496.0, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370497.5, 0x4033, 0x80000000L, 0x00000c00L), HEXCONSTE(4503599627370497.0, 0x4033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370495.5, 0xc032, 0xffffffffL, 0xfffff800L), HEXCONSTE(-4503599627370495.0, 0xc032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.25, 0xc033, 0x80000000L, 0x00000200L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.5, 0xc033, 0x80000000L, 0x00000400L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.75, 0xc033, 0x80000000L, 0x00000600L), HEXCONSTE(-4503599627370496.0, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370497.5, 0xc033, 0x80000000L, 0x00000c00L), HEXCONSTE(-4503599627370497.0, 0xc033, 0x80000000L, 0x00000800L), 0 },
	
	{ __LINE__, HEXCONSTE(9007199254740991.5, 0x4033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(9007199254740991.0, 0x4033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.25, 0x4034, 0x80000000L, 0x00000100L), HEXCONSTE(9007199254740992.0, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.5, 0x4034, 0x80000000L, 0x00000200L), HEXCONSTE(9007199254740992.0, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.75, 0x4034, 0x80000000L, 0x00000300L), HEXCONSTE(9007199254740992.0, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740993.5, 0x4034, 0x80000000L, 0x00000600L), HEXCONSTE(9007199254740993.0, 0x4034, 0x80000000L, 0x00000400L), 0 },
	
	{ __LINE__, HEXCONSTE(-9007199254740991.5, 0xc033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(-9007199254740991.0, 0xc033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.25, 0xc034, 0x80000000L, 0x00000100L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.5, 0xc034, 0x80000000L, 0x00000200L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.75, 0xc034, 0x80000000L, 0x00000300L), HEXCONSTE(-9007199254740992.0, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740993.5, 0xc034, 0x80000000L, 0x00000600L), HEXCONSTE(-9007199254740993.0, 0xc034, 0x80000000L, 0x00000400L), 0 },
	
	{ __LINE__, HEXCONSTE(72057594037927935.5, 0x4036, 0xffffffffL, 0xffffff80L), HEXCONSTE(72057594037927935.0, 0x4036, 0xffffffffL, 0xffffff00L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.25, 0x4037, 0x80000000L, 0x00000020L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.5, 0x4037, 0x80000000L, 0x00000040L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.75, 0x4037, 0x80000000L, 0x00000060L), HEXCONSTE(72057594037927936.0, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927937.5, 0x4037, 0x80000000L, 0x000000c0L), HEXCONSTE(72057594037927937.0, 0x4037, 0x80000000L, 0x00000080L), 0 },
	
	{ __LINE__, HEXCONSTE(-72057594037927935.5, 0xc036, 0xffffffffL, 0xffffff80L), HEXCONSTE(-72057594037927935.0, 0xc036, 0xffffffffL, 0xffffff00L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.25, 0xc037, 0x80000000L, 0x00000020L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.5, 0xc037, 0x80000000L, 0x00000040L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.75, 0xc037, 0x80000000L, 0x00000060L), HEXCONSTE(-72057594037927936.0, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927937.5, 0xc037, 0x80000000L, 0x000000c0L), HEXCONSTE(-72057594037927937.0, 0xc037, 0x80000000L, 0x00000080L), 0 },
	
	{ __LINE__, HEXCONSTE(34503599627370498.515625, 0x4035, 0xf529ae9eL, 0x86000508L), HEXCONSTE(34503599627370498.0, 0x4035, 0xf529ae9eL, 0x86000400L), 0 },
	{ __LINE__, HEXCONSTE(-34503599627370498.515625, 0xc035, 0xf529ae9eL, 0x86000508L), HEXCONSTE(-34503599627370498.0, 0xc035, 0xf529ae9eL, 0x86000400L), 0 },
	
	{ __LINE__, HEXCONSTE(10141204801825835211973625643007.5, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643007.0, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.25, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.5, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.75, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643009.5, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643009.0, 0x4066, 0x80000000L, 0x00000000L), 0 },
	
	{ __LINE__, HEXCONSTE(-8.98847e+307, 0xc3fe, 0x80000409L, 0x7954f717L), HEXCONSTE(-8.98847e+307, 0xc3fe, 0x80000409L, 0x7954f717L), 0 },
	{ __LINE__, HEXCONSTE(-4.45015e-308, 0xbc02, 0x8000044dL, 0xb01f4deeL), ZERO_M, 0 },
};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(fintrz_data, ARRAY_SIZE(fintrz_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}

#else

int main(void)
{
	return 77;
}

#endif
