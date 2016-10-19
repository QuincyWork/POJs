#include <gtest/gtest.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool ElementCompare(const pair<int,int>& l, const pair<int,int>& r)
{
	return l.second > r.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) 
{	
	unordered_map<int,int> counts;
	for (int i=0; i < nums.size(); ++i)
	{
		counts[nums[i]]++;
	}

	vector<pair<int,int>> values(counts.begin(), counts.end());
	sort(values.begin(), values.end(), ElementCompare);

	vector<int> result;
	for (int i=0; i<k; ++i)
	{
		result.push_back(values[i].first);
	}

	return result;
}

TEST(LeetCode, tTopKFrequent)
{
	int d1[] = {1,1,1,2,2,3};
	vector<int> v1(d1,d1+_countof(d1));

	vector<int> result = topKFrequent(v1,2);
	ASSERT_EQ(result.size(),2);
}