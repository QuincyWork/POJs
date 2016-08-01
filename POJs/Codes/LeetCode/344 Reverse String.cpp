#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

string reverseString(string s)
{
	return string(s.rbegin(), s.rend());
}

TEST(LeetCode, tReverseString)
{
	ASSERT_EQ(reverseString("hello"), "olleh");
	ASSERT_EQ(reverseString("h"), "h");
	ASSERT_EQ(reverseString(""), "");
}