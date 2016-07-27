#include <gtest/gtest.h>
#include <list>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> results;
	if (!root)
		return results;

	vector<int> level;
	list<TreeNode*> nodes;
	nodes.push_back(root);
	nodes.push_back(NULL);

	while (nodes.size() > 1)
	{
		TreeNode* t = nodes.front();
		nodes.pop_front();

		if (t==NULL)
		{
			results.push_back(level);
			level.clear();
			nodes.push_back(NULL);
			continue;
		}

		level.push_back(t->val);
		if (t->left)
			nodes.push_back(t->left);

		if (t->right)
			nodes.push_back(t->right);

	}
	results.push_back(level);
	reverse(results.begin(),results.end());

	return results;
}

TEST(Pratices, tLevelOrderBottom)
{
	TreeNode data1[] = {3,9,20,15,7};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[2].left = &data1[3];
	data1[2].right = &data1[4];

	vector<vector<int>> result = levelOrderBottom(data1);

	TreeNode data2[] = {1,2,2,4,6,4,6};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];

	result = levelOrderBottom(data2);
}