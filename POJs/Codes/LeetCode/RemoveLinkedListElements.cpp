#include <gtest\gtest.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* removeElements(ListNode* head, int val)
{
	if (!head)
		return NULL;

	ListNode* result = NULL;
	ListNode* pred = NULL;
	while (head)
	{
		if (head->val == val)
		{
			if (pred)
			{
				pred->next = head->next;
			}
		}
		else
		{
			pred = head;
			if (!result)
				result = head;
		}

		head = head->next;
	}

	return result;
}

TEST(Pratices, tRemoveElements)
{
	ListNode Nodes[] = { 4,4,4,4,4,1,2,3,4,5,4,4,3 };
	for (int i = 1; i<sizeof(Nodes) / sizeof(Nodes[0]); ++i)
	{
		Nodes[i - 1].next = &Nodes[i];
	}

	ListNode* result = removeElements(Nodes, 4);
	 result = removeElements(Nodes, 3);
}