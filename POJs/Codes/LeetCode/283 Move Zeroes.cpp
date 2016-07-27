#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/

void moveZeroes1(vector<int>& nums)
{
	int first = -1;	// first zero index
	int last = -1;	// last zero index + 1

	for (size_t i=0; i<nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			if (last > first)
			{				
				nums[first++] = nums[i];
				nums[i] = 0;
				last++;
			}
		}
		else
		{
			if (first == -1)
			{
				first = i;
			}
			
			last = i+1;
		}
	}
}

void moveZeroes(vector<int>& nums)
{
	size_t nZero = 0;
	for (size_t i=0; i< nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			if (i > nZero)
			{
				nums[nZero++] = nums[i];
				nums[i] = 0;
			}
			else
			{
				nZero++;
			}
		}
	}
}

TEST(LeetCode, tMoveZeroes)
{
	int data[] = {0, 1, 0, 3, 12,0,0,0,2,4,0,0,333,0,0,0};
	vector<int> vec(data,data+_countof(data));
	moveZeroes(vec);
}