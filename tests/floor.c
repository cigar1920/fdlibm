#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(floor)
#include "testdriver.h"



static test_f_f_data const floor_data[] = {
	{ __LINE__, ZERO_P, ZERO_P, 0 },
	{ __LINE__, ZERO_M, ZERO_M, FLAG_FAIL_ARANYM2 },
	{ __LINE__, INF_P, INF_P, 0 },
	{ __LINE__, INF_M, INF_M, 0 },
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },

	{ __LINE__, HEXCONST_PI, HEXCONSTE(3.0, 0x4000, 0xc0000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONST_PI_M, HEXCONSTE(-4.0, 0xc001, 0x80000000L, 0x00000000L), 0 },

	{ __LINE__, HEXCONSTE(0.1, 0x3ffb, 0xccccccccL, 0xcccccccdL), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.25, 0x3ffd, 0x80000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(0.625, 0x3ffe, 0xa0000000L, 0x00000000L), ZERO_P, 0 },
	{ __LINE__, HEXCONSTE(-0.1, 0xbffb, 0xccccccccL, 0xcccccccdL), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-0.25, 0xbffd, 0x80000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-0.625, 0xbffe, 0xa0000000L, 0x00000000L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-0.942695, 0xbffe, 0xf15475a3L, 0x1a4bdba1L), HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), 0 },
	
#ifdef TEST_LDOUBLE
	/* The result can only be represented in long double.  */
	{ __LINE__, HEXCONSTE(4503599627370495.5L, 0x4032, 0xffffffffL, 0xfffff800L), HEXCONSTE(4503599627370495.0L, 0x4032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.25L, 0x4033, 0x80000000L, 0x00000200L), HEXCONSTE(4503599627370496.0L, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.5L, 0x4033, 0x80000000L, 0x00000400L), HEXCONSTE(4503599627370496.0L, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.75L, 0x4033, 0x80000000L, 0x00000600L), HEXCONSTE(4503599627370496.0L, 0x4033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370497.5L, 0x4033, 0x80000000L, 0x00000c00L), HEXCONSTE(4503599627370497.0L, 0x4033, 0x80000000L, 0x00000800L), 0 },
