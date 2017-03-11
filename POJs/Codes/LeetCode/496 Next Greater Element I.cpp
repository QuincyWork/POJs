#include <gtest\gtest.h>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement1(vector<int>& findNums, vector<int>& nums)
{
	map<int, int> cachetbl;
	for (int i=0; i<nums.size(); ++i)
	{
		cachetbl[nums[i]] = i;
	}

	vector<int> result;
	for (int i = 0; i < findNums.size(); ++i)
	{
		int index = cachetbl.count(findNums[i]) ? cachetbl[findNums[i]] : -1;
		if (index == -1)
		{
			result.push_back(-1);
		}
		else
		{
			int value = -1;
			for (; index < nums.size(); ++index)
			{
				if (findNums[i] < nums[index])
				{
					value = nums[index];
					break;
				}
			}

			result.push_back(value);
		}
	}

	return result;
}

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
	stack<int> top;
	unordered_map<int, int> m;

	for (int n : nums)
	{
		while (top.size() && top.top() < n)
		{
			m[top.top()] = n;
			top.pop();
		}

		top.push(n);
	}

	vector<int> res;
	for (int n : findNums)
	{
		res.push_back(m.count(n) ? m[n] : -1);
	}

	return res;
}

TEST(LeetCode, tNextGreaterElement)
{
	//4,1,2  1,3,4,2 => -1,3,-1
	int d1[] = { 4,1,2 };
	vector<int> v1(d1, d1 + _countof(d1));

	int d2[] = { 1,3,4,2 };
	vector<int> v2(d2, d2 + _countof(d2));

	vector<int> result = nextGreaterElement(v1, v2);



}