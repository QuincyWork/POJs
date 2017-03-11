#include <gtest\gtest.h>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums)
{
	stack<pair<int, int>> t;
	vector<int> m(nums.size(),-1);

	for (int i = 0; i < nums.size(); ++i)
	{
		int n = nums[i];
		while (t.size() && t.top().first < n)
		{
			m[t.top().second] = n;
			t.pop();
		}

		t.push(make_pair(n, i));
	}

	for (int i = 0; i < nums.size() && !t.empty(); ++i)
	{
		int n = nums[i];
		while (t.size() && 
			   t.top().first < n && 
			   i < t.top().second)
		{
			m[t.top().second] = n;
			t.pop();
		}
	}

	return m;
}

TEST(LeetCode, tNextGreaterElements)
{
	// 1,2,1 => 2,-1,2
	// [100,1,11,1,120,111,123,1,-1,-100] => [120, 11, 120, 120, 123, 123, -1, 100, 100, 100]
	int d1[] = { 100,1,11,1,120,111,123,1,-1,-100 };
	vector<int> v1(d1, d1 + _countof(d1));
	vector<int> result = nextGreaterElements(v1);
}