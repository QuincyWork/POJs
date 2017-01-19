#include "util.h"
#include <gtest/gtest.h>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	vector<pair<int, int>> result;
	k = min(k, (int)(nums1.size() * nums2.size()));

	if (k==0)
	{
		return result;
	}

	vector<int> index(nums1.size(),0);
	while ( k > 0 )
	{
		int min = std::numeric_limits<int>::max();
		int t = 0;
		for (int i=0; i<nums1.size(); ++i)
		{
			if (index[i] < nums2.size() && 
				nums1[i] + nums2[index[i]] < min)
			{
				t = i;
				min = nums1[i] + nums2[index[i]];
			}
		}

		result.push_back(make_pair(nums1[t],nums2[index[t]]));
		index[t]++;
		k--;
	}

	return result;
}


TEST(LeetCode,tKSmallestPairs)
{
	// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
	// Return: [1,2],[1,4],[1,6]

	// Given nums1 = [1,2], nums2 = [3],  k = 3 
	// Return: [1,3],[2,3]

	vector<pair<int, int>> result = kSmallestPairs(V(3,1,7,11),V(3,2,4,6),3);
}