#include <gtest\gtest.h>
using namespace std;

int rob1(vector<int>& nums)
{
	const int length = nums.size();
	int max = 0;
	for (int i = 0; i < 2; i ++)
	{
		int v = 0;
		for (int j = i; j < length; j += 2)
		{
			v += nums[j];
		}

		if (v > max)
			max = v;
	}

	return max;
}

int robNum(vector<int>& nums, vector<int>& pred, int left, int right)
{
	if (left >= right)
		return 0;

	if (pred[left] != -1)
		return pred[left];

	int m = robNum(nums, pred, left + 2, right);
	int n = robNum(nums, pred, left + 3, right);

	pred[left] = nums[left] + (m > n ? m : n);

	return pred[left];
}

int rob(vector<int>& nums)
{
	const int length = nums.size();
	if (!length)
		return 0;

	vector<int> pred;
	pred.assign(length, -1);

	int m = robNum(nums, pred, 0, length);
	int n = robNum(nums, pred, 1, length);

	return (m > n ? m : n);
}

TEST(Pratices, tRob)
{
	// 1,3,9,6,8,4
	int data[] = { 2,5,6,2,8,11,8,10,34,1,2,0,7,12,4,3,56,60 };
	vector<int> t1;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		t1.push_back(data[i]);
	}

	ASSERT_EQ(rob(t1), 135);
}