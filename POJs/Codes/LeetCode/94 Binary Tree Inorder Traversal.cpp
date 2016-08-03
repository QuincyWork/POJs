#include <gtest\gtest.h>
#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归实现
void inorderTraversal1(TreeNode* root, vector<int>& result)
{
	if (!root)
		return;

	inorderTraversal1(root->left, result);
	result.push_back(root->val);
	inorderTraversal1(root->right, result);
}

vector<int> inorderTraversal1(TreeNode* root)
{
	vector<int> result;
	inorderTraversal1(root, result);
	return result;
}

// 循环实现
vector<int> inorderTraversal2(TreeNode* root)
{
	vector<int> result;
	if (!root)
	{
		return result;
	}

	stack<TreeNode*> stack;
	unordered_set<TreeNode*> visited;
	stack.push(root);

	while (!stack.empty())
	{
		TreeNode* node = stack.top();
		stack.pop();

		unordered_set<TreeNode*>::iterator it = visited.find(node);
		if (it != visited.end())
		{
			result.push_back(node->val);
			visited.erase(it);
			continue;
		}

		if (node->right)
		{
			stack.push(node->right);
		}

		if (node->left)
		{
			visited.insert(node);
			stack.push(node);
			stack.push(node->left);
		}
		else
		{
			result.push_back(node->val);
		}
	}

	return result;
}


vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> result;
	stack<TreeNode*> nodes;

	while (!nodes.empty() || root)
	{
		if (root)
		{
			nodes.push(root);
			root = root->left;
		}
		else
		{
			root = nodes.top();
			nodes.pop();
			result.push_back(root->val);
			root = root->right;
		}
	}

	return result;
}

TEST(LeetCode, tInorderTraversal)
{
	TreeNode t1[] = {1,2,3};
	t1[0].right = &t1[1];
	t1[1].left = &t1[2];

	vector<int> result = inorderTraversal(t1);
}