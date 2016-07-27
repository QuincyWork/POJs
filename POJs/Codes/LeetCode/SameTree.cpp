#include <gtest/gtest.h>
#include <list>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isSameTree1(TreeNode* p, TreeNode* q)
{
	if (!p || !q)
		return !(p || q);

	//
	list<TreeNode*> pLists;
	list<TreeNode*> qLists;
	pLists.push_back(p);
	qLists.push_back(q);

	while (!pLists.empty() && !qLists.empty())
	{
		p = pLists.front();
		pLists.pop_front();
		q = qLists.front();
		qLists.pop_front();

		if (p->val != q->val)
			return false;

		if ((p->left && q->left) != (p->left || q->left))
			return false;

		if ((p->right && q->right) != (p->right || q->right))
			return false;

		if (p->left)
			pLists.push_back(p->left);
		if (p->right)
			pLists.push_back(p->right);

		if (q->left)
			qLists.push_back(q->left);
		if (q->right)
			qLists.push_back(q->right);
	}

	return (pLists.empty() && qLists.empty());
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
	if (!q || !p)
		return !(p||q);

	if (p->val != q->val)
		return false;

	return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

TEST(Pratices,tSameTree)
{
	TreeNode data1[] = {1,2,3,4,6,10,20};
	data1[0].left = &data1[1];
	data1[0].right = &data1[2];
	data1[1].left = &data1[3];
	data1[1].right = &data1[4];
	data1[2].left = &data1[5];
	data1[2].right = &data1[6];

	TreeNode data2[] = {1,2,3,4,6,10,21};
	data2[0].left = &data2[1];
	data2[0].right = &data2[2];
	data2[1].left = &data2[3];
	data2[1].right = &data2[4];
	data2[2].left = &data2[5];
	data2[2].right = &data2[6];

	ASSERT_TRUE(isSameTree(data1,data1));
	ASSERT_FALSE(isSameTree(data1,data2));
	ASSERT_TRUE(isSameTree(data2,data2));

}