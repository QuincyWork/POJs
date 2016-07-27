#include <gtest\gtest.h>
#include <set>
using namespace std;

int Partition(vector<int>& nums, int left, int right)
{
	int p = nums[right];
	int last = left;
	for (int i = left; i < right; i++)
	{
		if (nums[i] < p)
		{
			int t = nums[last];
			nums[last] = nums[i];
			nums[i] = t;
			last++;
		}
	}

	nums[right] = nums[last];
	nums[last] = p;
	return last;
}

void QSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int p = Partition(nums, left, right);
		QSort(nums, left, p - 1);
		QSort(nums, p + 1, right);
	}
}

bool containsDuplicate1(vector<int>& nums)
{
	const int length = nums.size();
	if (length <= 1)
		return false;

	QSort(nums, 0, length - 1);
	for (int i = 1; i < length; ++i)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}

	return false;
}

bool containsDuplicate(vector<int>& nums)
{
	set<int> cache;
	for (int i = 0; i < nums.size(); ++i)
	{
		int v = nums[i];
		if (cache.find(v) != cache.end())
			return true;

		cache.insert(v);
	}

	return false;
}

TEST(Pratices, tContainsDumplicate)
{
	// 1,2,3,5,10,2,7
	vector<int> data = {1,2,3,5,10,2,7};
	ASSERT_TRUE(containsDuplicate(data));

	vector<int> data1 = { 1,2 };
	ASSERT_FALSE(containsDuplicate(data1));

	vector<int> data2 = { 0,0 };
	ASSERT_TRUE(containsDuplicate(data2));
}

