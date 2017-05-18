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

// Quick Sort
namespace QuickSort
{
	int Partition(int A[], int left, int right)
	{		
		int pos = left;
		for(int i=left; i<right; ++i)
		{
			if (A[i] <= A[right])
			{
				Swap(A[i],A[pos++]);
			}
		}

		Swap(A[pos],A[right]);
		return pos;
	}

	void QuickSort(int A[], int left, int right)
	{
		if (left >= right)
		{
			return;
		}

		int p = Partition(A,left,right);
		QuickSort(A,left,p-1);
		QuickSort(A,p+1,right);
	}

	void Sort(int A[], int N)
	{
		QuickSort(A,0,N-1);
	}
}

namespace HeapSort
{
	void Heapify(int A[], int idx, int N)
	{
		int left = 2*idx + 1;
		int right = 2*idx + 2;
		int largest = idx;
		if (left < N && A[left] > A[largest])
		{
			largest = left;
		}

		if (right < N && A[right] > A[largest])
		{
			largest = right;
		}

		if (largest != idx)
		{
			Swap(A[largest],A[idx]);
			Heapify(A,largest,N);
		}
	}

	void BuildHeap(int A[], int N)
	{
		for (int i = N/2-1; i >=0; --i)
		{
			Heapify(A,i,N);
		}
	}

	void Sort(int A[], int N)
	{
		BuildHeap(A,N);
		for (int i=N-1; i>=1; --i)
		{
			Swap(A[i],A[0]);
			Heapify(A,0,i);
		}
	}
}

namespace CountSort
{
	void Sort(int A[], int N, int MAX)
	{
		int* counts = new int[MAX];
		int* sorted = new int[N];
		memset(counts,0,MAX*sizeof(int));
		for(int i=0; i<N; ++i)
		{
			counts[A[i]]++;
		}

		for(int i=1 ; i<MAX; ++i)
		{
			counts[i] += counts[i-1];
		}

		for (int i=N-1; i>=0; --i)
		{
			int pos = --counts[A[i]];
			sorted[pos] = A[i];
		}

		memcpy(A,sorted,N*sizeof(int));
		delete counts;
		delete sorted;
	}
}

namespace RadixSort
{
	void Sort(vector<int>& A, int max, int b)
	{
		int base = 1;

		for (int n = 0; n < max; ++n)
		{
			// Count Sort
			vector<int> counts(b,0);
			vector<int> sorted(A.size(),0);

			for (int i=0; i<A.size(); ++i)
			{
				counts[(A[i] / base) % b]++;
			}

			for (int i=1; i<counts.size(); ++i)
			{
				counts[i] += counts[i-1];
			}

			for (int i=A.size()-1; i>=0; --i)
			{
				int pos = --counts[(A[i] / base) % b];
				sorted[pos] = A[i];
			}

			base = base * b;
			A = sorted;
		}
	}
}

namespace BucketSort
{
	int  BucketHash(int value)
	{
		return value / 10;
	}

	void InsertSort(vector<int>& A)
	{		
		for (int i=1; i<A.size(); ++i)
		{
			int value = A[i];
			int j = i-1;
			while (j>=0 && A[j] > value)
			{
				A[j+1] = A[j];
				j--;
			}

			A[j+1]=value;
		}
	}

	void Sort(vector<int>& A, int K)
	{
		vector<vector<int>> Buckets(K);
		for (int i=0; i<A.size(); ++i)
		{
			Buckets[BucketHash(A[i])].push_back(A[i]);
		}

		int idx = 0;
		for (int i=0; i<K; ++i)
		{
			InsertSort(Buckets[i]);
			for (int j=0; j<Buckets[i].size(); ++j)
			{
				A[idx++] = Buckets[i][j];
			}
		}
	}
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

	int d4[] = {4,5,2,34,6,2,3,8,7,1,2,3,6,7,9,3,4,6,2};
	QuickSort::Sort(d4,_countof(d4));

	int d5[] = {4,3,1,23,5,6,2,2,3,44,1,9,7,0,123,3,34,1,36,7,10};
	HeapSort::Sort(d5,_countof(d5));

	int d6[] = {4,3,1,23,5,6,2,2,3,44,1,9,7,0,123,3,34,1,36,7,10};
	CountSort::Sort(d6,_countof(d6),130);

	int d7[] = {4,3,1,23,5,6,2,2,3,44,1,9,7,0,123,3,34,1,36,7,10};	
	RadixSort::Sort(vector<int>(d7,d7+_countof(d7)),3,10);

	int d8[] = {4,3,1,23,5,6,2,2,3,44,1,9,7,0,123,3,34,1,36,7,10};	
	BucketSort::Sort(vector<int>(d8,d8+_countof(d8)),20);
}