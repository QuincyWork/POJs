#include <gtest/gtest.h>
using namespace std;

int trailingZeroes(int n)
{
	int count = 0;
	while (n)
	{
		n /= 5;
		count += n;
	}

	return count;
}

TEST(Pratices, tTrailingZeroes)
{
	//
	ASSERT_EQ(trailingZeroes(1),0);
	ASSERT_EQ(trailingZeroes(5),1);
	ASSERT_EQ(trailingZeroes(25),6);
	ASSERT_EQ(trailingZeroes(24),4);
}