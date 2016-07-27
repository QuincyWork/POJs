#include <gtest\gtest.h>
using namespace std;


// Eratosthenes筛选求质数
int countPrimes(int n)
{
	vector<bool> data(n,true);
	data[0] = data[1] = false;

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (data[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				data[j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 2; i < n; ++i)
	{
		if (data[i])
			count++;
	}

	return count;
}

TEST(Pratices, tCountPrimes)
{
	ASSERT_EQ(countPrimes(19), 4);
}