#include <gtest/gtest.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// LeetCode
// 290. Move Zeroes
// https://leetcode.com/problems/word-pattern/

bool wordPattern(string pattern, string str)
{
	bool bResult = true;
	unordered_map<char, string> tblKeyMapping;
	unordered_set<string> setValues;
	for (size_t i = 0; i<pattern.size(); ++i)
	{
		string::size_type pos = str.find(' ');
		string strToken = str.substr(0, pos);
		if (strToken.empty())
		{
			bResult = false;
			break;
		}

		if (pos != string::npos)
		{
			str = str.substr(pos+1);
		}
		else
		{
			str.clear();
		}

		char cValue = pattern[i];
		unordered_map<char, string>::const_iterator it = tblKeyMapping.find(cValue);
		if (it != tblKeyMapping.end())
		{
			if (it->second != strToken)
			{
				bResult = false;
				break;
			}
		}
		else
		{
			if (setValues.find(strToken) != setValues.end())
			{
				bResult = false;
				break;
			}

			tblKeyMapping.insert(make_pair(cValue, strToken));
			setValues.insert(strToken);
		}
	}

	if (bResult)
	{
		bResult = str.empty();
	}

	return bResult;
}

TEST(LeetCode, tWordPattern)
{
	ASSERT_TRUE(wordPattern("abba","dog cat cat dog"));
	ASSERT_FALSE(wordPattern("abba","dog cat cat fish"));
	ASSERT_FALSE(wordPattern("aaaa", "dog cat cat dog"));
	ASSERT_FALSE(wordPattern("aaaa", "dog cat cat dog"));
}