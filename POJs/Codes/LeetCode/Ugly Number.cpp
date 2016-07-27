#include <gtest/gtest.h>
using namespace std;

bool isUgly(int num)
{
	if (num <=0)
		return false;

	while (num % 2 == 0)
		num /= 2;

	while (num % 3 == 0)
		num /= 3;

	while (num % 5 == 0)
		num /= 5;

	return (num == 1);
}

TEST(Pratices, tIsUgly)
{
	ASSERT_TRUE(isUgly(4));
	ASSERT_FALSE(isUgly(11));
	ASSERT_FALSE(isUgly(14));
}