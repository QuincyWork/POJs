#include <gtest\gtest.h>
using namespace std;


int hammingWeight(uint32_t n)
{
	int result = 0;
	while (n)
	{
		result += n % 2;
		n /= 2;
	}

	return result;
}

TEST(Pratices, tHammingWeight)
{
	ASSERT_EQ(hammingWeight(100), 3);
	ASSERT_EQ(hammingWeight(0), 0);
	ASSERT_EQ(hammingWeight(0xFFFFFFFF), 32);
}