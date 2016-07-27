#include <gtest/gtest.h>
using namespace std;

void rotate1(vector<int>& nums, int k)
{
	const int length = nums.size();
	if (length <= 1)
		return;

	k = k % length;
	if (k == 0)
		return;

	for (int i=0; i<k; i++)
	{
		int v = nums[length-1];
		for (int j=length-1; j>=1; --j)
		{
			nums[j] = nums[j-1];
		}
		nums[0] = v;
	}
}

void reverse(vector<int>& nums, int left, int right)
{
	while (right > left)
	{
		int v = nums[right];
		nums[right] = nums[left];
		nums[left] = v;
		++left;
		--right;
	}
}

void rotate2(vector<int>& nums, int k)
{
	const int length = nums.size();
	if (length <= 1)
		return;

	k = k % length;
	if (k == 0)
		return;

	int mid = length - k;

	reverse(nums,0,mid -1);
	reverse(nums, mid,length-1);
	reverse(nums,0,length-1);
}

void rotate(vector<int>& nums, int k)
{
	const int length = nums.size();
	if (length <= 1)
		return;

	k = k % length;
	if (k == 0)
		return;

	int mid = length - k;

	int first = 0;
	int next = mid;
	while(true)
	{
		int v = nums[next];
		nums[next] = nums[first];
		nums[first] = v;

		if (++first == mid)
			if (++next == length)
				return;
			else
				mid = next;

		else if (++next == length)
			next = mid;
	};
}

TEST(Pratices, tRotate)
{
	// 1,2,3,4,5,6,7 -> 5,6,7,1,2,3,4
	vector<int> t1;
	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(3);
	t1.push_back(4);
	t1.push_back(5);
	t1.push_back(6);
	t1.push_back(7);

	rotate(t1,3);
	rotate(t1,4);
}