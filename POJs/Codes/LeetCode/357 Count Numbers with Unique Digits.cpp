#include <gtest/gtest.h>
using namespace std;

// ����һ�������¼[0-9]�Ƿ��Ѿ���
// ͨ����̬�滮��ʽ��ʵ��
// ע�⣺01 02 03������������Ҫ�ų�

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