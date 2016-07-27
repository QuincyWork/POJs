#include <gtest/gtest.h>
using namespace std;

int lengthOfLastWord(string s)
{
	const int n = s.length();
	int last = -1;
	for (int i = n-1; i>=0; --i)
	{
		char v = s[i];
		if (v == ' ')
		{
			if (last != -1)
			{
				return last-i;
			}
		}
		else
		{
			if (last == -1)
			{
				last = i;
			}
		}
	}

	return last+1;
}

TEST(Pratices, tLengthOfLastWord)
{
	// Hello_World
	ASSERT_EQ(lengthOfLastWord("Hello World"),5);
	// _
	ASSERT_EQ(lengthOfLastWord(""),0);
	ASSERT_EQ(lengthOfLastWord("  "),0);
	// 123_123_
	ASSERT_EQ(lengthOfLastWord("123 123  "),3);
	ASSERT_EQ(lengthOfLastWord("123"),3);
	ASSERT_EQ(lengthOfLastWord(" 123"),3);
}