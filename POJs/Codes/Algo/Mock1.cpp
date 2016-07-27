#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTValue(TreeNode* root, int& min, int& max)
{
	if (!root)
	{
		return true;
	}
    
	int lmin = root->val;
	int lmax = root->val;
	if (root->left)
	{
		if (!isValidBSTValue(root->left,lmin,lmax) ||
			lmax >= root->val) 
		{
			return false;
		}
	}
	min = lmin;

	if (root->right)
	{
		if (!isValidBSTValue(root->right,lmin,lmax) ||
			lmin <= root->val)
		{
			return false;
		}
	}
	max = lmax;

	return true;
}

bool isValidBST(TreeNode* root)
{
	int min,max;
	return isValidBSTValue(root,min,max);
}

TEST(Mock,tIsValidBST)
{
	TreeNode data1[] = {3,9,20,15,7};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[2].left = &data1[3];
	data1[2].right = &data1[4];

	bool ret = isValidBST(data1);

	TreeNode data2[] = {5,3,7,1,4,6,8};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];
	ret = isValidBST(data2);
}