#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

// LeetCode
// 299. Bulls and Cows
// https://leetcode.com/problems/bulls-and-cows/

string getHint(string secret, string guess)
{
	int nBulls = 0;
	int nCows = 0;
	size_t nSecretLength = secret.length();
	unordered_map<char, int> tblMapping;

	for (size_t i=0; i<secret.length();++i)
	{
		tblMapping[secret[i]]++;
	}

	for (size_t i=0; i<guess.length(); ++i)
	{
		int cValue = guess[i];
		if ((i < nSecretLength) && (secret[i] == cValue))
		{
			nBulls++;
			if (tblMapping[cValue] > 0)
				tblMapping[cValue]--;
			else
				nCows--;
		}
		else
		{
			unordered_map<char, int>::iterator it = tblMapping.find(cValue);
			if (it != tblMapping.end())
			{
				if (it->second > 0)
				{
					it->second--;
					nCows++;
				}
			}
		}
	}

	char szResult[10] = {0};
	sprintf(szResult,"%dA%dB",nBulls,nCows);

	return szResult;
}

TEST(LeetCode, tGetHint)
{
	ASSERT_EQ(getHint("1123","0111"), "1A1B");
	ASSERT_EQ(getHint("1807","7810"), "1A3B");
	ASSERT_EQ(getHint("5635212","1202"), "0A3B");
	ASSERT_EQ(getHint("153456","012859"), "1A1B");
}