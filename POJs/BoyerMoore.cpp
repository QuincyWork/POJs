#include <gtest/gtest.h>
using namespace std;

int  BmBadCode[256] = {0};
int  BmGoodSuffix[100] = {0};

void preBmBadCode(string& key)
{
	const int length = key.length();
	for (int i=0; i<_countof(BmBadCode); ++i)
	{
		BmBadCode[i] = length;
	}

	for (int i=0; i<length; ++i)
	{
		BmBadCode[key[i]] = length - 1 - i;
	}
}

void suffix(string& key, int* suff)
{
	int f,g,i;
	f = 0;
	int length = key.length();
	suff[length-1] = length;
	g = length - 1;

	for (i=length-2;i>=0; i--)
	{
		if (i > g && suff[i+length-1-f] < i-g)
		{
			suff[i] = suff[i+length-1-f];
		}
		else
		{
			if (i<g)
				g = i;
			f = i;
			while (g>=0 && key[g] == key[g+length-1-f])
				--g;

			suff[i] = f - g;
		}
	}
}

void preBmGoodSuffix(string& key)
{
	int i,j;
	int suff[100];
	suffix(key,suff);
	int length = key.length();

	for (int i=0; i<length; ++i)
	{
		BmGoodSuffix[i] = length;
	}


}

int Search(char* value, char* key)
{
	int n = strlen(value);
	int m = strlen(key);	
	int pos = m-1;	
	if (m==0 || n==0)
	{
		return -1;
	}

	BuildSkipTbl(key);

	while (pos < n)
	{
		int i=0;
		for (; i < m; i++)
		{
			if (value[pos-i] != key[m-1-i])
			{
				pos += SkipTbl[value[pos-i]];
				break;
			}
		}

		if (i == m)
		{
			return pos-i-1;
		}
	}

	return -1;
}

TEST(tAlgo, tBMSearch)
{
	ASSERT_EQ(Search("",""),-1);
	ASSERT_EQ(Search("ABCDEFG","CD"),2);
	ASSERT_EQ(Search("ABCDEFGACFGE","AB"),0);
}