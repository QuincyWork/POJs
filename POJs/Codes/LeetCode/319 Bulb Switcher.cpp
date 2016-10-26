#include <gtest/gtest.h>
#include <math.h>
using namespace std;


int bulbSwitch1(int n) 
{
	if (n==0)
	{
		return 0;
	}

	// 1st turn on all bulb
	vector<bool> vecBulbs(n, true);
	for (int i=2; i<=n; ++i)
	{
		for (int j=i; j<=n; j*=i)
		{
			vecBulbs[j-1] = ~vecBulbs[j-1];
		}
	}

	int result = 0;
	for (int i=0; i<vecBulbs.size(); ++i)
	{
		if (vecBulbs[i])
		{
			result ++;
		}
	}

	return result;
}

int bulbSwitch(int n) 
{
    return (int)sqrt((double)n);
}

TEST(LeetCode, tBulbSwitch)
{
	ASSERT_EQ(bulbSwitch(3),1);
}