#include <gtest/gtest.h>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

double MonteCarloPI(int nSize)
{
	int nCount = 0;
	double x,y;

	srand((unsigned int)time(NULL));
	for (int i=0; i<nSize; ++i)
	{
		x = (double) rand() / RAND_MAX;
		y = (double) rand() / RAND_MAX;

		if ((x * x + y * y) < 1)
		{
			++nCount;
		}
	}

	return (double)nCount * 4 / nSize;
}

TEST(Algo, tMonteCarloPI)
{		
	double dValue = MonteCarloPI(500);
	//ASSERT_GT(dValue,3.0);
	//ASSERT_LT(dValue,3.2);
	cout << "N:500 " << dValue << endl;

	dValue = MonteCarloPI(5000);
	//ASSERT_GT(dValue,3.0) << dValue;
	//ASSERT_LT(dValue,3.2);
	cout << "N:5000 " << dValue << endl;

	dValue = MonteCarloPI(50000);
	//ASSERT_GT(dValue,3.0) << dValue;
	//ASSERT_LT(dValue,3.2);
	cout << "N:50000 " << dValue << endl;

	dValue = MonteCarloPI(500000);
	//ASSERT_GT(dValue,3.0) << dValue;
	//ASSERT_LT(dValue,3.2);
	cout << "N:500000 " << dValue << endl;
}