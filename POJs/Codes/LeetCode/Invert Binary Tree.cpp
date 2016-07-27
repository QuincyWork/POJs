#include <gtest\gtest.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

 TreeNode* invertTree(TreeNode* root)
 {
	 if (!root)
		 return NULL;

	 invertTree(root->left);
	 invertTree(root->right);

	 TreeNode* tmp = root->left;
	 root->left = root->right;
	 root->right = tmp;

	 return root;
 }

 TEST(Pratices, tInvertTree)
 {
	 TreeNode data[] = {4,2,7,1,3,6,9};
	 data[0].left = &data[1];
	 data[0].right = &data[2];
	 data[1].left = &data[3];
	 data[1].right = &data[4];
	 data[2].left = &data[5];
	 data[2].right = &data[6];

	 TreeNode* result = invertTree(data);
 }