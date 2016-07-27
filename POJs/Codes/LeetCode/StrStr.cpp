#include <gtest/gtest.h>
using namespace std;

int strStr(string haystack, string needle)
{
	int index = -1;
	const int n = haystack.length();
	const int m = needle.length();
	if (n < m)
		return -1;

	for (int i=0; i<=n-m; ++i)
	{
		int j = 0;
		for (; j<m; ++j)
		{
			if (haystack[i+j] != needle[j])
			{
				break;
			}
		}

		if (j==m)
		{
			index = i;
			break;
		}
	}

	return index;
}

TEST(Pratices, tStrStr)
{
	// 12345678 123 =>0
	ASSERT_EQ(strStr("12345678","123"),0);
	ASSERT_EQ(strStr("12345678","231"),-1);
	ASSERT_EQ(strStr("123","123"),0);
	ASSERT_EQ(strStr("123","1234"),-1);
	ASSERT_EQ(strStr("11123412341234","1234"),2);
}