#include <gtest/gtest.h>

using namespace std;

int lengthOfLongestSubstring1(string s) 
{
	int length = s.length();
	int cache[260] = {0};
	int beginMax = 0;
	int lengthMax = 0;
	int j=0;

	for (int i = 0; i < length; ++i)
	{
		memset(cache,0,sizeof(cache));
		cache[s[i]] = 1;

		for (j = i+1; j < length; ++j)
		{
			if (cache[s[j]]) //exists
			{
				break;
			}
			else
			{
				cache[s[j]] = 1;
			}
		}

		if (j-i > lengthMax)
		{
			lengthMax = j-i;
			beginMax = i;
		}
	}

	return lengthMax;
}


int lengthOfLongestSubstring(string s) 
{
	int length = s.length();
	int cache[260] = {0};
	int beginMax = 0;
	int lengthMax = 0;
	int j=0;

	for (int i = 0; i < length; ++i)
	{
		memset(cache,0,sizeof(cache));
		cache[s[i]] = 1;

		for (j = i+1; j < length; ++j)
		{
			if (cache[s[j]]) //exists
			{
				break;
			}
			else
			{
				cache[s[j]] = 1;
			}
		}

		cache[s[i]] = 0;

		if (j-i > lengthMax)
		{
			lengthMax = j-i;
			beginMax = i;
		}
	}

	return lengthMax;
}

TEST(Pratices, tLengthOfLongestSubstring)
{
	// abcabcbb  = > abc
	// a => a
	// aa => a
	// Empty => Empty

	// abcabcabc => abc
	
	ASSERT_EQ(lengthOfLongestSubstring("abc\x61hbcbb"),3);
	ASSERT_EQ(lengthOfLongestSubstring("a"),1);
	ASSERT_EQ(lengthOfLongestSubstring("aa"),1);
	ASSERT_EQ(lengthOfLongestSubstring(""),0);
	ASSERT_EQ(lengthOfLongestSubstring("abcabcabc"),3);
}