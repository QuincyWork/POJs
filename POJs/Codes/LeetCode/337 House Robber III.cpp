#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}

  };

int robSub(TreeNode* root, bool bCanRob, unordered_map<TreeNode*,int>& record)
{
	if (!root)
	{
		return 0;
	}

	if (record.count(root))
	{
		return record[root];
	}

	int result = robSub(root->left, true, record) + robSub(root->right, true, record);	
	if (bCanRob)
	{
		result = max(robSub(root->left, false, record) + robSub(root->right, false, record) + root->val, result);			
	}
	
	//record[root] = result;

	return result;
}

int rob(TreeNode* root) 
{	
	unordered_map<TreeNode*,int> record;
	return max(robSub(root, true, record),robSub(root, false, record));
}

TEST(LeetCode, tRob)
{	
	TreeNode t1[] = {3,2,3,3,1};	
	t1[0].left = &t1[1];
	t1[0].right = &t1[2];
	t1[1].right = &t1[3];
	t1[2].right = &t1[4];

	ASSERT_EQ(rob(t1),7);

	TreeNode t2[] = {3,4,5,1,3,1};	
	t2[0].left = &t2[1];
	t2[0].right = &t2[2];

	t2[1].left = &t2[3];
	t2[1].right = &t2[4];
	t2[2].right = &t2[5];

	ASSERT_EQ(rob(t2),9);

}