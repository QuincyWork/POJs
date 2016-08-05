#include <gtest/gtest.h>
using namespace std;

vector<string> letterCombinations(string digits)
{
	string mapPhoneNumbe[] = {
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"};

	vector<string> result;
	string current;

	for (int i=0; i<digits.length();++i)
	{
		int value = digits[i] - '0';
		if (value < 2 && value > 9)
		{
			result.clear();
			break;
		}

		for (int m = 0; m < mapPhoneNumbe[value].length(); ++m)
		{
			current = mapPhoneNumbe[value][0];
			for (int j = i+1; j < digits.length(); ++j)
			{
				for (int n = 0; n < mapPhoneNumbe[j].length(); ++n)
				{

				}
			}
		}
	}


	return result;
}