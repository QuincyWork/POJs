#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalancedDepth(TreeNode* root, int& depth)
{
	if (!root)
	{
		depth = 0;
		return true;
	}

	int l;
	int r;
	if (isBalancedDepth(root->left,l) &&
		isBalancedDepth(root->right,r))
	{
		if (abs(l-r) <= 1)
		{
			depth = (l>r) ? l:r;
			depth++;
			return true;
		}
	}

	return false;
}

bool isBalanced(TreeNode* root)
{
	int depth = 0;
	return isBalancedDepth(root,depth);
}

TEST(Pratices, tIsBalanced)
{
	TreeNode data[] = {1,2,4,5,6,7,3,4,5,1};
	data[0].left = &data[1];
	data[0].right = &data[2];
	data[1].left = &data[3];
	data[1].right = &data[4];
	data[2].left = &data[5];
	data[2].right = &data[6];
	data[3].left = &data[7];
	data[3].right = &data[8];
	data[4].left = &data[9];

	ASSERT_TRUE(isBalanced(data));

}