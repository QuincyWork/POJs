#include <gtest\gtest.h>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate1(vector<int>& nums, int k) 
{
	const int length = nums.size();
	for (int t=0; t < length; ++t)
	{		
		int val = nums[t];
		for (int s = t+1; s < length && s <= t+k; ++s)
		{
			if (val == nums[s])
			{
				return true;
			}
		}
	}

	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	unordered_map<int, int> data;
	for (int i=0; i<nums.size(); ++i)
	{
		int val = nums[i];
		if (data.find(val) != data.end() &&
			i - data[val] <= k)
		{
			return true;
		}

		data[val] = i;
		if (i - k > 0)
		{
			data.erase(i-k-1);
		}
	}

	return false;
}

TEST(Pratices, tContainsNearbyDuplicate)
{
	int data[] = {1,2,3,4,5,2,7};
	vector<int> vData;
	for (int i=0; i<sizeof(data)/sizeof(data[0]); ++i)
	{
		vData.push_back(data[i]);
	}

	ASSERT_TRUE(containsNearbyDuplicate(vData,4));
	ASSERT_FALSE(containsNearbyDuplicate(vData,3));
}