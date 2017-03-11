#include <gtest/gtest.h>
using namespace std;

double myPow1(double x, int n)
{
	double result = 1;
	bool sign = false;
	if (n < 0)
	{
		sign = true;
		n = -n;
	}

	while(--n >= 0)
	{
		result *= x;
	}

	if (sign)
	{
		result = 1 / result;
	}

	return result;
}

double myPow(double x, int n)
{
	if (n==0)
	{
		return 1;
	}

	if (n < 0)
	{
		x = 1/x;
		if (n == 0x80000000)
		{
			n = 0x7FFFFFFF;
			x *= x;
		}
		else
		{
			n = -n;
		}
	}

	return (n % 2==0) ? myPow(x*x,n/2) : x* myPow(x*x,n/2);
}

TEST(LeetCode, tMyPow)
{
	ASSERT_DOUBLE_EQ(myPow(8.88023,3),700.281482945268167);
	ASSERT_DOUBLE_EQ(myPow(34.00515,-3),0.00003);
	ASSERT_DOUBLE_EQ(myPow(2.00000,-2147483648),0.00000);
}