#include <gtest/gtest.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) 
{
	int result = 0;
	int left = 0;
	int right = nums.size()-1;
	while (left <= right)
	{
		int mid = left + (right-left)/2;
		int value = nums[mid];
		if (target==value)
		{		
			result = mid;
			break;
		}
		else if(target < value)
		{
			right = mid - 1;			
		}
		else
		{
			left = mid + 1;

		}
	}

	if (!result)
		result = left;

	return result;
}


TEST(LeetCode, tSearchInsert)
{
	// [1,3,5,6], 5 ¡ú 2
	// [1,3,5,6], 2 ¡ú 1
	// [1,3,5,6], 7 ¡ú 4
	// [1,3,5,6], 0 ¡ú 0

	int d1[] = {1,3,5,6};
	vector<int> v1(d1, d1+_countof(d1));

	ASSERT_EQ(searchInsert(v1,5),2);
	ASSERT_EQ(searchInsert(v1,2),1);
	ASSERT_EQ(searchInsert(v1,7),4);
	ASSERT_EQ(searchInsert(v1,0),0);

	int d2[] = {1,3};
	vector<int> v2(d2,d2+_countof(d2));
	ASSERT_EQ(searchInsert(v2,2),1);
}