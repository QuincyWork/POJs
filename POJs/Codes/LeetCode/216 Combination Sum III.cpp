#include <gtest\gtest.h>
using namespace std;

void combinationSumResrve(vector<vector<int>>& record, vector<bool>& flags, int begin, int leftK, int leftN)
{
	if (leftK == 0)
	{
		return;
	}

	for (int i = begin + 1; i <= 9; ++i)
	{
		if (flags[i])
		{
			continue;
		}

		if (leftN == i && leftK == 1)
		{
			vector<int> val;
			for (int j = 1; j < i; ++j)
			{
				if (flags[j])
				{
					val.push_back(j);
				}
			}
			val.push_back(i);
			record.push_back(val);
			return;
		}

		if (leftN <= i)
		{
			break;
		}

		flags[i] = true;
		combinationSumResrve(record, flags, i, leftK - 1, leftN - i);
		flags[i] = false;
	}
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> record;
	vector<bool> flags(10,false);
	combinationSumResrve(record, flags, 0, k, n);

	return record;
}

TEST(LeetCode, tCombinationSum3)
{
	vector<vector<int>> record = combinationSum3(3, 7);

}