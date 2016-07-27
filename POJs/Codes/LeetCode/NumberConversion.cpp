#include <gtest/gtest.h>
using namespace std;

string DecimalConvertToRadix(int nValue, int nRadix)
{
	int State[256] = {0};
	int nIndex = 0;	
	static char szText[] = "0123456789ABCDEF";

	while (nValue)
	{
		State[nIndex++] = nValue % nRadix;
		nValue = nValue / nRadix;
	};

	string strValue;
	for (int i = nIndex-1; i >= 0; --i)
	{
		strValue += szText[State[i]];	
	}

	if (strValue.empty())
	{
		strValue = "0";
	}

	return strValue;
}

int RadixConvertToDecimal(const string& strValue, int nRadix)
{	
	int nValue = 0;
	int Base = 1;	

	for (int i = strValue.size()-1; i >=0; i--)
	{
		char cTemp = strValue[i];
		if (cTemp >= 'a' && cTemp <= 'f')
		{
			nValue += (cTemp - 'a' + 10) * Base;
		}
		else if (cTemp >= 'A' && cTemp <= 'F')
		{
			nValue += (cTemp - 'A' + 10) * Base;
		}
		else
		{
			nValue+= (cTemp - '0') * Base;
		}
		
		Base *= nRadix;
	}

	return nValue;
}

TEST(Pratices, tNumberConversion)
{
	// 10进制转2进制
	// 0 => 
	// 1 => 1
	// 2 => 10
	// 34 => 100010
	// 100 => 1100100
	ASSERT_EQ(DecimalConvertToRadix(0, 2), "0");
	ASSERT_EQ(DecimalConvertToRadix(1, 2), "1");
	ASSERT_EQ(DecimalConvertToRadix(2, 2), "10");
	ASSERT_EQ(DecimalConvertToRadix(34, 2), "100010");
	ASSERT_EQ(DecimalConvertToRadix(100, 2), "1100100");

	// 10进制转8进制
	// 0 =>
	// 7 => 7
	// 8 => 10
	// 9 => 11
	// 34 => 42
	// 100 => 144
	ASSERT_EQ(DecimalConvertToRadix(0, 8),"0");
	ASSERT_EQ(DecimalConvertToRadix(7, 8),"7");
	ASSERT_EQ(DecimalConvertToRadix(8, 8),"10");
	ASSERT_EQ(DecimalConvertToRadix(9, 8),"11");
	ASSERT_EQ(DecimalConvertToRadix(34, 8),"42");
	ASSERT_EQ(DecimalConvertToRadix(100, 8),"144");
	
	// 2进制转10进制
	// 0 = > 0
	// 1 = > 1
	// 10 = > 2
	// 1101 = >13
	// 11111111 => 255
	ASSERT_EQ(RadixConvertToDecimal("0", 2),0);
	ASSERT_EQ(RadixConvertToDecimal("1", 2),1);
	ASSERT_EQ(RadixConvertToDecimal("10", 2),2);
	ASSERT_EQ(RadixConvertToDecimal("1101", 2),13);
	ASSERT_EQ(RadixConvertToDecimal("11111111", 2),255);

	// 16进制转换10进制
	// 0 => 0
	// f => 15
	// 10 => 16
	// 1Fea => 8170
	// FFFF => 65535	
	ASSERT_EQ(RadixConvertToDecimal("0", 16),0);
	ASSERT_EQ(RadixConvertToDecimal("f", 16),15);
	ASSERT_EQ(RadixConvertToDecimal("10", 16),16);
	ASSERT_EQ(RadixConvertToDecimal("1Fea", 16),8170);
	ASSERT_EQ(RadixConvertToDecimal("FFFF", 16),65535);
}