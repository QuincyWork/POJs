#include <gtest/gtest.h>
#include <iostream>
#include <string>
using namespace std;

int CalcDistance(const string& A, int offsetA,const string& B, int offsetB)
{
	if (A.size() == offsetA)
	{
		return B.size() - offsetB;		
	}

	if (B.size() == offsetB)
	{
		return A.size() - offsetA;
	}

	if (A[offsetA] == B[offsetB])
	{
		return CalcDistance(A, offsetA+1, B, offsetB + 1);
	}
	else
	{
		int dist1 = CalcDistance(A, offsetA, B, offsetB + 1);
		int dist2 = CalcDistance(A, offsetA + 1, B, offsetB);
		int dist3 = CalcDistance(A, offsetA + 1, B, offsetB + 1);
		int result = dist1 < dist2 ? dist1 : dist2;
		result = result < dist3 ? result : dist3;

		return result + 1;
	}
}

int main_modify()
{
	return 0;
}

TEST(BaiLian, tLevenshtein)
{		
	ASSERT_EQ(CalcDistance("zero",0,"ero",0), 1);
	ASSERT_EQ(CalcDistance("zero",0,"fero",0), 1);
	ASSERT_EQ(CalcDistance("abcddefg",0,"abcefg",0), 2);
	ASSERT_EQ(CalcDistance("abcddefg",0,"abcddefg",0), 0);
	ASSERT_EQ(CalcDistance("abcddfg",0,"abcddefg",0), 1);
	ASSERT_EQ(CalcDistance("",0,"",0), 0);
	ASSERT_EQ(CalcDistance("abcdefgh",0,"",0), 8);
	ASSERT_EQ(CalcDistance("",0,"abcdefgh",0), 8);
}