#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 371. Sum of Two Integers
// https://leetcode.com/problems/sum-of-two-integers/

int getSum(int a, int b) 
{
	while(b)
	{
		int carry = a & b;
		a = a ^ b;
		b = carry << 1;
	}
	
	return a;
}

TEST(LeetCode, tGetSum)
{
	ASSERT_EQ(getSum(1,2),3);
	ASSERT_EQ(getSum(25,31),56);
}