#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

void RxSort(int* data, int size, int p, int k)
{
	int* counts = new int[k];
	int* sorted = new int[size];
	
	for (int n=0; n<p; n++)
	{
		memset(counts, 0, sizeof(int)*k);
		int qval = (int)pow((double)k, (double)n);
		
		// 计数排序
		for (int i=0; i<size; ++i)
		{
			counts[(int)(data[i]/qval) % k]++;
		}

		for (int i=1; i<k; ++i)
		{
			counts[i] += counts[i-1];
		}

		for (int i=size-1; i >=0; --i)
		{
			int index = (int)(data[i]/qval) % k;
			counts[index]--;
			sorted[counts[index]] = data[i];
		}

		memcpy(data, sorted, sizeof(int)*size);
		// 计数排序 End
	}

	delete[] counts;
	delete[] sorted;
}

// 辅助函数
template<typename T>
static void ShowElem(T& val)
{
	cout << val << " ";
}

template<typename T>
static bool Validate(T* data, int len)
{
	for (int i=0; i < len-1; ++i)
	{
		if (data[i] > data[i+1])
		{
			return false;
		}
	}

	return true;
}

//测试代码
TEST(Algo, tCountSort)
{	
	int d1[] = {2,82,73,11,12,85,6,4};
	RxSort(d1, 8, 2, 10);
	for_each(d1, d1+8, ShowElem<int>);	
	ASSERT_TRUE(Validate(d1,8));	
	cout << endl;

	int d2[] = {2};
	RxSort(d2, 1, 1, 10);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,1));
	cout << endl;

	int d3[] = {2,4,5,66,7,52,2,3,5,7,10,111,2,4,5,68,3,4,53};
	RxSort(d3, 19, 3, 10);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,19));
	cout << endl;
}