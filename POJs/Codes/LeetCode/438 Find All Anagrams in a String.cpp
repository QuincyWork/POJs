#include <gtest\gtest.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
	vector<int> result;
	if (p.size() > s.size() ||
		s.empty())
	{
		return result;
	}

	int hash[26] = { 0 };
	for (int i = 0; i < p.size(); ++i)
	{
		hash[p[i]-'a']++;
	}

	
	for (int i = 0; i <= s.size() - p.size(); ++i)
	{
		int v[26];
		memcpy(v, hash, sizeof(v));
		bool find = true;

		for (int j = 0; j < p.size(); ++j)
		{
			if (v[s[i+j]-'a']-- <= 0)
			{
				find = false;
				break;
			}
		}

		if (find)
		{
			result.push_back(i);
		}
	}

	return result;
}

TEST(LeetCode, tFindAnagrams)
{
	// abab ab => 0,1,2
	vector<int> result = findAnagrams("abab", "ab");
	// cbaebabacd abc => 0,6
	result = findAnagrams("cbaebabacd", "abc");
}