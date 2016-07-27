#include <gtest/gtest.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


void dfs(TreeNode* root, string path, vector<string>& result)
{
	if (!root)
	{
		return;
	}

	char szBuffer[20] = {0};
	string newPath = path;
	if (!newPath.empty())
	{
		newPath += "->";
	}

	sprintf(szBuffer,"%d",root->val);
	newPath += szBuffer;

	if (root->left || root->right)
	{
		dfs(root->left, newPath, result);
		dfs(root->right, newPath, result);
	}
	else
	{
		result.push_back(newPath);
	}
}

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	string strPath;
	dfs(root, strPath, result);

	return result;
}

TEST(Pratices, tBinaryTreePaths)
{
	TreeNode data[] = {1,2,3,5};
	data[0].left = &data[1];
	data[0].right = &data[2];
	data[1].right = &data[3];

	vector<string> result = binaryTreePaths(&data[0]);
}