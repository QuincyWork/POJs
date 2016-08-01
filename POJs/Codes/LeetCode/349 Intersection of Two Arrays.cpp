#include <gtest/gtest.h>
#include <map>
using namespace std;

// LeetCode
// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> result;
	map<int,int> tblValueCount;
	for(vector<int>::const_iterator it = nums1.begin();
		it != nums1.end();
		++it)
	{
		tblValueCount[*it] = 1;
	}

	for (vector<int>::const_iterator it = nums2.begin();
		it != nums2.end();
		++it)
	{
		if (1 == tblValueCount[*it]--)
		{
			result.push_back(*it);
		}
	}

	return result;
}

TEST(LeetCode, tIntersection)
{
	// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
	int d1[] = {1,2,2,1};
	vector<int> v1(d1,d1+_countof(d1));

	int d2[] = {2,2};
	vector<int> v2(d2,d2+_countof(d2));

	vector<int> result = intersection(v1,v2);

}