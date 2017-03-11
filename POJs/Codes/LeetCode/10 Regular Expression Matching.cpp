#include <gtest/gtest.h>
using namespace std;

bool isMatch(string s, string p, int sbegin, int pbegin)
{
	if (s.length() == sbegin ||
		p.length() == pbegin)
	{
		while((pbegin < p.length()) && (p[pbegin++] == '*'));

		return (p.length() == pbegin) && (s.length() == sbegin);
	}

	char sVal = s[sbegin];
	char pVal = p[pbegin];
	if ((pVal == '.') ||
		(sVal == pVal))
	{
		return isMatch(s,p,sbegin+1,pbegin+1);
	}
	else if(pVal == '*')
	{
		if (pbegin == p.length() - 1)
		{
			return true;
		}

		pVal = p[++pbegin];
		while ((sbegin < s.length()) && (s[++sbegin] != pVal));		

		if (sbegin >= s.length())
		{
			return false;
		}

		return isMatch(s,p,sbegin+1,pbegin+1);
	}

	return false;
}

bool isMatch(string s, string p) 
{	
	/*vector<string> parttion;
	string::size_type pos = p.find('*');
	while (pos != string::npos)
	{
		parttion.push_back(p.substr(0,pos+1));
		p = p.substr(pos);
	}

	if (p.length())
	{
		parttion.push_back(p);
	}

	bool bResult = false;
	for (int i=0; i<parttion.size(); ++i)
	{
		if (isMatch(s, p, 0, 0))
		{
			bResult = true;
			break;
		}
	}*/
	
	return isMatch(s, p, 0, 0);
}

TEST(LeetCode, tIsMatch)
{
	ASSERT_FALSE(isMatch("aa","a"));
	ASSERT_TRUE(isMatch("aa","aa"));
	ASSERT_FALSE(isMatch("aaa","aa"));
	ASSERT_TRUE(isMatch("aa","a*"));
	ASSERT_TRUE(isMatch("a","a*"));
	ASSERT_TRUE(isMatch("aa",".a"));
	ASSERT_TRUE(isMatch("aacdefge","a*"));
	ASSERT_FALSE(isMatch("aab","c*a*b"));
}