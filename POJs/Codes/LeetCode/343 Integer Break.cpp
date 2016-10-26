#include<gtest/gtest.h>
using namespace std;

// 2 => 1*1 => 1
// 3 => 2*1 => 2
// 4 => 2*2 => 4
// 5 => 3*2 => 6
// 6 => 3*3 => 9
// 7 => 3*4 => 12
// 8 => 3*3*2 => 18
// 9 => 3*3*3 => 27

int integerBreak(int n) 
{
	if (n == 2 || n == 3)
		return n-1;

	int result = 1;
	while (n > 4)
	{
		result *= 3;
		n -= 3;
	}

	return result * n;
}

TEST(LeetCode, tIntegerBreak)
{
	ASSERT_EQ(integerBreak(6),9);
	ASSERT_EQ(integerBreak(9),27);
}