#include <gtest/gtest.h>

using namespace std;

struct ListNode {
     int val;
	 ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* deleteDuplicates(ListNode* head)
{
	if (!head)
		return head;

	ListNode* pred = head;
	ListNode* current = head->next;
	while (current)
	{
		if (pred->val == current->val)
		{
			pred->next = current->next;
		}
		else
		{
			pred = current;
		}

		current = current->next;
	}

	return head;
}

TEST(Pratices,tDeleteDuplicates)
{
	ListNode Values[] = {1,1,2,3,3};
	for (int i=1; i<sizeof(Values)/sizeof(Values[0]);++i)
	{
		Values[i-1].next = &Values[i];
	}

	ListNode* Result = deleteDuplicates(Values);
}