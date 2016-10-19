#include <gtest/gtest.h>
using namespace std;

// ºŸ…Ë ˝æ›
// X1£¨X2£¨X3£¨X4£¨X5£¨X1£¨X2£¨X4£¨X5£¨X1£¨X2£¨X4£¨X5


int singleNumber(vector<int>& nums) 
{
	int bitCount;
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		bitCount = 0;
		for (int j = 0; j < nums.size(); ++j)
		{
			bitCount += (nums[j] >> i) & 1;
		}
		result |= (bitCount % 3) << i;
	}

	return result;
}

TEST(LeetCode, tSingleNumber2)
{
	int d1[] = {1};
	vector<int> v1(d1,d1+_countof(d1));

	int result = singleNumber(v1);
	ASSERT_EQ(result, 1);

	int d2[] = {1,3,4,5,2,1,3,4,5,1,4,5,3};
	vector<int> v2(d2,d2+_countof(d2));
	result = singleNumber(v2);
	ASSERT_EQ(result, 2);
}