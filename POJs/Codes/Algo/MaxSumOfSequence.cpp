#include <gtest/gtest.h>
using namespace std;

int MaxSumOfSequence(int* pData, int nLength, int& nBegin, int& nEnd)
{
	if (!pData || !nLength)
	{
		return 0;
	}

	int nMaxSum = 0;
	int nCurrVal = 0;
	int nCurrBegin = 0;

	for (int i = 0; i < nLength; ++i)
	{
		nCurrVal += pData[i];
		if (nCurrVal >= nMaxSum)
		{
			nMaxSum = nCurrVal;
			nBegin = nCurrBegin;
			nEnd = i;
		}

		if (nCurrVal < 0)
		{			
			nCurrVal = 0;
			nCurrBegin = i+1;
		}
	}

	return nMaxSum;
}

TEST(Algo, tMaxSumOfSequence)
{
	// 	
	// 5,-6,4,2	
	// 5,-4,4,2	
	// 5,4,-10,2	
	
	int Data1[] = {5,-6,4,2};
	int nBegin = 0;
	int nEnd = 0;

	ASSERT_EQ(MaxSumOfSequence(Data1,4,nBegin,nEnd),6);
	ASSERT_TRUE(nBegin==2 && nEnd==3);

	int Data2[] = {5,-4,4,2};
	ASSERT_EQ(MaxSumOfSequence(Data2,4,nBegin,nEnd),7);
	ASSERT_TRUE(nBegin==0 && nEnd==3);

	int Data3[] = {5,4,-10,2};
	ASSERT_EQ(MaxSumOfSequence(Data3,4,nBegin,nEnd),9);
	ASSERT_TRUE(nBegin==0 && nEnd==1);
}
