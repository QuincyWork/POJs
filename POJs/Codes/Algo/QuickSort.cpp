#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

template<typename T>
int Partition(T* data, int low, int high)
{
	T pivot = data[high];
	int i = low - 1;
	int tmp;
	for (int j = low; j < high; j++)
	{
		if (data[j] < pivot)
		{
			tmp = data[++i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}

	tmp = data[i+1];
	data[i+1] = data[high];
	data[high] = tmp;
	return i+1;
}

template<typename T>
void QSort(T* data, int low, int high)
{
	if (low < high)
	{
		int mid = Partition(data, low, high);
		QSort(data, low, mid - 1);
		QSort(data, mid + 1, high);
	}
}

// Helper function
template<typename T>
void ShowElem(T& val)
{
	cout << val << " ";
}

template<typename T>
bool Validate(T* data, int low, int high)
{
	for (int i=low; i < high; ++i)
	{
		if (data[i] > data[i+1])
		{
			return false;
		}
	}

	return true;
}

TEST(Algo, tQSort)
{
	int d1[] = {2,8,7,1,3,5,6,4};
	QSort(d1, 0, 7);
	for_each(d1, d1+8, ShowElem<int>);	
	ASSERT_TRUE(Validate(d1,0,7));	
	cout << endl;

	int d2[] = {2};
	QSort(d2, 0, 0);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,0,0));
	cout << endl;

	int d3[] = {2,4,5,6,7,5,2,3,5,7,10,111,2,4,5,6,3,4,5};
	QSort(d3, 0, 18);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,0,18));
	cout << endl;	
}