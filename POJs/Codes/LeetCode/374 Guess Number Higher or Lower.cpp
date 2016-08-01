#include <gtest/gtest.h>
using namespace std;

// Leet Code
// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/

int nPickedData = 0;

int guess(int num)
{
	int result = 0;
	if (num > nPickedData)
	{
		result = -1;
	}
	else if(num < nPickedData)
	{
		result = 1;
	}

	return result;
}

int guessNumber(int n)
{
	int left = 1;
	int right = n;
	int mid = 1;
	while (left <= right)
	{
		mid = left + (right - left)/2;
		switch (guess(mid))
		{
		case 0:
			return mid;

		case -1:
			right = mid-1;
			break;

		case 1:
			left = mid+1;
			break;
		}		
	}

	return mid;
}

TEST(LeetCode, tGuessNumber)
{
	nPickedData = 6;
	ASSERT_EQ(guessNumber(10),nPickedData);

	nPickedData = 1;
	ASSERT_EQ(guessNumber(2001),nPickedData);
}