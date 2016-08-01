#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

bool isPowerOfFour(int num)
{
	// ��2�ĳ˻������Ҽ�һ�ܱ�3����
	return (!(num & (num-1)) && ((num-1) % 3 == 0));
}


TEST(LeetCode, tIsPowerOfFour)
{
	ASSERT_TRUE(isPowerOfFour(4));
	ASSERT_FALSE(isPowerOfFour(5));
	ASSERT_TRUE(isPowerOfFour(16));
	ASSERT_TRUE(isPowerOfFour(1073741824));
}