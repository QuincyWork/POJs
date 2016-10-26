#include <gtest/gtest.h>
using namespace std;


int missingNumber(vector<int>& nums)
{	
	int length = nums.size();	
	int value = (length * (length +1))/2;

	int	count = 0;	
	for (int i=0; i<length; ++i)
	{		
		count += nums[i];
	}

	return (value-count);
}

TEST(LeetCode, tMissingNumber)
{
	int d1[] = {0,1,3};
	vector<int> v1(d1,d1+_countof(d1));

	ASSERT_EQ(missingNumber(v1),2);

}