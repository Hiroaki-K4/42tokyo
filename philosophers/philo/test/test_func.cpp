#include "gtest/gtest.h"

extern "C"
{
	#include "../philosophers.h"
}

extern "C" int	ft_atoi(const char *nptr);

TEST(ft_atoi_test, word_int)
{
	EXPECT_EQ(0, ft_atoi("0"));
	EXPECT_EQ(0, ft_atoi("aaaa"));
	EXPECT_EQ(0, ft_atoi("-+--"));
	EXPECT_EQ(2323, ft_atoi("2323"));
	EXPECT_EQ(-232, ft_atoi("-232"));
}