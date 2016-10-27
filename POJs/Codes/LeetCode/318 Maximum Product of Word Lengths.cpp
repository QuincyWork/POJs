#include <gtest/gtest.h>
using namespace std;

int convert(const string& val)
{	
	int result = 0;
	for (int i=0; i<val.length();++i)
	{
		result |= (1 << (val[i]-'a'));
	}

	return result;
}

int maxProduct(vector<string>& words) 
{
	vector<pair<int,int>> wordtbl;
	for (int i=0; i<words.size();++i)
	{
		wordtbl.push_back(make_pair(words[i].length(), convert(words[i])));
	}

	int result = 0;
	for (int i=0; i<wordtbl.size(); ++i)
	{
		for (int j=i+1; j<wordtbl.size();++j)
		{
			if (wordtbl[i].second & wordtbl[j].second)
			{
				continue;
			}

			int val = wordtbl[i].first * wordtbl[j].first;
			if (result < val)
			{
				result = val;
			}
		}
	}

	return result;
}

TEST(LeetCode,tMaxProduct)
{
	string s1[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	vector<string> v1(s1,s1+_countof(s1));
	ASSERT_EQ(maxProduct(v1),16);

	string s2[] = {"a", "aa", "aaa", "aaaa"};
	vector<string> v2(s2,s2+_countof(s2));
	ASSERT_EQ(maxProduct(v2),0);
}