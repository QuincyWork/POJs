#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

bool isAnagram1(string s, string t) 
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	return (s==t);
}

bool isAnagram(string s, string t) 
{
	int counts[26] = {0};
	for (int i=0; i<s.length(); ++i)
	{
		counts[s[i]-'a']++;
	}

	for (int i=0; i<t.length(); ++i)
	{
		counts[t[i]-'a']--;
	}

	for (int i=0; i<26; ++i)
	{
		if (counts[i] != 0)
			return false;
	}

	return true;
}

TEST(Pratices, tIsAnagram)
{
	ASSERT_TRUE(isAnagram1("anagram","nagaram"));
	ASSERT_TRUE(isAnagram("anagram","nagaram"));
	ASSERT_FALSE(isAnagram1("rat","car"));
	ASSERT_FALSE(isAnagram("rat","car"));
}