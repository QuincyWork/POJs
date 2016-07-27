#include <gtest\gtest.h>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
	int v[32] = { 0 };
	int index = 0;
	while (n)
	{
		v[index++] = n % 2;
		n /= 2;
	}

	long long result = 0;
	int base = 1;
	index = 31;
	while (index >= 0)
	{
		result += v[index--] * base;
		base *= 2;
	}

	return result;
}

TEST(Pratices, tReverseBits)
{
	//43261596 => 964176192 
	ASSERT_EQ(reverseBits(43261596), 964176192);
	ASSERT_EQ(reverseBits(0), 0);
}