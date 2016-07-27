#include <gtest/gtest.h>
#include <map>

using namespace std;

int majorityElement1(vector<int>& nums)
{
	map<int, int> cache;
	for (int i=0; i<nums.size(); ++i)
	{
		cache[nums[i]]++;
	}

	for (map<int, int>::const_iterator it = cache.begin();
		it != cache.end();
		++it)
	{
		if (it->second >= (nums.size() / 2))
		{
			return it->first;
		}
	}

	return 0;
}

int majorityElement(vector<int>& nums)
{
	const int length = nums.size();
	if (!length)
		return 0;

	int count = 0;
	int value = 0;
	for (int i=0; i<length; ++i)
	{
		if (count==0)
		{
			count++;
			value = nums[i];
		}
		else if(value == nums[i])
		{
			count++;
		}
		else
		{
			count--;
		}
	}

	return value;
}

TEST(Pratices ,tMajorityElement)
{
	vector<int> t1;
	t1.push_back(1);
	ASSERT_EQ(majorityElement(t1),1);
	t1.push_back(2);
	ASSERT_EQ(majorityElement(t1),1);
	t1.push_back(2);
	t1.push_back(2);
	t1.push_back(2);
	t1.push_back(4);
	ASSERT_EQ(majorityElement(t1),2);
}