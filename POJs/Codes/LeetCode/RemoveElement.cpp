#include <gtest/gtest.h>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
	const int n = nums.size();
	if (!n)
		return 0;

	int last = n -1;
	for (int i=last; i>=0; --i)
	{
		if (nums[i]==val)
		{
			if (i != last)
			{
				nums[i] = nums[last];
			}
			--last;
		}
	}
	
	++last;
	nums.resize(last);
	return last;
}

TEST(Pratices, tRemoveElement)
{
	// 3,2,1,4,2,3 =>2,2,1,4

	vector<int> nums;
	ASSERT_EQ(removeElement(nums,3),0);

	nums.push_back(3);
	ASSERT_EQ(removeElement(nums,3),0);

	nums.push_back(2);
	nums.push_back(1);
	ASSERT_EQ(removeElement(nums,3),2);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);

	ASSERT_EQ(removeElement(nums,3),3);
}