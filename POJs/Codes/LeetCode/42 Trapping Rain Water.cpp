#include <gtest/gtest.h>
#include <deque>
using namespace std;

int trap(vector<int>& height)
{
	if (height.size() <= 2)
	{
		return 0;
	}

	int result = 0;
	deque<int> left;
	for (int i=0; i<height.size(); ++i)
	{
		if (left.empty() || height[i] < left.front())
		{
			left.push_back(height[i]);
		}
		else
		{
			while (!left.empty())
			{
				result += left.front() - left.back();
				left.pop_back();
			}

			left.push_back(height[i]);
		}
	}

	//
	deque<int> right;
	for (int i = left.size()-1; i >= 0; --i)
	{
		if (right.empty() || left[i] < right.front())
		{
			right.push_back(left[i]);
		}
		else
		{
			while (!right.empty())
			{
				result += right.front() - right.back();
				right.pop_back();
			}

			right.push_back(left[i]);
		}
	}

	return result;
}

TEST(LeetCode, tTrap)
{
	// 0 0
	// 0,1,0,2,1,0,1,3,2,1,2,1

	int d1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> v1(d1,d1+_countof(d1));

	ASSERT_EQ(trap(v1),6);
}