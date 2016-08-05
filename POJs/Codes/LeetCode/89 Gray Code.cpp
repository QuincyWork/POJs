#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 89. Gray Code
// https://leetcode.com/problems/gray-code/

vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);
	for (int i=0; i<n; ++i)
	{
		int value = 1 << i;
		for (int k = value-1; k >=0; k--)
		{
			result.push_back(value+result[k]);
		}
	}

	return result;
}

// 二进制码->格雷码（编码）：
// 从最右边一位起，依次将每一位与左边一位异或（XOR），作为对应格雷码该位的值，最左边一位不变（相当于左边是0）；

// 格雷码->二进制码（解码）：
// 从左边第二位起，将每位与左边一位解码后的值异或，作为该位解码后的值（最左边一位依然不变）。

vector<int> grayCode1(int n)
{
	vector<int> result;
	int count = 1 << n;
	for (int i=0; i< count; ++i)
	{
		result.push_back((i >> 1) ^ i);
	}

	return result;
}

TEST(LeetCode, tGrayCode)
{
	// 2
	vector<int> result = grayCode1(2);
	result  = grayCode1(4);
}