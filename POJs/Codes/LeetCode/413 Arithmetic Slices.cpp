#include <gtest\gtest.h>
using namespace std;

bool isArithmeticSlice(vector<int>& A, int begin, int end)
{
	if (end - begin < 2)
		return false;

	int delta = A[begin] - A[begin + 1];
	for (int i = begin + 1; i < end; ++i)
	{
		if ((A[begin] - A[begin + 1]) != delta)
		{
			return false;
		}
	}

	return true;
}

int numberOfArithmeticSlices1(vector<int>& A)
{
	int count = 0;
	for (int i = 0; i < A.size() - 2; ++i)
	{
		for (int m = i + 2; m < A.size(); ++m)
		{
			if (isArithmeticSlice(A, i, m))
			{
				++count;
			}
		}
	}

	return count;
}

int numberOfArithmeticSlices(vector<int>& A)
{
	if (A.size() < 3)
	{
		return 0;
	}

	vector<int> dp(A.size(), 0);

	int count = 0;
	for (int i = 2; i < A.size(); ++i)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
		{
			dp[i] = dp[i - 1] + 1;
		}

		count += dp[i];
	}

	return count;
}

int numberOfArithmeticSlices2(vector<int>& A)
{
	if (A.size() < 3)
	{
		return 0;
	}

	int current = 0;
	int count = 0;
	for (int i = 2; i < A.size(); ++i)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
		{
			current++;
		}
		else
		{
			current = 0;
		}

		count += current;
	}

	return count;
}

TEST(LeetCode, tNumberOfArithmeticSlices)
{
	int d1[] = { 1, 2, 3, 4 };
	vector<int> v1(d1, d1 + _countof(d1));

	ASSERT_EQ(numberOfArithmeticSlices(v1), 3);
}