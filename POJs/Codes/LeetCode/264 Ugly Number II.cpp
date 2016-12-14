#include <gtest\gtest.h>
#include <algorithm>
using namespace std;

int nthUglyNumber1(int n)
{
	vector<int> record;
	vector<int> indexs(3, 0);
	record.push_back(1);

	while (record.size() < n)
	{
		int v1 = record[indexs[0]] * 2;
		int v2 = record[indexs[1]] * 3;
		int v3 = record[indexs[2]] * 5;

		int val = min(v1, min(v2, v3));
		if (val == v1)
			indexs[0]++;

		if (val == v2)
			indexs[1]++;

		if (val == v3)
			indexs[2]++;

		record.push_back(val);
	}

	return record.back();
}

int nthUglyNumber(int n, vector<int>& factor)
{
	if (!n || !factor.size())
	{
		return 0;
	}

	vector<int> record;
	vector<int> idx(factor.size(), 0);

	record.push_back(1);
	while (record.size() < n)
	{
		int minVal = numeric_limits<int>::max();
		vector<int> minIdx;
		for (int i = 0; i < factor.size(); ++i)
		{
			int value = record[idx[i]] * factor[i];
			if (minVal > value)
			{
				minVal = value;
				minIdx.clear();
				minIdx.push_back(i);
			}
			else if (minVal == value)
			{
				minIdx.push_back(i);
			}
		}

		// insert val and plus index
		record.push_back(minVal);

		for (int i = 0; i < minIdx.size(); ++i)
		{
			idx[minIdx[i]]++;
		}
	}

	return record.back();
}

int nthUglyNumber(int n)
{
	vector<int> factor;
	factor.push_back(2);
	factor.push_back(3);
	factor.push_back(5);

	return nthUglyNumber(10, factor);
}

TEST(LeetCode, tNthUglyNumber)
{
	ASSERT_EQ(nthUglyNumber(10), 12);
}