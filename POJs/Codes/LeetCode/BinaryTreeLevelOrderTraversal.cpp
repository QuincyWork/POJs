#include <gtest/gtest.h>
#include <list>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> results;
	list<TreeNode*> nodes;
	list<TreeNode*> nextNodes;
	if (!root)
		return results;

	nodes.push_back(root);

	vector<int> levelResult;
	while (!nodes.empty() || !nextNodes.empty())
	{
		if (nodes.empty())
		{
			nodes.assign(nextNodes.begin(),nextNodes.end());
			nextNodes.clear();

			results.push_back(levelResult);
			levelResult.clear();
		}

		TreeNode* t = nodes.front();
		nodes.pop_front();
		levelResult.push_back(t->val);

		if (t->left)
			nextNodes.push_back(t->left);

		if (t->right)
			nextNodes.push_back(t->right);
	}

	if (!levelResult.empty())
		results.push_back(levelResult);

	return results;
}

TEST(Pratices,tLevelOrder)
{
	TreeNode data1[] = {3,9,20,15,7};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[2].left = &data1[3];
	data1[2].right = &data1[4];

	vector<vector<int>> result = levelOrder(data1);

	TreeNode data2[] = {1,2,2,4,6,4,6};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];

	result = levelOrder(data2);
}