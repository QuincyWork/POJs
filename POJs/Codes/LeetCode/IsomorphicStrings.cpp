#include <gtest\gtest.h>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t)
{
	const int lengthS = s.length();
	const int lengthT = t.length();
	if (lengthS != lengthT)
	{
		return false;
	}

	map<int, int> deltaS;
	map<int, int> deltaT;

	for (int i = 0; i < lengthS; ++i)
	{
		int m = s[i];
		int n = t[i];
		if (deltaS.find(m) != deltaS.end())
		{
			if (m + deltaS[m] != n)
				return false;
		}
		else
		{
			deltaS[m] = n - m;
		}
			
		if (deltaT.find(n) != deltaT.end())
		{
			if (m != n + deltaT[n])
				return false;
		}
		else
		{
			deltaT[n] = m - n;
		}
	}

	return true;
}

TEST(Pratices, tIsIsomorphic)
{
	ASSERT_TRUE(isIsomorphic("egg", "add"));
	ASSERT_FALSE(isIsomorphic("ab", "aa"));
}