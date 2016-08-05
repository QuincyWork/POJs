#include <gtest/gtest.h>
using namespace std;

// LeetCode
// 77. Combinations
// https://leetcode.com/problems/combinations/

void combine(int n, int k, int current, vector<int>& value, vector<vector<int>>& result)
{	
	int size = value.size();
	if (size == k)
	{
		result.push_back(value);
	}
	
	if (size < k && current <= n)
	{		
		combine(n, k, current+1, value, result);	
		value.push_back(current);
		combine(n, k, current+1, value, result);
		value.pop_back();
	}
}

 vector<vector<int>> combine1(int n, int k)
 {
	 vector<vector<int>> result;
	 combine(n,k,1,vector<int>(), result);

	 return result;
 }

//这些子集已经使用字典顺序排列，如此才可以观察出一些规则：
//	如果最右一个元素小于m，则如同码表一样的不断加1
//	如果右边一位已至最大值，则加1的位置往左移
//	每次加1的位置往左移后，必须重新调整右边的元素为递减顺序

 vector<vector<int>> combine(int n, int k)
 {
	 vector<vector<int>> result;
	 if (!n || !k)
	 {
		 return result;
	 }
	 
	 vector<int> current;
	 for (int i=0; i<k; i++)
	 {
		 current.push_back(i+1);
	 }

	 result.push_back(current);
	 int pos = k-1;

	 while (current[0] < n - k +1)
	 {
		 if (current[k - 1] == n)
		 {
			 pos--;
		 }
		 else
		 {
			 pos = k-1;
		 }

		 current[pos]++;
		 for (int i = pos+1; i<k; ++i)
		 {
			 current[i] = current[i-1] + 1;
		 }

		 result.push_back(current);
	 }

	 return result;
 }

 TEST(LeetCode, tCombine)
 {
	 vector<vector<int>> result = combine(4,2);
 }