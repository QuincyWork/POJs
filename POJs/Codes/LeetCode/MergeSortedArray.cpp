#include <gtest/gtest.h>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	if (nums1.size() < m+n)
	{
		nums1.resize(m+n);
	}

	int i = 0;
	int j = 0;
	while ((i<m) && (j<n))
	{
		if (nums2[j] < nums1[i])
		{
			nums1.insert(nums1.begin()+i,nums2[j]);
			++j;
			++m;
		}

		++i;
	}

	while (j < n)
	{
		nums1[i++] = nums2[j++];
	}
}

TEST(Pratices, tMerge)
{
	vector<int> nums1;
	nums1.assign(10,0);
	nums1[0] = 1;
	nums1[1] = 3;
	nums1[2] = 4;

	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(7);
	nums2.push_back(10);
	nums2.push_back(100);
	
	merge(nums1,3,nums2,4);
}