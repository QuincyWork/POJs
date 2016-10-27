#include <gtest/gtest.h>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


int kthSmallest(TreeNode* root, int k) 
{
	if (!root)
	{
		return 0;
	}

	int result = 0;
	int count = 0;	
	stack<TreeNode*> s;	

	while (!s.empty() || root)
	{		
		if (root)
		{
			s.push(root);
			root = root->left;
		}
		else
		{
			root = s.top();
			s.pop();
			if (++count == k)
			{
				result = root->val;
				break;
			}

			root = root->right;
		}
	}

	return result;
}

TEST(LeetCode, tKthSmallest)
{
	TreeNode t1[] = {1,2,3,4,5,6,7};
	t1[1].left = &t1[0];
	t1[1].right = &t1[2];

	t1[3].left = &t1[1];
	t1[3].right = &t1[5];

	t1[5].left = &t1[4];
	t1[5].right = &t1[6];

	ASSERT_EQ(kthSmallest(&t1[3],2),2);
}