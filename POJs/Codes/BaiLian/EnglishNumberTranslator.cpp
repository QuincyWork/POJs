#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

enum TOKEN_TYPE
{
	TYPE_NUMBER,
	TYPE_UNIT,
	TYPE_NEGATIVE
};

struct Token
{
	string		StringValue;
	int			Value;
	TOKEN_TYPE	Type;
};

Token sTokenTable[] = 
{
	{"zero",		0, TYPE_NUMBER},
	{"one",			1, TYPE_NUMBER},
	{"two",			2, TYPE_NUMBER},
	{"three",		3, TYPE_NUMBER},
	{"four",		4, TYPE_NUMBER},
	{"five",		5, TYPE_NUMBER},
	{"six",			6, TYPE_NUMBER},
	{"seven",		7, TYPE_NUMBER},
	{"eight",		8, TYPE_NUMBER},
	{"nine",		9, TYPE_NUMBER},
	{"ten",			10, TYPE_NUMBER},
	{"eleven",		11, TYPE_NUMBER},
	{"twelve",		12, TYPE_NUMBER},
	{"thirteen",	13, TYPE_NUMBER},
	{"fourteen",	14, TYPE_NUMBER},
	{"fifteen",		15, TYPE_NUMBER},
	{"sixteen",		16, TYPE_NUMBER},
	{"seventeen",	17, TYPE_NUMBER},
	{"eighteen",	18, TYPE_NUMBER},
	{"nineteen",	19, TYPE_NUMBER},
	{"twenty",		20, TYPE_NUMBER},
	{"thirty",		30, TYPE_NUMBER},
	{"forty",		40, TYPE_NUMBER},
	{"fifty",		50, TYPE_NUMBER},
	{"sixty",		60, TYPE_NUMBER},
	{"seventy",		70, TYPE_NUMBER},
	{"eighty",		80, TYPE_NUMBER},
	{"ninety",		90, TYPE_NUMBER},
	{"hundred",		100, TYPE_UNIT},
	{"thousand",	1000, TYPE_UNIT},
	{"million",		1000000, TYPE_UNIT},	
	{"negative",	-1, TYPE_NEGATIVE}
};

bool GetPreToken(const string& value, int& pos, Token& nextToken)
{	
	bool bRetValue = false;
	pos = value.find_last_not_of(" ", pos);
	if (pos == string::npos)
	{
		return false;
	}
	
	string tokenStr;
	string::size_type next = value.rfind(" ", pos);
	if (next != string::npos)
	{
		tokenStr = value.substr(next+1, pos-next);
	}
	else
	{
		tokenStr = value.substr(0, pos+1);
	}

	for (int i=0; i<sizeof(sTokenTable)/sizeof(sTokenTable[0]); ++i)
	{
		if (tokenStr.compare(sTokenTable[i].StringValue)==0)
		{			
			nextToken.Type = sTokenTable[i].Type;
			nextToken.Value = sTokenTable[i].Value;

			bRetValue = true;
			pos = next;
			break;
		}
	}

	return bRetValue;
}

long Parse(const string& value)
{
	long lResult = 0;
	int nNegatvie = 1;
	int nPos = string::npos;	
	Token NextToken;
	int CurrentUnitValue = 1;	
	
	while (GetPreToken(value, nPos, NextToken))
	{
		switch (NextToken.Type)
		{
		case TYPE_NEGATIVE:
			nNegatvie = -1;
			break;

		case TYPE_NUMBER:
			lResult += NextToken.Value * CurrentUnitValue;
			break;

		case TYPE_UNIT:

			if (NextToken.Value >= CurrentUnitValue)
			{
				CurrentUnitValue = NextToken.Value;
			}
			else
			{
				CurrentUnitValue *= NextToken.Value;
			}
			break;
		}

		if (nPos == string::npos)
		{
			break;
		}
	}

	lResult *= nNegatvie;

	return lResult;
}

int main2()
{
	char input[512];
	cin.getline(input,512);
	string value(input);
	while (!value.empty())
	{
		cout << Parse(value) << endl;
		cin.getline(input, 512);
		value = input;		
	}

	return 0;
}

// http://dsalgo.openjudge.cn/201409week4/1/?lang=zh_CN

// Test Case
// zero 
// six
// negative seven hundred twenty nine
// one million one hundred one
// eight hundred fourteen thousand twenty two
// eight thousand fourteen hundred  twenty two

TEST(BaiLian, tEnglishNumberTranslator)
{	
	//main2();

	ASSERT_EQ(Parse("zero"), 0);
	ASSERT_EQ(Parse("six"), 6);
	ASSERT_EQ(Parse("negative seven hundred twenty nine"), -729);
	ASSERT_EQ(Parse("one million one hundred one"), 1000101);
	ASSERT_EQ(Parse("eight hundred fourteen thousand twenty two"), 814022);
	ASSERT_EQ(Parse("one"), 1);
	ASSERT_EQ(Parse("two"), 2);
	ASSERT_EQ(Parse("three"), 3);
	ASSERT_EQ(Parse("four"), 4);
	ASSERT_EQ(Parse("five"), 5);
	ASSERT_EQ(Parse("seven"), 7);
	ASSERT_EQ(Parse("eight"), 8);
	ASSERT_EQ(Parse("nine"), 9);
	ASSERT_EQ(Parse("ten"), 10);
	ASSERT_EQ(Parse("eleven"), 11);
	ASSERT_EQ(Parse("twelve"), 12);
	ASSERT_EQ(Parse("thirteen"), 13);
	ASSERT_EQ(Parse("fourteen"), 14);
	ASSERT_EQ(Parse("fifteen"), 15);
	ASSERT_EQ(Parse("sixteen"), 16);
	ASSERT_EQ(Parse("seventeen"), 17);
	ASSERT_EQ(Parse("eighteen"), 18);
	ASSERT_EQ(Parse("nineteen"), 19);
	ASSERT_EQ(Parse("twenty"), 20);
	ASSERT_EQ(Parse("thirty"), 30);
	ASSERT_EQ(Parse("forty one"), 41);
	ASSERT_EQ(Parse("fifty"), 50);
	ASSERT_EQ(Parse("sixty"), 60);
	ASSERT_EQ(Parse("seventy seven"), 77);
	ASSERT_EQ(Parse("eighty"), 80);
	ASSERT_EQ(Parse("ninety"), 90);
	ASSERT_EQ(Parse("one hundred three"), 103);
	ASSERT_EQ(Parse("negative one hundred twenty three million four hundred fifty six thousand seven hundred eighty"), -123456780);
	ASSERT_EQ(Parse("one hundred twenty three million four hundred fifty six thousand seven hundred eighty"), 123456780);
	ASSERT_EQ(Parse("nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine"), 999999999);
	ASSERT_EQ(Parse("negative nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine"), -999999999);	
}
