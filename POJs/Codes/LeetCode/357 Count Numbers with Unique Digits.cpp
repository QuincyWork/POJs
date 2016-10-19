#include <gtest/gtest.h>
using namespace std;

// 采用一个数组记录[0-9]是否已经有
// 通过动态规划方式来实现
// 注意：01 02 03等这种数字需要排除

void countSubNumbers(int size, int index, int& count, vector<bool>& flags)
{
	if (index >= size)
	{
		return;
	}

	for (int i=0; i<=9; ++i)
	{
		if (flags[i])
		{
			continue;
		}
		
		if ((i != 0) || (index == 0))
		{
			count++;
		}

		flags[i] = true;
		countSubNumbers(size, index+1, count, flags);
		flags[i] = false;
	}
}

int countNumbersWithUniqueDigits(int n) 
{
	if (!n)
	{
		return 1;
	}

	vector<bool> flags(10,false);
	int result = 0;
	countSubNumbers(n,0,result,flags);
	return result;
}

TEST(LeetCode, tCountNumbersWithUniqueDigits)
{
	ASSERT_EQ(countNumbersWithUniqueDigits(2),91);
}