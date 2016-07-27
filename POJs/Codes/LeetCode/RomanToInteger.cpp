#include <gtest/gtest.h>
using namespace std;

	//{'I','V','X','L','C','D','M','#','#'};
	//  1   5  10  50  100 500 1000

int getSingleRomanInt(char s)
{
	int nResult = 0;
	switch (s)
	{
	case 'I':
		nResult = 1;
		break;
	case 'V':
		nResult = 5;
		break;
	case 'X':
		nResult = 10;
		break;
	case 'L':
		nResult = 50;
		break;
	case 'C':
		nResult = 100;
		break;
	case 'D':
		nResult = 500;
		break;
	case 'M':
		nResult = 1000;
		break;
	}

	return nResult;
}

int romanToInt1(string s) 
{
	int nResult = 0;
	int nLength = s.length();
	if (nLength == 0)
	{
		return 0;
	}

	int nPre = getSingleRomanInt(s[0]);
	int nTemp = nPre;
	for (int i = 1; i < nLength; ++i)
	{
		int nCurrent = getSingleRomanInt(s[i]);
		if (nPre == nCurrent)
		{
			nTemp += nCurrent;
		}
		else if(nPre < nCurrent)
		{
			nTemp = nCurrent - nTemp;
		}
		else
		{
			nResult += nTemp;
			nTemp = nCurrent;
		}

		nPre = nCurrent;
	}

	nResult += nTemp;
	return nResult;
}

// 虽然罗马数字的书写规则较为复杂，但根据罗马数字“左加右减”的规律，
// 可以构造出更简单的罗马数字转换阿拉伯数字的方法：即从右向左（从低位向高位）考察罗马数字，
// 遇到比上一个数字大的数字就加上，遇到比上一个数字小的数字就减去。
int romanToInt(string s) 
{
	int nResult = 0;
	int nLength = s.length();
	if (nLength == 0)
	{
		return 0;
	}

	int nPre = 0;
	for (int i = nLength-1; i >=0; i--)
	{
		int nCurrent = getSingleRomanInt(s[i]);
		if (nCurrent < nPre)
		{
			nResult -= nCurrent;
			nPre = nCurrent;
		}
		else
		{
			nResult += nCurrent;
			nPre = nCurrent;
		}
	}

	return nResult;
}

TEST(Pratices, tRomanToInt)
{
	// DLLXXXVII => 687
	ASSERT_EQ(romanToInt("DCLXXXVII"),687);

	// CCI => 201
	ASSERT_EQ(romanToInt("CCI"),201);

	// MMMCMXCIX => 3999
	ASSERT_EQ(romanToInt("MMMCMXCIX"),3999);

	// CDLVI => 456
	ASSERT_EQ(romanToInt("CDLVI"),456);

	// XCIX => 99
	ASSERT_EQ(romanToInt("XCIX"),99);

	ASSERT_EQ(romanToInt("IV"),4);
}