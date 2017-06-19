#include <gtest/gtest.h>
using namespace std;


int EditDistance(const string& A,const string& B)
{
	int length = (A.size()+1) * (B.size()+1);
	int* edTable = new int[length];
	memset(edTable,0,length*sizeof(int));

	for (int i=0; i <A.size(); ++i)
	{
		edTable[i+1] = i+1;
	}

	for (int i=0; i<B.size(); ++i)
	{
		edTable[(i+1)*(A.size()+1)] = i+1;
	}

	// Modify Table

	for (int i=1; i<=B.size(); ++i)
	{
		for (int j=1; j<=A.size(); ++j)
		{
			int d1 = edTable[(i-1)*(A.size()+1)+(j-1)] + (B[i-1] == A[j-1] ? 0 : 1);
			int d2 = edTable[(i-1)*(A.size()+1)+j] + 1;
			int d3 = edTable[(i)*(A.size()+1)+(j-1)] + 1;
			int minValue = d1;
			if (minValue > d2)
			{
				minValue = d2;
			}
			if (minValue > d3)
			{
				minValue = d3;
			}
			edTable[i*(A.size()+1)+j] = minValue;
		}
	}
	
	int result = edTable[length-1];
	delete edTable;

	return result;
}

// 一种节省空间的方法
// 在构造这个二维矩阵的过程中由于得出矩阵的某一行后其上一行就没用了，所以实际上在程序中可以用一维数组来代替这个矩阵
// 如果把strB的长度假设为短的那个字符串，空间更少
int EditDistance2(const string& A, const string& B)
{
	int length = A.size()+1;
	int* edPreRow = new int[length];
	int* edCurRow = new int[length];
	memset(edPreRow,0,length*sizeof(int));
	memset(edCurRow,0,length*sizeof(int));

	for (int i=0; i <A.size(); ++i)
	{
		edPreRow[i+1] = i+1;
		edCurRow[i+1] = i+1;
	}

	for (int i=1; i<=B.size(); ++i)
	{
		edCurRow[0] = i;
		for (int j=1; j<=A.size(); ++j)
		{
			int d1 = edPreRow[j-1] + (B[i-1] == A[j-1] ? 0 : 1);
			int d2 = edPreRow[j] + 1;
			int d3 = edCurRow[j-1] + 1;
			int minValue = d1;
			if (minValue > d2)
			{
				minValue = d2;
			}
			if (minValue > d3)
			{
				minValue = d3;
			}
			edCurRow[j] = minValue;
		}

		memcpy(edPreRow,edCurRow,length*sizeof(int));
	}

	int result = edCurRow[length - 1];
	delete edPreRow;
	delete edCurRow;

	return result;
}

TEST(Algo,tEditDistance)
{
	ASSERT_EQ(EditDistance2("zero","ero"), 1);
	ASSERT_EQ(EditDistance2("zero","fero"), 1);
	ASSERT_EQ(EditDistance2("abcddefg","abcefg"), 2);
	ASSERT_EQ(EditDistance2("abcddefg","abcddefg"), 0);
	ASSERT_EQ(EditDistance2("abcddfg","abcddefg"), 1);
	ASSERT_EQ(EditDistance2("",""), 0);
	ASSERT_EQ(EditDistance2("abcdefgh",""), 8);
	ASSERT_EQ(EditDistance2("","abcdefgh"), 8);
}