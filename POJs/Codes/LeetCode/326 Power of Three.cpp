#include <gtest/gtest.h>
#include <math.h>
using namespace std;

// LeetCode
// 326. Power of Three
// https://leetcode.com/problems/power-of-three/

bool isPowerOfThree(int n)
{
	return ((n > 0) && (1162261467 % n == 0));
}

bool isPowerOfThree1(int n)
{
	return (n > 0 && int(log10((double)n) / log10((double)3)) - log10((double)n) / log10((double)3) == 0);
}

TEST(LeetCode, tIsPowerOfThree)
{
	ASSERT_FALSE(isPowerOfThree(345));
	ASSERT_TRUE(isPowerOfThree(27));
}