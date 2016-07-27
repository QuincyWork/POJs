#include <gtest/gtest.h>
using namespace std;


string singleDigitToRoman(int n, int nth)
{
	if (n ==0)
	{
		return "";
	}

	char singleRoman[] = {'I','V','X','L','C','D','M','#','#'};
	//                     1   5   10  50 100 500 1000
	nth = 2*nth - 1;
	string strResult;

	if (n <= 3)
	{
		strResult.append(n,singleRoman[nth-1]);
	}
	else if (n == 4)
	{
		strResult.push_back(singleRoman[nth-1]);
		strResult.push_back(singleRoman[nth]);
	}
	else if (n == 5)
	{
		strResult.push_back(singleRoman[nth]);
	}
	else if (n >= 6 && n <= 8)
	{
		strResult.push_back(singleRoman[nth]);
		strResult.append(n-5,singleRoman[nth-1]);		
	}
	else if (n == 9)
	{
		strResult.push_back(singleRoman[nth-1]);
		strResult.push_back(singleRoman[nth+1]);
	}
	else
	{
		strResult = "Error";
	}

	return strResult;
}

string intToRoman(int num) 
{
	if (num < 1 || num > 3999)
	{
		return "Invalid Param!";
	}

	string strSingleResult[4];
	int index = 0;
	while (num)
	{
		strSingleResult[index] = singleDigitToRoman(num % 10, index + 1);
		num /= 10;
		++index;
	}
	
	string strResult;
	while (index > 0)
	{
		strResult += strSingleResult[index-1];
		--index;
	}

	return strResult;
}

TEST(Pratices, tIntToRoman)
{
	//{'I','V','X','L','C','D','M','#','#'};
	//  1   5  10  50  100 500 1000
	// 1
	ASSERT_EQ(intToRoman(1),"I");
	// 99
	ASSERT_EQ(intToRoman(99),"XCIX");
	// 456
	ASSERT_EQ(intToRoman(456),"CDLVI");
	// 3999
	ASSERT_EQ(intToRoman(3999),"MMMCMXCIX");
	// 201
	ASSERT_EQ(intToRoman(201),"CCI");
	// 687
	ASSERT_EQ(intToRoman(687),"DLLXXXVII");
}