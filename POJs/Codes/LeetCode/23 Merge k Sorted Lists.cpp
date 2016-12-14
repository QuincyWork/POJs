#include <gtest\gtest.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode root(0);
	ListNode* next = &root;
	
	while (true)
	{
		if (l1 == NULL)
		{
			next->next = l2;
			break;
		}

		if (l2 == NULL)
		{
			next->next = l1;
			break;
		}

		if (l1->val <= l2->val)
		{
			next = next->next = l1;
			l1 = l1->next;
		}
		else
		{
			next = next->next = l2;
			l2 = l2->next;
		}
	}

	return root.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	if (lists.empty())
	{
		return NULL;
	}

	ListNode* current = lists[0];
	for (int i = 1; i < lists.size(); ++i)
	{
		current = mergeTwoLists(current, lists[i]);
	}

	return current;
}

TEST(LeetCode, tMergeKLists)
{
	ListNode list1[] = { 2,3,5,7,10,14,18,23 };
	for (int i = 1; i < _countof(list1); ++i)
		list1[i - 1].next = &list1[i];

	ListNode list2[] = { 1,4,5,7,9,11,16,18,20,31 };
	for (int i = 1; i < _countof(list2); ++i)
		list2[i - 1].next = &list2[i];

	ListNode list3[] = { 3,7,9,19,21,34,50 };
	for (int i = 1; i < _countof(list3); ++i)
		list3[i - 1].next = &list3[i];

	vector<ListNode*> lists;
	lists.push_back(list1);
	lists.push_back(list2);
	lists.push_back(list3);

	ListNode* result = mergeKLists(lists);
}