#include <gtest/gtest.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums)
{
	int xorVal = 0;
	for (int i=0; i<nums.size(); ++i)
	{
		xorVal ^= nums[i];
	}

	xorVal &= -xorVal;
	vector<int> result(2,0);
	for (int i=0; i<nums.size(); ++i)
	{
		if (nums[i] & xorVal)
		{
			result[0] ^= nums[i];
		}
		else
		{
			result[1] ^= nums[i];
		}
	}

	return result;
}

TEST(LeetCode, tSingleNumber2)
{
	int d1[] = {1,2};
	vector<int> v1(d1,d1+_countof(d1));

	vector<int> result = singleNumber(v1);	

	int d2[] = {1,3,4,5,2,1,3,4,5,1,4,5,3,9};
	vector<int> v2(d2,d2+_countof(d2));
	result = singleNumber(v2);
}