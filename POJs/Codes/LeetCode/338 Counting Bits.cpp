#include <gtest/gtest.h>
using namespace std;

 vector<int> countBits1(int num)
 {
	vector<int> results;
	for (int i=0; i<= num; i++)
	{
		int count = 0;	
		int value = i;
		while (value)
		{
			if (value & 1)
			{
				count++;
			}

			value = value >> 1;
		}

		results.push_back(count);
	}

	return results;
 }

 // ������λ���㣺
 // ����ʽ��ans[n] = ans[n >> 1] + (n & 1)
 vector<int> countBits(int num)
 {
	vector<int> counts;
	counts.assign(num+1,0);

	for (int i=0; i<=num; ++i)
	{
		if (i % 2)
		{
			counts[i] = counts[i>>1] + 1;
		}
		else
		{
			counts[i] = counts[i>>1];
		}
	}

	return counts;
 }

// ����highbits���㣺
// ����ʽ��ans[n] = ans[n - highbits(n)] + 1
// ���� highbits(n) ��ʾֻ����n�����λ�õ������֡�


 TEST(LeetCode, tCountBits)
 {
	 // 5 ->
	 vector<int> result = countBits(5);
	 result = countBits(6);
 }