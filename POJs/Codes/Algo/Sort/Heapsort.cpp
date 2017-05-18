#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

#define M_PARENT(i)		(i)/2
#define M_LEFT(i)		2*(i)+1
#define M_RIGHT(i)		2*(i+1)

template<typename T>
void MaxHeapify(T* data, int index, int len)
{
	int l = M_LEFT(index);
	int r = M_RIGHT(index);
	int largest;

	if (l < len && data[l] > data[index])
	{
		largest = l;
	}
	else
	{
		largest = index;
	}

	if (r < len && data[r] > data[largest])
	{
		largest = r;
	}

	if (largest != index)
	{
		T tmp = data[largest];
		data[largest] = data[index];
		data[index] = tmp;

		MaxHeapify(data, largest, len);
	}
}

template<typename T>
void BuildMaxHeap(T* data, int len)
{
	if (!data || len <= 1)
		return;

	for (int i=len/2 + 1; i>=0; --i)
	{
		MaxHeapify(data,i,len);
	}
}

template<typename T>
void HeapSort(T* data, int len)
{
	if (!data || len <= 1)
	{
		return;
	}

	BuildMaxHeap(data, len);

	for (int i=len-1; i>=1; --i)
	{
		T tmp = data[0];
		data[0] = data[i];
		data[i] = tmp;

		MaxHeapify(data,0,--len);
	}
}

// Helper function
template<typename T>
void ShowElem(T& val)
{
	cout << val << " ";
}

template<typename T>
bool Validate(T* data, int len)
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

TEST(Algo, tHeapSort)
{
	int d1[] = {2,8,7,1,3,5,6,4};
	HeapSort(d1, 8);
	for_each(d1, d1+8, ShowElem<int>);	
	ASSERT_TRUE(Validate(d1,8));	
	cout << endl;

	int d2[] = {2};
	HeapSort(d2, 1);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,1));
	cout << endl;

	int d3[] = {2,4,5,6,7,5,2,3,5,7,10,111,2,4,5,6,3,4,5};
	HeapSort(d3, 19);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,19));
	cout << endl;
}