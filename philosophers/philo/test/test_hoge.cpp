#include "gtest/gtest.h"

extern "C"
{
	#include "../philosophers.h"
}

extern "C" int increment(int i);

TEST(foo, testOfFoo)
{
	EXPECT_EQ(1, increment(0));
	EXPECT_EQ(2, increment(1));
}