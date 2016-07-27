#include <gtest/gtest.h>
#include <algorithm>

using namespace std;

template<typename T>
void Merge(T* data, int low, int mid, int high)
{
	T* tmp = new T[high - low + 1];
	int i = low;
	int j = mid + 1;
	int k = 0;

	// �ѽ�С�������Ƶ��������� 
	while (i <= mid && j <= high)
	{
		if (data[i] < data[j])
		{
			tmp[k++] = data[i++];
		}
		else
		{
			tmp[k++] = data[j++];
		}
	}

	// �����ʣ�������������  
	while (i <= mid)
	{
		tmp[k++] = data[i++];
	}

	// ���ұ߱�ʣ�������������
	while (j <= high)
	{
		tmp[k++] = data[j++];
	}

	// ���������е�������nums����  
	for (int i = 0; i < k; ++i)
	{
		data[i+low] = tmp[i];
	}

	delete[] tmp;
}

template<typename T>
void MergeSort(T* data, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		// ���
		MergeSort(data, low, mid);
		// �ұ� 
		MergeSort(data, mid+1, high);
		// ���ҹ鲢
		Merge(data, low, mid, high);
	}
}

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

TEST(Algo, tMergeSort)
{
	int d1[] = {2,8,7,1,3,5,6,4};
	MergeSort(d1, 0, 7);
	for_each(d1, d1+8, ShowElem<int>);
	ASSERT_TRUE(Validate(d1,8));
	cout << endl;

	int d2[] = {2};
	MergeSort(d2, 0, 0);
	for_each(d2, d2+1, ShowElem<int>);
	ASSERT_TRUE(Validate(d2,1));
	cout << endl;

	int d3[] = {2,4,5,6,7,5,2,3,5,7,10,111,2,4,5,6,3,4,5};
	MergeSort(d3, 0, 18);
	for_each(d3, d3+19, ShowElem<int>);
	ASSERT_TRUE(Validate(d3,19));
	cout << endl;
}