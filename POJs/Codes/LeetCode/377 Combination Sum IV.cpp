#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

void combination1(vector<int>& nums, int left, vector<int>& select, vector<vector<int>>& result)
{
	for (int i=0; i<nums.size(); ++i)
	{
		int v = nums[i];
		if (left == v)
		{
			select.push_back(v);
			result.push_back(select);
			select.pop_back();
		}
		else if (left > v)
		{
			select.push_back(v);
			combination1(nums, left - v, select, result);
			select.pop_back();
		}
	}
}

void combination(vector<int>& nums, int left, int& count)
{
	for (int i=0; i<nums.size(); ++i)
	{
		int v = nums[i];
		if (left == v)
		{			
			count++;
			break;
		}
		else if (left > v)
		{			
			combination(nums, left - v, count);			
		}
	}
}

int combinationSum41(vector<int>& nums, int target)
{
	int count = 0;
	sort(nums.begin(), nums.end());
	combination(nums, target, count);

	return count;
}

int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1);
	dp[0] = 1;

	sort(nums.begin(), nums.end());
	for (int i=1; i <= target; ++i)
	{
		for (int j=0; j < nums.size(); ++j)
		{		
			if (i < nums[j])
				break;
			
			dp[i] += dp[i - nums[j]];			
		}
	}
	
	return dp.back();
}

TEST(LeetCode, tCombinationSum4)
{
	int d1[] = {1,2,3};
	vector<int> v1(d1, d1+_countof(d1));

	ASSERT_EQ(combinationSum4(v1,4),7);	
}