#include <gtest/gtest.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// ±©¡¶±È¿˙
vector<int> twoSum1(vector<int>& nums, int target) 
{
	vector<int> results;
	for (int i=0; i< nums.size(); ++i)
	{
		for (int j=i+1; j < nums.size(); ++j)
		{
			if (nums[i]+nums[j] == target)
			{
				results.push_back(i);
				results.push_back(j);
				break;
			}
		}
	}

	return results;
};

// ª∫¥Ê”≥…‰
vector<int> twoSum2(vector<int>& nums, int target)
{
	vector<int> results;
	map<int, vector<int> > cache;
	bool find = false;

	for (unsigned int i=0; i<nums.size(); ++i)
	{	
		cache[nums[i]].push_back(i);		
	}

	for (unsigned int i=0; i<nums.size(); ++i)
	{
		map<int, vector<int> >::const_iterator it = cache.find(target-nums[i]);
		if (it != cache.end())
		{
			for (unsigned int j = 0; j< it->second.size(); ++j)
			{
				if (i != it->second[j])
				{
					results.push_back(i);
					results.push_back(it->second[j]);
					find = true;
					break;
				}
			}

			if (find)
			{
				break;
			}
		}
	}

	return results;
};

// ≈≈–Ú∫Û≤È’“
struct Node
{
	int index;
	int value;

	Node(int i, int v)
	{
		index = i;
		value = v;
	}

	bool operator < (Node& ref)
	{
		return value < ref.value;
	}
};

vector<int> twoSum(vector<int> &nums, int target) 
{
	vector<int> results;
	vector<Node> cache;

    for (int i=0; i<nums.size(); ++i)
	{
		cache.push_back(Node(i, nums[i]));
	}

	sort(cache.begin(), cache.end());

	for (int i = 0, j = cache.size() - 1; i < j;)
	{
		int value = cache[i].value + cache[j].value;
		if (value == target)
		{
			results.push_back(min(cache[i].index, cache[j].index));
			results.push_back(max(cache[i].index, cache[j].index));
			break;
		}
		else if (value > target)
		{
			--j;
		}
		else
		{
			++i;
		}
	}
	
	return results;
};

TEST(Pratices, tTwoSum)
{
	// [3, 3, 1, 2]  3 => [0, 1]
	// [2, 7, 11, 15] 9 => [0, 1]
	// [-1, 8, 10, 12, 40, 11] 10 => [0,5]

	vector<int> data;
	data.push_back(3);
	data.push_back(3);
	data.push_back(1);	
	data.push_back(2);	
	vector<int> results =  twoSum(data,6);

	data.clear();
	data.push_back(2);
	data.push_back(7);
	data.push_back(11);
	data.push_back(15);
	results =  twoSum(data,9);

	data.clear();
	data.push_back(-1);
	data.push_back(8);
	data.push_back(10);
	data.push_back(12);
	data.push_back(40);
	data.push_back(11);
	results =  twoSum(data,10);
}
