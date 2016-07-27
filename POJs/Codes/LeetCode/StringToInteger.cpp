#include <gtest/gtest.h>
using namespace std;

int myAtoi(string str)
{	
	int nLength = str.length();
	if (nLength == 0)
	{
		return 0;
	}

	char* pszData = (char*)str.c_str();
	for (int i=0; i<nLength; ++i)
	{
		if (' ' != *pszData)
		{
			break;
		}

		++pszData;
	}

	// Positive or negative
	int nFlag = 1;
	if ('+' == *pszData)
	{
		++pszData;
	}
	else if('-' == *pszData)
	{
		nFlag = -1;
		++pszData;
	}

	// ignore base case. 
	char cValue;
	long long nResult = 0;
	while( (cValue = *pszData) != '\0')
	{
		if ( (cValue >= '0') && (cValue <= '9'))
		{
			nResult = nResult * 10 + cValue - '0';
		}
		else
		{
			break;
		}

		if (nResult > 0x80000000)
		{
			break;
		}

		++pszData;
	}
	
	nResult *= nFlag;	
	if (nResult > std::numeric_limits<int>::max())
	{
		nResult = std::numeric_limits<int>::max();		
	}
	else if(nResult < std::numeric_limits<int>::min())
	{
		nResult = std::numeric_limits<int>::min();
	}

	return (long)nResult;
}

TEST(Pratices, tMyAtoi)
{
	// 123 
	ASSERT_EQ(myAtoi("123"),123);
	ASSERT_EQ(myAtoi("-123123"),-123123);
	ASSERT_EQ(myAtoi("-123123abdf"),-123123);
	ASSERT_EQ(myAtoi("2147483648"),2147483647);
	ASSERT_EQ(myAtoi("2147483647"),2147483647);
	ASSERT_EQ(myAtoi("-2147483649"),-2147483648);
	ASSERT_EQ(myAtoi("9223372036854775809"),2147483647);
	
}