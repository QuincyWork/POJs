#include <gtest/gtest.h>
using namespace std;

int mySqrt(int x)
{
	if (x==0)
		return 0;

	int result = 0;
	int l = 1;
	int r = x;
	while (r >= l)
	{
		int m = l + (r-l)/2;		
		if (m == x/m)
		{
			result = m;
			break;
		}
		else if (m < x/m)
		{
			result = m;
			l = m+1;
		}
		else
		{
			r = m-1;
		}
	}

	return result;
}

TEST(LeetCode, tMySqrt)
{
	ASSERT_EQ(mySqrt(0),0);
	ASSERT_EQ(mySqrt(1),1);
	ASSERT_EQ(mySqrt(2),1);
	ASSERT_EQ(mySqrt(3),1);
	ASSERT_EQ(mySqrt(4),2);
	ASSERT_EQ(mySqrt(12312312),3508);
}