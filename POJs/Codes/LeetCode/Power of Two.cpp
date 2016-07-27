#include <gtest/gtest.h>
using namespace std;

bool isPowerOfTwo(int n)
{
	if (n <= 0)
		return false;

	return !((n) & (n-1));
}

TEST(Pratices, tIsPowerOfTwo)
{
	ASSERT_TRUE(isPowerOfTwo(4));
	ASSERT_TRUE(isPowerOfTwo(8));
	ASSERT_TRUE(isPowerOfTwo(16));
	ASSERT_FALSE(isPowerOfTwo(18));
	ASSERT_FALSE(isPowerOfTwo(20));
	ASSERT_FALSE(isPowerOfTwo(0));
}