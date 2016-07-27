#include <gtest/gtest.h>
using namespace std;

int addDigits(int num)
{
	int nResult = 0;
	while (num)
	{
		nResult += num % 10;
		if (nResult >= 10)
		{
			nResult %= 10;
			nResult ++;
		}

		num /= 10;
	}

	return nResult;
}

TEST(Pratices, tAddDigits)
{
	ASSERT_EQ(addDigits(38),2);
	ASSERT_EQ(addDigits(4382),8);
}