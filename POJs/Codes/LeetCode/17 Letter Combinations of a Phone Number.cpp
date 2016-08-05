#include <gtest/gtest.h>
using namespace std;

string mapPhoneNumber[] = {
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz" };

bool letterCombinations(string digits, string select, int index, vector<string>& result)
{
	if (index == digits.length())
	{
		result.push_back(select);
		return true;
	}

	int value = digits[index] - '0';
	if (value < 2 || value > 9)
	{
		return false;
	}

	value -= 2;
	for (int i = 0; i < mapPhoneNumber[value].length(); ++i)
	{
		select.push_back(mapPhoneNumber[value][i]);
		if (!letterCombinations(digits, select, index + 1, result))
		{
			return false;
		}
		select.pop_back();
	}

	return true;
}

vector<string> letterCombinations(string digits)
{
	vector<string> result;
	string current;

	if (digits.empty())
	{
		return result;
	}

	if (!letterCombinations(digits, current, 0, result))
	{
		result.clear();
	}

	return result;
}

TEST(LeetCode, tLetterCombinations)
{
	vector<string> result = letterCombinations("23");
	result = letterCombinations("");
}