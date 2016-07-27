#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (!root || !p || !q)
		return NULL;

	if (root == p || root == q)
	{
		return root;
	}

	if (root->val > p->val &&
		root->val > q->val)
	{
		return lowestCommonAncestor(root->left, p, q);
	}
	else if(root->val < p->val &&
		root->val < q->val)
	{
		return lowestCommonAncestor(root->right, p, q);
	}

	return root;
}

TEST(Pratices, tLowestCommonAncestor)
{
	TreeNode data[] = {1,2,3,4,5,6,7,8,9};
	data[5].left= &data[1];
	data[5].right = &data[7];
	data[1].left = &data[0];
	data[1].right = &data[3];
	data[3].left = &data[2];
	data[3].right = &data[4];
	data[7].left = &data[6];
	data[7].right = &data[8];


	TreeNode* pNode = lowestCommonAncestor(&data[5], &data[1], &data[7]);
	ASSERT_TRUE(pNode->val == 6);

	pNode = lowestCommonAncestor(&data[5], &data[3], &data[1]);
	ASSERT_TRUE(pNode->val == 2);
}