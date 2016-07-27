#include <gtest/gtest.h>
#include <list>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isSymmetric(TreeNode* root)
{
	if (!root)
		return true;

	list<TreeNode*> left;
	list<TreeNode*> right;

	left.push_back(root->left);
	right.push_back(root->right);
	while (!left.empty() && !right.empty())
	{
		TreeNode* l = left.front();
		TreeNode* r = right.front();

		left.pop_front();
		right.pop_front();

		if (l && r)
		{
			if (l->val != r->val)
				return false;
		}
		else if (l || r)
		{
			return false;
		}

		if (l)
		{
			left.push_back(l->left);
			left.push_back(l->right);
		}

		if (r)
		{
			right.push_back(r->right);
			right.push_back(r->left);
		}
	}

	return (left.empty() && right.empty());
}

TEST(Pratices,tIsSymmetric)
{
	TreeNode data1[] = {1,2,3,4,6,10,20};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[1].left = &data1[3];
	data1[1].right = &data1[4];
	data1[2].left = &data1[5];
	data1[2].right = &data1[6];

	TreeNode data2[] = {1,2,2,4,6,4,6};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];

	ASSERT_FALSE(isSymmetric(data2));
	ASSERT_FALSE(isSymmetric(data1));

}