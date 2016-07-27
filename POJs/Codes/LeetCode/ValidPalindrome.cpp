#include <gtest/gtest.h>
using namespace std;

int getAlphaNumeric(int data)
{
	int n = 0;
	if (isdigit(data) || isalpha(data))
	{
		n = data;
	}

	return n;
}

bool isPalindrome(string s) 
{
	if (s.empty())
		return true;

	const int length = s.length();
	int r = 0;
	int l = length -1;

	while (l>r)
	{
		int rVal = getAlphaNumeric(s[r++]);
		while (!rVal && r<=l)
			rVal = getAlphaNumeric(s[r++]);

		int lVal = getAlphaNumeric(s[l--]);
		while (!lVal && r<=l)
			lVal = getAlphaNumeric(s[l--]);

		if (rVal && lVal)
		{
			if (toupper(rVal) != toupper(lVal))
				return false;
		}
	}

	return true;
}

TEST(Pratices,tIsPalindrome)
{
	// A man, a plan, a canal: Panama
	ASSERT_TRUE(isPalindrome("A man, a plan, a canal: Panama"));
	ASSERT_FALSE(isPalindrome("race a car"));
	ASSERT_TRUE(isPalindrome(" , , , , , ,"));
	ASSERT_TRUE(isPalindrome(" , , , , , ,A"));
	ASSERT_TRUE(isPalindrome(" , , , A, , ,A"));
	ASSERT_TRUE(isPalindrome(" A"));
	ASSERT_FALSE(isPalindrome("b      A       b A"));
	ASSERT_TRUE(isPalindrome("123aba , ,3, 2, 1  "));
}