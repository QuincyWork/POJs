#include <gtest\gtest.h>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	int length = nums.size();
	for (int i = 0; i < length; ++i)
	{
		int val = nums[i];
		if (val > 0 &&
			val <= length &&
			val != i + 1 &&
			nums[val-1] != val)
		{
			nums[i] = nums[val - 1];
			nums[val - 1] = val;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		if (i + 1 != nums[i])
		{
			return i + 1;
		}
	}

	return length + 1;
}

TEST(LeetCode, tFirstMissingPositive)
{

}