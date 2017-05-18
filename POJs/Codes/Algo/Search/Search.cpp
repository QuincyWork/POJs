#include <gtest/gtest.h>
#include <list>
using namespace std;

namespace SequentialSearch
{
	int Search(vector<int>& A, int key)
	{
		int result = -1;
		for (int i=0; i<A.size(); ++i)
		{
			if (A[i]==key)
			{
				result = i;
				break;
			}
		}

		return result;
	}
}

// Binary Search
namespace BinarySearch
{	
	int Search(vector<int>& A, int key)
	{
		int result = -1;
		int left = 0;
		int right = A.size()-1;
		while(left <= right)
		{
			int mid = left+(right-left)/2;
			if (key == A[mid])
			{
				result = mid;
				break;
			}

			if (key < A[mid])
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}

		return result;
	}
}

namespace InterpolationSearch
{
	int Search(vector<int>& A, int key)
	{
		int result = -1;
		int left = 0;
		int right = A.size()-1;
		
		while(left <= right)
		{
			int mid = left + (right-left)* (key-A[left]) / (A[right]-A[left]);
			if (A[mid] == key)
			{
				result = mid;
				break;
			}
			else if(A[mid] > key)
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}

		return result;
	}
}

namespace HashSearch
{
	int Search(vector<int>& A, int key)
	{
		int result = -1;
		vector<int> B(A.size(),-1);
		for(int i=0; i < A.size(); ++i)
		{
			int pos = A[i] % A.size();
			while (B[pos] != -1)
			{
				pos = ++pos % A.size();
			}

			B[pos] = i;
		}

		int idx = key % A.size();
		int step = 0;
		while((step < A.size()) && (B[idx] != -1) && (A[B[idx]] != key))
		{
			idx = ++idx % A.size();
			++step;
		}

		if (A[B[idx]]==key)
		{
			result = B[idx];
		}

		return result;
	}

	int Search2(vector<int>& A, int key)
	{
		int result = -1;
		vector<vector<int>> B(A.size());
		for (int i=0; i<A.size(); ++i)
		{
			B[A[i] % A.size()].push_back(i);
		}

		int idx = key % A.size();
		int pos = 0;
		while(pos < B[idx].size() && (key != A[B[idx][pos]]))
		{
			pos++;
		}

		if (key == A[B[idx][pos]])
		{
			result = pos;
		}

		return result;
	}
}

TEST(Algo, tSerach)
{
	int d1[] = {3,4,5,2,1,7,8,9,20,22,11,10};
	int result = SequentialSearch::Search(vector<int>(d1,d1+_countof(d1)),8);
	ASSERT_EQ(result,6);

	//int d2[] = {1,3,5,6,7,9,10,22,31,40,56,71,89,100,120,132,144,156,178,190,191};
	int d2[] = {1,3,5};
	result = BinarySearch::Search(vector<int>(d2,d2+_countof(d2)),5);
	ASSERT_EQ(result,2);

	int d3[] = {1,3,5,6,7,9,10,22,31,40,56,71,89,100,120,132,144,156,178,190,191};
	result = InterpolationSearch::Search(vector<int>(d3,d3+_countof(d3)),100);
	ASSERT_EQ(result,13);

	int d4[] = {1,3,5,6,7,9,10,22,31,40,56,71,89,100,120,132,144,156,178,190,191};
	result = HashSearch::Search(vector<int>(d4,d4+_countof(d4)),900);
	ASSERT_EQ(result,-1);
}