# if LDBL_MANT_DIG > 100
	{ __LINE__, HEXCONSTE(4503599627370494.5000000000001L, 0x4032, 0xffffffffL, 0xffffe800L), HEXCONSTE(4503599627370494.0L, 0x4032, 0xffffffffL, 0xffffe000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370495.5000000000001L, 0x4032, 0xffffffffL, 0xfffff800L), HEXCONSTE(4503599627370495.0L, 0x4032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(4503599627370496.5000000000001L, 0x4033, 0x80000000L, 0x00000400L), HEXCONSTE(4503599627370496.0L, 0x4033, 0x80000000L, 0x00000000L), 0 },
# endif

	{ __LINE__, HEXCONSTE(-4503599627370495.5L, 0xc032, 0xffffffffL, 0xfffff800L), HEXCONSTE(-4503599627370496.0L, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.25L, 0xc033, 0x80000000L, 0x00000200L), HEXCONSTE(-4503599627370497.0L, 0xc033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.5L, 0xc033, 0x80000000L, 0x00000400L), HEXCONSTE(-4503599627370497.0L, 0xc033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.75L, 0xc033, 0x80000000L, 0x00000600L), HEXCONSTE(-4503599627370497.0L, 0xc033, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370497.5L, 0xc033, 0x80000000L, 0x00000c00L), HEXCONSTE(-4503599627370498.0L, 0xc033, 0x80000000L, 0x00001000L), 0 },
# if LDBL_MANT_DIG > 100
	{ __LINE__, HEXCONSTE(-4503599627370494.5000000000001L, 0xc032, 0xffffffffL, 0xffffe800L), HEXCONSTE(-4503599627370495.0L, 0xc032, 0xffffffffL, 0xfffff000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370495.5000000000001L, 0xc032, 0xffffffffL, 0xfffff800L), HEXCONSTE(-4503599627370496.0L, 0xc033, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-4503599627370496.5000000000001L, 0xc033, 0x80000000L, 0x00000400L), HEXCONSTE(-4503599627370497.0L, 0xc033, 0x80000000L, 0x00000800L), 0 },
# endif

	{ __LINE__, HEXCONSTE(9007199254740991.5L, 0x4033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(9007199254740991.0L, 0x4033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.25L, 0x4034, 0x80000000L, 0x00000100L), HEXCONSTE(9007199254740992.0L, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.5L, 0x4034, 0x80000000L, 0x00000200L), HEXCONSTE(9007199254740992.0L, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.75L, 0x4034, 0x80000000L, 0x00000300L), HEXCONSTE(9007199254740992.0L, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740993.5L, 0x4034, 0x80000000L, 0x00000600L), HEXCONSTE(9007199254740993.0L, 0x4034, 0x80000000L, 0x00000400L), 0 },

# if LDBL_MANT_DIG > 100
	{ __LINE__, HEXCONSTE(9007199254740991.0000000000001L, 0x4033, 0xffffffffL, 0xfffff800L), HEXCONSTE(9007199254740991.0L, 0x4033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.0000000000001L, 0x4034, 0x80000000L, 0x00000000L), HEXCONSTE(9007199254740992.0L, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740993.0000000000001L, 0x4034, 0x80000000L, 0x00000400L), HEXCONSTE(9007199254740993.0L, 0x4034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740991.5000000000001L, 0x4033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(9007199254740991.0L, 0x4033, 0xffffffffL, 0xfffff800L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740992.5000000000001L, 0x4034, 0x80000000L, 0x00000200L), HEXCONSTE(9007199254740992.0L, 0x4034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(9007199254740993.5000000000001L, 0x4034, 0x80000000L, 0x00000600L), HEXCONSTE(9007199254740993.0L, 0x4034, 0x80000000L, 0x00000400L), 0 },
# endif

	{ __LINE__, HEXCONSTE(-9007199254740991.5L, 0xc033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(-9007199254740992.0L, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.25L, 0xc034, 0x80000000L, 0x00000100L), HEXCONSTE(-9007199254740993.0L, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.5L, 0xc034, 0x80000000L, 0x00000200L), HEXCONSTE(-9007199254740993.0L, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.75L, 0xc034, 0x80000000L, 0x00000300L), HEXCONSTE(-9007199254740993.0L, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740993.5L, 0xc034, 0x80000000L, 0x00000600L), HEXCONSTE(-9007199254740994.0L, 0xc034, 0x80000000L, 0x00000800L), 0 },

# if LDBL_MANT_DIG > 100
	{ __LINE__, HEXCONSTE(-9007199254740991.0000000000001L, 0xc033, 0xffffffffL, 0xfffff800L), HEXCONSTE(-9007199254740992.0L, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.0000000000001L, 0xc034, 0x80000000L, 0x00000000L), HEXCONSTE(-9007199254740993.0L, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740993.0000000000001L, 0xc034, 0x80000000L, 0x00000400L), HEXCONSTE(-9007199254740994.0L, 0xc034, 0x80000000L, 0x00000800L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740991.5000000000001L, 0xc033, 0xffffffffL, 0xfffffc00L), HEXCONSTE(-9007199254740992.0L, 0xc034, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740992.5000000000001L, 0xc034, 0x80000000L, 0x00000200L), HEXCONSTE(-9007199254740993.0L, 0xc034, 0x80000000L, 0x00000400L), 0 },
	{ __LINE__, HEXCONSTE(-9007199254740993.5000000000001L, 0xc034, 0x80000000L, 0x00000600L), HEXCONSTE(-9007199254740994.0L, 0xc034, 0x80000000L, 0x00000800L), 0 },
# endif

	{ __LINE__, HEXCONSTE(72057594037927935.5L, 0x4036, 0xffffffffL, 0xffffff80L), HEXCONSTE(72057594037927935.0L, 0x4036, 0xffffffffL, 0xffffff00L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.25L, 0x4037, 0x80000000L, 0x00000020L), HEXCONSTE(72057594037927936.0L, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.5L, 0x4037, 0x80000000L, 0x00000040L), HEXCONSTE(72057594037927936.0L, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927936.75L, 0x4037, 0x80000000L, 0x00000060L), HEXCONSTE(72057594037927936.0L, 0x4037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(72057594037927937.5L, 0x4037, 0x80000000L, 0x000000c0L), HEXCONSTE(72057594037927937.0L, 0x4037, 0x80000000L, 0x00000080L), 0 },

	{ __LINE__, HEXCONSTE(-72057594037927935.5L, 0xc036, 0xffffffffL, 0xffffff80L), HEXCONSTE(-72057594037927936.0L, 0xc037, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.25L, 0xc037, 0x80000000L, 0x00000020L), HEXCONSTE(-72057594037927937.0L, 0xc037, 0x80000000L, 0x00000080L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.5L, 0xc037, 0x80000000L, 0x00000040L), HEXCONSTE(-72057594037927937.0L, 0xc037, 0x80000000L, 0x00000080L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927936.75L, 0xc037, 0x80000000L, 0x00000060L), HEXCONSTE(-72057594037927937.0L, 0xc037, 0x80000000L, 0x00000080L), 0 },
	{ __LINE__, HEXCONSTE(-72057594037927937.5L, 0xc037, 0x80000000L, 0x000000c0L), HEXCONSTE(-72057594037927938.0L, 0xc037, 0x80000000L, 0x00000100L), 0 },

	{ __LINE__, HEXCONSTE(10141204801825835211973625643007.5L, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643007.0L, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.25L, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0L, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.5L, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0L, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643008.75L, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643008.0L, 0x4066, 0x80000000L, 0x00000000L), 0 },
	{ __LINE__, HEXCONSTE(10141204801825835211973625643009.5L, 0x4066, 0x80000000L, 0x00000000L), HEXCONSTE(10141204801825835211973625643009.0L, 0x4066, 0x80000000L, 0x00000000L), 0 },

	{ __LINE__, HEXCONSTE(2.25179981368524799902e+15, 0x4031, 0xffffffffL, 0xfffffff8L), HEXCONSTE(2.25179981368524700000e+15, 0x4031, 0xffffffffL, 0xffffe000L), 0 },
	{ __LINE__, HEXCONSTE(-2.25179981368524800098e+15, 0xc032, 0x80000000L, 0x00000004L), HEXCONSTE(-2.25179981368524900000e+15, 0xc032, 0x80000000L, 0x00001000L), 0 },
#endif
};

int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(floor_data, ARRAY_SIZE(floor_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
