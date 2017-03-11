#include <gtest/gtest.h>
#include <map>
using namespace std;

int robSub(vector<int>& nums, bool bCanRob, int index, bool bEndCanRob, map<int,int>& record)
{
	if (index >= nums.size())
	{
		return 0;
	}

	if (index == nums.size()-1)
	{
		bCanRob &= bEndCanRob;
	}
	
	int val = robSub(nums, true, index+1, bEndCanRob, record);
	if (bCanRob)
	{
		val = max(val, robSub(nums, false, index+1, bEndCanRob, record) + nums[index]);		
	}

	return val;
}

int rob1(vector<int>& nums)
{
	map<int,int> record;
	int v1 = robSub(nums, true, 0, false, record);
	int v2 = robSub(nums, false, 0, true, record);

	return max(v1, v2);
}

int rob(vector<int>& nums, int left, int right)
{
	if (left >= right)
	{
		return nums[left];
	}

	vector<int> dp(right, 0);
	dp[left] = nums[left];
	dp[left+1] = max(nums[left], nums[left+1]);

	for (int i = left + 2; i < right; ++i)
	{
		dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
	}

	return dp.back();
}

int rob(vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		return nums.empty() ? 0 : nums[0];
	}

	return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
}

TEST(LeetCode, tRob)
{
	int d1[] = {2,3,4,5,1,3};
	vector<int> v1(d1, d1+_countof(d1));

	ASSERT_EQ(rob(v1),11);
}