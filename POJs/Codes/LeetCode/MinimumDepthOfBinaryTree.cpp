#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int minDepth(TreeNode* root)
{
	if (!root)
		return 0;

	int l = minDepth(root->left)+1;
	int r = minDepth(root->right)+1;
	if (!root->left)
		return r;

	if (!root->right)
		return l;

	return (l<r ? l : r);
}

TEST(Pratices, tMinDepth)
{
	TreeNode data1[] = {3,9,20,15,7};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[2].left = &data1[3];
	data1[2].right = &data1[4];

	ASSERT_EQ(minDepth(data1),2);

	TreeNode data2[] = {1,2,2,4,6,4,6};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[2].left = &data2[3];
	data2[2].right = &data2[4];
	data2[4].left = &data2[5];
	data2[4].right = &data2[6];
	ASSERT_EQ(minDepth(data2),2);
}