#include <gtest/gtest.h>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void PreOrderTrversalSub(TreeNode* root, vector<int>& result)
{
	if (!root)
		return;

	result.push_back(root->val);
	PreOrderTrversalSub(root->left, result);
	PreOrderTrversalSub(root->right, result);		
}

// µÝ¹éµ÷ÓÃ
vector<int> preorderTraversal1(TreeNode* root)
{
	vector<int> result;
	PreOrderTrversalSub(root, result);

	return result;
}

// Ñ­»·
vector<int> preorderTraversal(TreeNode* root)
{
	vector<int> result;
	if (!root)
	{
		return result;
	}

	stack<TreeNode*> nodes;
	nodes.push(root);

	while(!nodes.empty())
	{
		TreeNode* pNode = nodes.top();
		nodes.pop();

		result.push_back(pNode->val);

		if (pNode->right)
		{
			nodes.push(pNode->right);
		}

		if (pNode->left)
		{
			nodes.push(pNode->left);
		}
	}

	return result;
}


TEST(LeetCode, tPreorderTraversal)
{
	TreeNode t1[] = {1,2,3};
	t1[0].right = &t1[1];
	t1[1].left = &t1[2];

	vector<int> result = preorderTraversal(t1);
}