#include <gtest\gtest.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

TreeNode* treeToBST(vector<TreeNode*>& nodes, int l, int r)
{
	if (l > r)
	{
		return NULL;
	}

	int m = l + (r - l + 1) / 2;

	nodes[m]->left = treeToBST(nodes, l, m - 1);
	nodes[m]->right = treeToBST(nodes, m + 1, r);

	return nodes[m];
}


TreeNode* sortedListToBST(ListNode* head)
{
	if (!head)
	{
		return NULL;
	}

	vector<TreeNode*> nodes;
	while (head)
	{
		nodes.push_back(new TreeNode(head->val));
		head = head->next;
	}

	return treeToBST(nodes, 0, nodes.size() - 1);
}

TEST(LeetCode, tSortedListToBST)
{
	ListNode l1[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 1; i < _countof(l1); ++i)
	{
		l1[i - 1].next = &l1[i];
	}

	TreeNode* result = sortedListToBST(l1);
}
