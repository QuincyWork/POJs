#include <gtest/gtest.h>
#include <set>
#include <algorithm>
using namespace std;

void combinationSum(vector<int>& candidates, int target, int currentIdx, int currentVal, vector<int>& select, set<vector<int>>& result)
{	
	if (currentIdx < candidates.size())
	{			
		int temp = candidates[currentIdx];
		if (currentVal == target)
		{
			result.insert(select);
		}

		if (currentVal > target)
		{
			return;
		}

		// 当前不选择
		combinationSum(candidates, target, currentIdx+1, currentVal, select, result);
				
		select.push_back(temp);		
		// 当前重复选择
		combinationSum(candidates, target, currentIdx, currentVal + temp, select, result);

		// 当前选择一次
		combinationSum(candidates, target, currentIdx+1, currentVal + temp, select, result);
		select.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	set<vector<int>> result;
	vector<int> select;
	combinationSum(candidates, target, 0, 0, select, result);
	return vector<vector<int>>(result.begin(), result.end());
}

void combinationSum1(vector<int>& candidates, int target, int currentIdx, int currentVal, vector<int>& select, vector<vector<int>>& result)
{
	if (currentVal == target)
	{
		result.push_back(select);
	}

	for (int i= currentIdx; i < candidates.size() && currentVal < target; ++i)
	{
		int temp = candidates[i];
		select.push_back(temp);
		combinationSum1(candidates, target, i, currentVal+temp, select, result);
		select.pop_back();
	}
};

vector<vector<int>> combinationSum1(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());

	vector<vector<int>> result;
	vector<int> select;
	combinationSum1(candidates, target, 0, 0, select, result);

	return result;
}


TEST(LeetCode, tCombinationSum)
{
	int d1[] = {2, 3, 6, 7};
	vector<int> v1(d1, d1+_countof(d1));

	vector<vector<int>> result = combinationSum1(v1, 7);



}