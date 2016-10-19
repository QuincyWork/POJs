#include <gtest/gtest.h>
using namespace std;

// 153. Find Minimum in Rotated Sorted Array
//

int findMin1(vector<int>& nums) 
{
	int min = numeric_limits<int>::max();
	for (int i=0; i<nums.size(); ++i)
	{
		if (min > nums[i])
		{
			min = nums[i];
		}
	}

	return min;
}

int findSubMin(vector<int>& nums, int left, int right)
{
	if (left == right)
	{
		return nums[left];
	}

	int pivot = left + (right-left)/2;
	int lv = nums[left];
	if (lv > nums[pivot])
	{
		lv = findSubMin(nums, left, pivot);
	}

	int rv = nums[pivot+1];
	if (rv > nums[right])
	{
		rv = findSubMin(nums, pivot+1, right);
	}

	return (lv < rv ? lv : rv);
}

int findMin(vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}

	return findSubMin(nums, 0, nums.size()-1);
}

TEST(LeetCode, tFindMin)
{
	int d1[] = {1};
	vector<int> v1(d1,d1+_countof(d1));
	ASSERT_EQ(findMin(v1), 1);

	int d2[] = {4,5,6,7,0,1,2};
	vector<int> v2(d2,d2+_countof(d2));
	ASSERT_EQ(findMin(v2), 0);
}