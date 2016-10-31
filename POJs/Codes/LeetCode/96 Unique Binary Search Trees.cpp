#include <gtest\gtest.h>
using namespace std;

int numTrees(int n)
{
	if (n == 1)
		return 1;
	
	if (n == 2)
		return 2;

	vector<int> record(n+1);
	record[0] = 1;
	record[1] = 1;
	record[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		int v = 0;
		for (int j = 0; j < i; ++j)
		{
			v += record[j] * record[i - j - 1];
		}

		record[i] = v;
	}
	
	return record[n];
}

TEST(LeetCode, tNumTrees)
{
	ASSERT_EQ(numTrees(3), 5);
}