#include <gtest\gtest.h>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	map<string,vector<string>> mapValues;
	for (int i = 0; i < strs.size(); ++i)
	{
		string value = strs[i];
		sort(value.begin(), value.end());
		mapValues[value].push_back(strs[i]);
	}

	vector<vector<string>> result;
	for (map<string, vector<string>>::const_iterator it = mapValues.begin();
		it != mapValues.end();
		++it)
	{
		result.push_back(it->second);
	}

	return result;
}

TEST(LeetCode, tGroupAnagrams)
{
	string d1[] = { "eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> v1(d1,d1+_countof(d1));

	vector<vector<string>> result = groupAnagrams(v1);
}