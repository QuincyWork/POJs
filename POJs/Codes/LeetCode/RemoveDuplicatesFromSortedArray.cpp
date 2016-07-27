#include <gtest/gtest.h>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	const int length = nums.size();
	if (length == 0)
		return 0;

	int pred = nums[0];
	int last = 0;

	for (int i=1; i<length; ++i)
	{
		int val = nums[i];
		if ((pred != val))
		{
			++last;
			if (last < i)
			{
				nums[last] = val;
			}

			pred = val;
		}
	}

	nums.resize(++last);
	return last;
}

TEST(Pratices, tRemoveDuplicates)
{
	// 1,1,1,2
	vector<int> nums;
	ASSERT_EQ(removeDuplicates(nums),0);

	nums.push_back(1);
	ASSERT_EQ(removeDuplicates(nums),1);

	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);

	ASSERT_EQ(removeDuplicates(nums),2);

	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);

	ASSERT_EQ(removeDuplicates(nums),4);
}