#include <gtest/gtest.h>
using namespace std;

string longestCommonPrefix1(vector<string>& strs) 
{	
	int nMinLength = std::numeric_limits<int>::max();
	int nLength = strs.size();
	if (nLength == 0)
	{
		return "";
	}

	for (int i=0; i < nLength; ++i)
	{
		if (strs[i].length() < nMinLength)
		{
			nMinLength = strs[i].length();
		}
	}

	int nLCPLength = 0;
	for (int i=0; i < nMinLength; ++i)
	{
		int temp = strs[0][i];
		bool match = true;
		for (int j=1; j < nLength; ++j)		
		{
			if (temp != strs[j][i])
			{
				match = false;
				break;
			}
		}

		if (!match)
		{
			break;
		}

		nLCPLength++;
	}

	string strResult;
	if (nLCPLength > 0)
	{
		strResult = strs[0].substr(0,nLCPLength);
	}

	return strResult;
}

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 0)
	{
		return "";
	}

	for (int i=0; i<strs[0].length(); ++i)
	{
		for (int j=1; j<strs.size(); ++j)
		{
			if ((i >= strs[j].length()) || (strs[0][i] != strs[j][i]))
			{
				return strs[0].substr(0,i);
			}
		}
	}

	return strs[0];
}

TEST(Pratices, tLongestCommonPrefix)
{
	//123124444
	//12355233
	//12

	vector<string> data;
	data.push_back("123124444");
	data.push_back("12355233");
	data.push_back("12");

	ASSERT_EQ(longestCommonPrefix(data), "12");

	data.clear();
	ASSERT_EQ(longestCommonPrefix(data), "");
}