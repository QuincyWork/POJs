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

// ��������->�����루���룩��
// �����ұ�һλ�����ν�ÿһλ�����һλ���XOR������Ϊ��Ӧ�������λ��ֵ�������һλ���䣨�൱�������0����

// ������->�������루���룩��
// ����ߵڶ�λ�𣬽�ÿλ�����һλ������ֵ�����Ϊ��λ������ֵ�������һλ��Ȼ���䣩��

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