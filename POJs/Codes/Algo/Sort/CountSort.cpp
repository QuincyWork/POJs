#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

// 元素值可以直接用作索引值，并行不考虑相同值元素先后关系
// 这样可以节省以排序数据的辅助空间
void CountingSort2(int* data, int size, int max)
{
	int* counts = new int[max];
	memset(counts, 0, max * sizeof(int));

	for (int i=0; i<size; ++i)
	{
		counts[data[i]]++;
	}

	int index = 0;
	for (int i=0; i<max; i++)
	{
		while(counts[i]-- > 0)
		{
			data[index++] = i;
		}
	}

	delete[] counts;
}

// 计数排序
int ConvDataToIndex(float data, int max)
{
	return (int)(data * 10);
}

template<typename T, typename F>
void CountingSort(T* data, int size, int max, F conv)
{
	int* counts = new int[max];	//计数数组
	T*   sorted = new T[size];	//排序缓存

	memset(counts, 0, max*sizeof(int));

	for (int i = 0; i<size; ++i)
	{
		counts[conv(data[i], max)]++;
	}

	for (int i = 1; i<max; ++i)
	{
		counts[i] += counts[i-1];
	}

	for (int i = size-1; i >=0; --i )
	{
		int j = --counts[conv(data[i], max)];
		sorted[j] = data[i];
	}

	memcpy(data, sorted, size * sizeof(T));
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
	
	float d4[] = {0, 1.2, 3.1, 4.0, 1.5, 2.6, 10.4, 9.7, 8.2};
	CountingSort(d4, 9, 105, ConvDataToIndex);
	for_each(d4, d4+9, ShowElem<float>);
	ASSERT_TRUE(Validate(d4,9));
	cout << endl;

	int d1[] = {2,8,7,1,3,5,6,4};
	CountingSort2(d1, 8, 9);
	for_each(d1, d1+8, ShowElem<int>);	
	ASSERT_TRUE(Validate(d1,8));	
	cout << endl;

	int d2[] = {2};
	CountingSort2(d2, 1, 3);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,1));
	cout << endl;

	int d3[] = {2,4,5,6,7,5,2,3,5,7,10,111,2,4,5,6,3,4,5};
	CountingSort2(d3, 19, 112);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,19));
	cout << endl;
}