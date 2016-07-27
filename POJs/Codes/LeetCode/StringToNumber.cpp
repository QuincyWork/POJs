#include <gtest/gtest.h>
using namespace std;

int StrToInt(const char* szValue, int nBase = 0, bool* bValid = NULL)
{	
	long long nValue = 0;
	int nSign = 1;
	
	if (bValid)
	{
		*bValid = false;
	}

	if (!szValue)
	{
		return 0;
	}

	if (nBase < 0 || nBase == 1 || nBase > 36)
	{
		return 0;
	}

	char cData = *szValue++;
	while(cData <= ' ')			// skip whitespace
	{
		cData = *szValue++;
	}

	if (cData == '+')
	{
		cData = *szValue++;
	}
	else if(cData == '-')
	{
		cData = *szValue++;
		nSign = -1;
	}

	if (nBase==0)
	{
		if (cData != '0')
			nBase = 10;
		else if (*szValue == 'x' || *szValue == 'X')
			nBase = 16;
		else
            nBase = 8;
	}

	if (nBase == 16)
	{
		if (cData == '0' && (*szValue == 'x' || *szValue == 'X'))
		{
			szValue++;
			cData = *szValue++;
		}
	}

	while (cData != '\0')
	{
		int nData = 0;
		if (cData >= '0' && cData <= '9')
		{			
			nData = cData-'0';
		}
		else if (cData >= 'A' && cData <= 'Z')
		{
			nData = cData - 'A' + 10;
		}
		else if(cData >= 'a' && cData <= 'z')
		{
			nData = cData - 'a' + 10;
		}
		else
		{
			break;
		}
		
		if (nData >= nBase) // bad digit
		{
			break;
		}

		nValue = (nBase * nValue) + nData;		
		if (nValue > std::numeric_limits<int>::max())
		{
			nValue = 0;
			break;
		}

		cData = *szValue++;
	}
		
	if (bValid)
	{
		*bValid = (cData == '\0');
	}
	
	return (int)(nSign * nValue);
}

TEST(Pratices, tStrToInt)
{	
	// NULL -> 0
	// ""  -> 0	
	// "0" -> 0
	// "+123" -> 123
	// "-123" -> -123
	// "123" -> 123
	
	ASSERT_EQ(StrToInt(NULL), 0);
	ASSERT_EQ(StrToInt(""), 0);
	ASSERT_EQ(StrToInt("0"), 0);
	ASSERT_EQ(StrToInt("+123"), 123);
	ASSERT_EQ(StrToInt("-123"), -123);
	ASSERT_EQ(StrToInt("123"), 123);

	// 16进制
	// 0x10 -> 16
	// 0x0 -> 0
	// 0x123 -> 291
	ASSERT_EQ(StrToInt("0x10"), 16);
	ASSERT_EQ(StrToInt("0x10",16), 16);
	ASSERT_EQ(StrToInt("0x0",16), 0);
	ASSERT_EQ(StrToInt("-0x123"), -291);
	
	// 8进制
	// 010 -> 8	
	// 0123 -> 83
	ASSERT_EQ(StrToInt("010"), 8);
	ASSERT_EQ(StrToInt("0123",8), 83);

}