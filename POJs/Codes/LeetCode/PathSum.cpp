#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool hasPathSum(TreeNode* root, int sum)
{
	if (!root)
		return false;

	if (!root->left && !root->right)
		return (sum == root->val);

	return (hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val));
}

TEST(Pratices, tHasPathSum)
{
	TreeNode data1[] = {5,4,8,11,13,4,7,2,1,1};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[1].left = &data1[3];
	data1[2].left = &data1[4];
	data1[2].right = &data1[5];
	data1[3].left = &data1[6];
	data1[3].right = &data1[7];
	data1[5].right = &data1[8];

	ASSERT_TRUE(hasPathSum(data1,22));
	ASSERT_FALSE(hasPathSum(data1,23));
}