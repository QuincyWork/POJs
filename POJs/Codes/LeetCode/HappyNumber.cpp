#include <gtest\gtest.h>
using namespace std;

bool isHappy(int n)
{
	set<int> numbers;
	int sum = 0;
	while (numbers.find(sum) == numbers.end())
	{
		numbers.insert(n);
		sum = 0;
		while (n)
		{
			int v = n % 10;
			sum += v * v;
			n /= 10;
		}

		if (sum == 1)
		{
			return true;
		}

		n = sum;
	}

	return false;
}

TEST(Pratices, tIsHappy)
{
	//19
	ASSERT_TRUE(isHappy(19));
}