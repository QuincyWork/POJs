#include <gtest\gtest.h>
#include <Util.h>
#include <set>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
	multiset<int> window(nums.begin(),nums.begin()+k);
	auto mid = next(window.begin(),k / 2);
	vector<double> medians;

	for (int i=k;;++i)
	{
		medians.push_back((double(*mid) + *next(mid, k%2 - 1))/2);		
		if (i == nums.size())
		{
			break; 
		}

		window.insert(nums[i]);
		if (nums[i] < *mid)
		{
			--mid;
		}

		if (nums[i-k] <= *mid)
		{
			++mid;
		}

		window.erase(window.lower_bound(nums[i-k]));
	}

	return medians;
}

TEST(LeetCode,tMedianSlidingWindow)
{
	vector<double> result = medianSlidingWindow(V(8,1,3,-1,-3,5,3,6,7),3);
}