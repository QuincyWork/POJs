#include <gtest/gtest.h>
using namespace std;


void nextSteps(int left, int n, int&step)
{
	if (left > n)
	{
		return;
	}
	else if (left == n)
	{
		step++;
	}
	else
	{
		nextSteps(left+1,n,step);
		nextSteps(left+2,n,step);
	}
}

int climbStairs(int n)
{
	//int steps = 0;
	//nextSteps(0,n, steps);

	//return steps;
	int stepA = 1;
	int stepB = 1;
	for (int i = 2; i<=n; ++i)
	{
		int temp = stepB;
		stepB = stepA + stepB;
		stepA = temp;
	}

	return stepB;
}

TEST(Pratices, tClimbStairs)
{
	ASSERT_EQ(climbStairs(4),5);
	ASSERT_EQ(climbStairs(20),10946);
}