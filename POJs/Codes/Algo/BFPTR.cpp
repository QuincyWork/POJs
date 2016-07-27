#include <gtest/gtest.h>
using namespace std;



template<typename T>
int BFPRT(T* data, int low, int high, int n)
{
	int num = FindMid(data, low, high);
	int p = FindId(data, low, high, num);
	int i = Partion(data, low, high, p);

	int m = i - low + 1;
	if (m = n)
	{
		return data[i];
	}

	if (m > n)
	{
		return BFPRT(data, low, i-1, n);
	}
	else
	{
		return BFPRT(data, i+1, high, n);
	}
}