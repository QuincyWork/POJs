#include <gtest/gtest.h>
using namespace std;

vector<int> productExceptSelf1(vector<int>& nums)
{
	vector<int> result;
	long long val = 1;
	for (int i=0; i<nums.size(); ++i)
	{
		val *= nums[i];
	}

	for (int i=0; i<nums.size(); ++i)
	{
		result.push_back(val / nums[i]);
	}

	return result;
}

int GetProducts(int pred, int index, vector<int>& nums, vector<int>& result)
{	
	if (index < 0 )
	{
		return 1;
	}

	int value = GetProducts(pred * nums[index], index-1, nums, result);
	result.push_back(pred * value);

	return value * nums[index];
}

vector<int> productExceptSelf(vector<int>& nums)
{
	vector<int> result;
	GetProducts(1,nums.size() - 1,nums,result);

	return result;
}

TEST(LeetCode, tProductExceptSelf)
{
	int d1[] = {1,2,3,4};
	vector<int> v1(d1, d1+_countof(d1));
	vector<int> result = productExceptSelf(v1);


}