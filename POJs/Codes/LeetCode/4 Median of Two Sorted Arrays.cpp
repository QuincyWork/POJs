#include <gtest/gtest.h>
using namespace std;

double findKth(vector<int>& A1, vector<int>& A2, int startA1, int startA2, int len1, int len2, int k)
{
	if (len1 > len2)
	{
		return findKth(A2, A1, startA2, startA1, len2, len1, k);
	}

	if (len1 == 0)
	{
		return A2[startA2 + k-1];
	}

	if (k == 1)
	{
		return min(A1[startA1],A2[startA2]);
	}

	int p1 = min(k/2, len1);
	int p2 = k - p1;

	if (A1[startA1+p1-1] < A2[startA2+p2-1])
	{
		return findKth(A1,A2,startA1+p1,startA2,len1-p1,len2,k-p1);
	}
	else if (A1[startA1+p1-1] > A2[startA2+p2-1])
	{
		return findKth(A1,A2,startA1,startA2+p2,len1,len2-p2,k-p2);
	}
	else
	{
		return A1[startA1+p1-1];
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int length1 = nums1.size();
	int length2 = nums2.size();

	int k = (length1 + length2) / 2;
	if ((length1+length2) % 2 == 0)
	{
		return (findKth(nums1,nums2,0,0,length1,length2,k) + 
			findKth(nums1,nums2,0,0,length1,length2,k+1)) / 2;
	}
	else
	{
		return findKth(nums1,nums2,0,0,length1,length2,k+1);
	}
}


TEST(LeetCode, tFindMedianSortedArrays)
{
	int d1[] = {1,2};
	int d2[] = {3};
	vector<int> v1(d1,d1+_countof(d1));
	vector<int> v2(d2,d2+_countof(d2));

	ASSERT_EQ(findMedianSortedArrays(v1, v2), 2.0);
}