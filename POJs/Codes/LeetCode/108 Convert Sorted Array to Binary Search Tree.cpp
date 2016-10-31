#include <gtest\gtest.h>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* sortedArrayToBST1(vector<int>& nums)
{
	if (nums.empty())
	{
		return NULL;
	}

	vector<TreeNode*> nodes;
	for (int i = 0; i < nums.size(); ++i)
	{
		nodes.push_back(new TreeNode(nums[i]));
	}
	
	for (int i = 0; i < nodes.size()/2; i++)
	{
		int lChild = 2 * i + 1;
		int rChild = 2 * i + 2;
		if (lChild < nodes.size())
		{
			nodes[i]->left = nodes[lChild];
		}
		
		if (rChild < nodes.size())
		{
			nodes[i]->right = nodes[rChild];
		}
	}

	return nodes[0];
}

TreeNode* treeToBST(vector<TreeNode*>& nodes, int l, int r)
{
	if (l > r)
	{
		return NULL;
	}

	int m = l + (r - l + 1) / 2;
	
	nodes[m]->left = treeToBST(nodes, l, m-1);
	nodes[m]->right = treeToBST(nodes, m+1, r);

	return nodes[m];
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	if (nums.empty())
	{
		return NULL;
	}

	vector<TreeNode*> nodes;
	for (int i = 0; i < nums.size(); ++i)
	{
		nodes.push_back(new TreeNode(nums[i]));
	}

	int length = nums.size();
	return treeToBST(nodes, 0, length - 1);
}

TEST(LeetCode, tSortedArrayToBST)
{
	int d1[] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> v1(d1, d1 + _countof(d1));
	TreeNode* result = sortedArrayToBST(v1);
}