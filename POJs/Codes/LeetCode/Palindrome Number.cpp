#include <gtest/gtest.h>

using namespace std;

bool isPalindrome2(int x)
{
	bool bResult = false;
	if (x < 0)
	{
		return false;
	}

	int tempData[20] = {0};
	int tempIdx = 0;
	int tempX = x;
	long long rValue = 0;
	while (tempX)
	{
		tempData[tempIdx++] = tempX % 10;
		tempX /= 10;
	}

	for (int i=0; i<tempIdx;++i)
	{
		rValue = rValue*10 +tempData[i];
	}

	return (x == rValue);
}

bool isPalindrome3(int x)
{
	if (x < 0)
		return false;

	long long nValue = 0;
	int temp = x;
	while (temp)
	{
		nValue = nValue*10 + temp % 10;
		temp /= 10;
	}

	return (x == nValue);
}

bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int dev = 1;
	while (x / dev >= 10)
	{
		dev *= 10;
	}

	while (x != 0)
	{
		int l = x / dev;
		int r = x % 10;
		if (l != r)
			return false;

		x = (x % dev) / 10;
		dev /= 100;
	}

	return true;
}

TEST(Pratices, tIsPalindrome)
{
	// 123 false
	// 121 true
	// -111 false
	// 0 true
	// 2147483647 false
	ASSERT_FALSE(isPalindrome(123));
	ASSERT_TRUE(isPalindrome(121));
	ASSERT_FALSE(isPalindrome(-111));
	ASSERT_TRUE(isPalindrome(0));
	ASSERT_FALSE(isPalindrome(2147483647));


}