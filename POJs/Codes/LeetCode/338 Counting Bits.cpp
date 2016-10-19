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

 // 利用移位运算：
 // 递推式：ans[n] = ans[n >> 1] + (n & 1)
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

// 利用highbits运算：
// 递推式：ans[n] = ans[n - highbits(n)] + 1
// 其中 highbits(n) 表示只保留n的最高位得到的数字。


 TEST(LeetCode, tCountBits)
 {
	 // 5 ->
	 vector<int> result = countBits(5);
	 result = countBits(6);
 }