#include <gtest/gtest.h>
using namespace std;

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

// Selection Sort
namespace SelectionSort
{
	int SelectMax(int A[], int P, int N)
	{
		int maxIdx = P;
		int maxValue = A[P];
		while (P < N)
		{
			if (A[P] > maxValue)
			{
				maxValue = A[P];
				maxIdx = P;
			}

			++P;
		}

		return maxIdx;
	}

	void Sort(int A[], int N)
	{		
		for (int i=0; i<N ; ++i)
		{
			int pos = SelectMax(A,i,N);
			if (pos != i)
			{
				Swap(A[i], A[pos]);
			}
		}
	}
}

// Merge Sort
namespace MergeSort 
{
	// ¼õÉÙ¿Õ¼ä
	void Merge2(int A[], int left, int mid, int right)
	{
		int length = mid-left+1;
		int* B = new int[length];
		memcpy(B,A+left,sizeof(int)*length);

		int index = 0;		
		int m = 0;
		int n = mid+1;
		while ((m < length) && (n <= right))
		{
			if (B[m] > A[n])
			{
				A[left+index++] = A[n++];
			}
			else
			{
				A[left+index++] = B[m++];
			}
		}

		while(m < length)
		{
			A[left+index++] = B[m++];
		}

		delete[] B;
	}

	void Merge(int A[], int left, int mid, int right)
	{
		int* B = new int[right-left+1];		
		int index = 0;
		int m = left;
		int n = mid+1;
		while ((m <= mid) && (n <= right))
		{
			if (A[m] > A[n])
			{
				B[index++] = A[n++];
			}
			else
			{
				B[index++] = A[m++];
			}
		}

		while (m<=mid)
		{
			B[index++] = A[m++];
		}
		
		while(n<=right)
		{
			B[index++] = A[n++];
		}
		
		for (int i=0; i<index; ++i)
		{
			A[left+i] = B[i];
		}

		delete[] B;
	}

	void MergeSort(int A[], int left, int right)
	{
		if (left >= right)
		{
			return;
		}

		int mid = left + (right-left)/2;
		MergeSort(A,left,mid);
		MergeSort(A,mid+1,right);
		//Merge(A,left,mid,right);
		Merge2(A,left,mid,right);
	}

	void Sort(int A[], int N)
	{
		MergeSort(A,0,N-1);
	}
}

namespace MergeSort2
{
	void Merge(int A[], int mid, int n)
	{		
		int* B = new int[mid];
		memcpy(B,A,sizeof(int)*mid);

		int index = 0;		
		int i = 0;
		int j = mid;
		while ((i < mid) && (j < n))
		{
			if (B[i] > A[j])
			{
				A[index++] = A[j++];
			}
			else
			{
				A[index++] = B[i++];
			}
		}

		while(i < mid)
		{
			A[index++] = B[i++];
		}

		delete[] B;
	}

	void MergeSort(int A[], int n)
	{
		if (n <= 1)
		{
			return;
		}

		int mid = n / 2;
		MergeSort(A,mid);
		MergeSort(A+mid,n-mid);		
		Merge(A,mid,n);
	}

	void Sort(int A[], int N)
	{
		MergeSort(A,N);
	}
}

namespace ShellSort
{

	void Sort(int A[], int N)
	{
		for (int d=N/2; d >= 1; d = d/2)
		{
			for (int i=d; i<N; i++)
			{	
				int j = i-d;
				int value = A[i];
				while (j >=0 && value < A[j])
				{
					A[j+d] = A[j];
					j -= d;
				}

				A[j+d] = value;
			}
		}
	}	
}

namespace QuickSort
{

}


TEST(Algo,tSort)
{
	int d1[] = {1,4,5,2,3,9,0,1};
	SelectionSort::Sort(d1,_countof(d1));

	int d2[] = {3,4,2,3,6,1,6,7,4,3,10,13,3,15};
	//MergeSort::Sort(d2,_countof(d2));
	MergeSort2::Sort(d2,_countof(d2));

	int d3[] = {4,5,2,34,6,2,3,8,7,1,2,3,6,7,9,3,4,6,2};
	ShellSort::Sort(d3,_countof(d3));	
}