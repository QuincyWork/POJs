#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

int singleNumber1(vector<int>& nums)
{
	int Result = -1;
	unordered_map<int,int> cache;
	vector<int>::const_iterator it = nums.begin();
	for (;it != nums.end(); ++it)
	{
		cache[*it]++;
	}

	unordered_map<int,int>::const_iterator itCache = cache.begin();
	for (;itCache != cache.end(); ++itCache)
	{
		if (itCache->second == 1)
		{
			Result = itCache->first;
			break;
		}
	}

	return Result;
}

// 采用异或操作
int singleNumber(vector<int>& nums)
{
	int Result = 0;
	vector<int>::const_iterator it = nums.begin();
	for (;it != nums.end(); ++it)
	{
		Result ^= *it;
	}

	return Result;
}

TEST(LeetCode, tSingleNumber)
{
	int d1[] = {1};
	vector<int> v1(d1,d1+_countof(d1));

	int result = singleNumber(v1);
	ASSERT_EQ(result, 1);

	int d2[] = {1,2,4,1,5,7,8,2,4,5,7};
	vector<int> v2(d2,d2+_countof(d2));
	result = singleNumber(v2);
	ASSERT_EQ(result, 8);
}