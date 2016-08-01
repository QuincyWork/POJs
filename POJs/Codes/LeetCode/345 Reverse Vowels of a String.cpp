#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 345. Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string/

bool isVowel(char c)
{
	return ((c=='a') || (c=='A') || 
		    (c=='e') || (c=='E') || 
			(c=='i') || (c=='I') || 
			(c=='o') || (c=='O') ||
			(c=='u') || (c=='U'));
}

string reverseVowels(string s)
{
	int r = 0;
	int l = s.length()-1;

	while (r<l)
	{
		// Get Right vowel
		while ((r<l) && !isVowel(s[r]))
			++r;

		// Get Left vowel
		while ((r<l) && !isVowel(s[l]))
			--l;

		if (r < l)
		{
			char temp = s[r];
			s[r] = s[l];
			s[l] = temp;

			++r;
			--l;
		}
	}

	return s;
}

TEST(LeetCode, tReverseVowels)
{
	ASSERT_EQ(reverseVowels("hllll"),"hllll");
	ASSERT_EQ(reverseVowels("hlllo"),"hlllo");
	ASSERT_EQ(reverseVowels("hello"),"holle");
	ASSERT_EQ(reverseVowels("leetcode"),"leotcede");
}
