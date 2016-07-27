#include <gtest\gtest.h>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int areaA = (C-A)*(D-B);
	int areaB = (G-E)*(H-F);

	int cL = max(A,E);
	int cB = max(B,F);
	int cR = min(C,G);
	int cT = min(D,H);

	int value = areaA+areaB;
	if (cR > cL && cT > cB)
	{
		value -= (cR-cL) * (cT-cB);
	}

	return value;
}

TEST(Pratices, tComputeArea)
{
	ASSERT_EQ(computeArea(-2,-2,2,2,-2,-2,2,2),16);
	ASSERT_EQ(computeArea(-2,-2,0,0,0,0,2,2),8);
}