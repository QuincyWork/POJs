#include <gtest/gtest.h>
#include <numeric>
using namespace std;

int maxSubArray(vector<int>& nums)
{	
	int result = numeric_limits<int>::min();
	int sum = 0;
	for (vector<int>::const_iterator it = nums.begin();
		it != nums.end();
		++it)
	{							
		if (sum + *it < 0)
		{
			sum = *it;
		}		

		if (sum > result)
		{
			result = sum;
		}

		sum += *it;	
	}

	return result;
}

TEST(LeetCode, tMaxSubArray)
{
	//
	int d1[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> v1(d1, d1+_countof(d1));

	ASSERT_EQ(maxSubArray(v1), 6);
}