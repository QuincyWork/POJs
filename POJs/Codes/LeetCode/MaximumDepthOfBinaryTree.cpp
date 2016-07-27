#include <gtest/gtest.h>
#include <list>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root)
{
	if (!root)
		return 0;

	int l = maxDepth(root->left)+1;
	int r = maxDepth(root->right)+1;

	return ((l>r) ? l : r);
}

TEST(Pratices, tMaxDepth)
{
	TreeNode data1[] = {3,9,20,15,7};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[2].left = &data1[3];
	data1[2].right = &data1[4];

	ASSERT_EQ(maxDepth(data1),3);

	TreeNode data2[] = {1,2,2,4,6,4,6};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];
	ASSERT_EQ(maxDepth(data2),3);
}