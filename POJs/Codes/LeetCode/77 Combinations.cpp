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

//��Щ�Ӽ��Ѿ�ʹ���ֵ�˳�����У���˲ſ��Թ۲��һЩ����
//	�������һ��Ԫ��С��m������ͬ���һ���Ĳ��ϼ�1
//	����ұ�һλ�������ֵ�����1��λ��������
//	ÿ�μ�1��λ�������ƺ󣬱������µ����ұߵ�Ԫ��Ϊ�ݼ�˳��

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