#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

template<typename T>
void InsertSort(T* data, int low, int high)
{
	for (int i = low + 1; i <= high; ++i)	//第一个元素为有序
	{
		if (data[i-1] > data[i])
		{
			T val = data[i];
			int j = i;

			while (j > low && data[j-1] > val) //将比data[i]大的数据向后移
			{
				data[j] = data[j-1];
				--j;
			}

			data[j] = val;
		}
	}
}

// helper function
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

TEST(Algo, tInsertSort)
{
	int d1[] = {2,8,7,1,3,5,6,4};
	InsertSort(d1, 0, 7);
	for_each(d1, d1+8, ShowElem<int>);	
	ASSERT_TRUE(Validate(d1,8));	
	cout << endl;

	int d2[] = {2};
	InsertSort(d2, 0,0);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,1));
	cout << endl;

	int d3[] = {2,4,5,6,7,5,2,3,5,7,10,111,2,4,5,6,3,4,5};
	InsertSort(d3, 0, 18);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,19));
	cout << endl;
}