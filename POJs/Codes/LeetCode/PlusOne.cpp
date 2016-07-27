#include <gtest/gtest.h>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	vector<int> result;
	const int n = digits.size();
	int carry = 0;
	int data = 1;
	for (int i = n-1; i>=0; --i)
	{
		if (digits[i]>9 || digits[i] <0)
		{
			result.clear();
			return result;
		}

		int val = digits[i] + carry;
		if (data)
		{
			val += data;
			data = 0;
		}

		carry = val / 10;
		result.insert(result.begin(), val % 10);
	}

	if (carry+data > 0)
	{
		result.insert(result.begin(), carry+data);
	}

	return result;
}

TEST(Pratices,tPlusOne)
{
	vector<int> digits;
	vector<int> result = plusOne(digits);

	digits.push_back(1);
	result = plusOne(digits);
	digits.push_back(9);
	result = plusOne(digits);
	digits.push_back(9);
	result = plusOne(digits);

	digits.clear();
	digits.push_back(0);
	result = plusOne(digits);

	digits.clear();
	digits.push_back(10);
	result = plusOne(digits);
}