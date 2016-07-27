#include <gtest/gtest.h>
using namespace std;

// 全排列

void Swap(int* v1, int* v2)
{
	if (v1 == v2)
		return;

	int value = *v1;
	*v1 = *v2;
	*v2 = value;
}

void ShowResult(int data[], int size, int count)
{
	for (int i = 0; i < size; ++i)
	{
		cout << data[i] << " ";
	}

	if (count % 8 == 0)
	{
		cout << endl;
	}
	else
	{
		cout << "  ";
	}
}

void Permutation(int data[], int begin, int end, int& count)
{	
	if (begin < end)
	{
		for (int i = begin; i < end; ++i)
		{
			Swap(&data[begin], &data[i]);
			Permutation(data, begin+1, end, count);
			Swap(&data[begin], &data[i]);
		}
	}
	else
	{
		++count;
		ShowResult(data, end ,count);
	}
}

TEST(Algo, tPermutation)
{
	int data[] = {1,2,3,4};
	int nCount = 0;

	// 4个数 4! = 24
	Permutation(data, 0, 4, nCount);
	ASSERT_EQ(nCount, 24);

	// 5个数 5! = 120
	int data1[] = {1,2,3,4,5};
	nCount = 0;
	Permutation(data1, 0, 5, nCount);
	ASSERT_EQ(nCount, 120);

	// 6个数 6! = 720
	int data2[] = {1,2,3,4,5,6};
	nCount = 0;
	Permutation(data2, 0, 6, nCount);
	ASSERT_EQ(nCount, 720);
}