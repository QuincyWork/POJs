#include <gtest/gtest.h>
using namespace std;

int reverse2(int x) 
{
	int result[20] = {0};
	int resultIdx = 0;
	int sign = 1;
	long long val = x;
	if (val < 0)
	{
		sign = -1;
		val = -val;
	}

	while (val)
	{
		result[resultIdx++] = val % 10;
		val /= 10;
	}

	long long newResult = 0;
	long long base = 1;
	for (int i = resultIdx-1; i >= 0; i--)
	{
		newResult += result[i] * base;
		base *= 10;
	}

	if (newResult > 0x7FFFFFFF)
	{
		newResult = 0;
	}

	newResult *= sign;

	return (int)newResult;
}

int reverse(int x) 
{
	int result[20] = {0};
	int resultIdx = 0;

	while (x)
	{
		result[resultIdx++] = x % 10;
		x /= 10;
	}

	long long newResult = 0;
	long long base = 1;
	for (int i = resultIdx-1; i >= 0; i--)
	{
		newResult += result[i] * base;
		base *= 10;
	}

	if ((newResult > 0x7FFFFFFF) || (newResult < -0x7FFFFFFF))
	{
		newResult = 0;
	}

	return (int)newResult;
}

TEST(Pratices, tReverse)
{
	// 123 -> 321
	ASSERT_EQ(reverse(123),321);
	// -123 -> -321
	ASSERT_EQ(reverse(-123),-321);
	// 0 -> 0
	ASSERT_EQ(reverse(0),0);
	// -0 -> 0
	ASSERT_EQ(reverse(-0),0);
	// 0x1FFFFFFF -> 0x7FFFFFFF
	ASSERT_EQ(reverse(-2147483648),0);
	// -0x1FFFFFFF -> -0x7FFFFFFF
	//ASSERT_EQ(reverse(-0x1FFFFFFF),-0x7FFFFFFF);
}