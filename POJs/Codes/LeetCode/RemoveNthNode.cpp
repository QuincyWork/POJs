#include <gtest/gtest.h>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL || !n)
		return head;

	ListNode* temp = head;
	ListNode* pred = NULL;
	ListNode* current = NULL;
	while (temp)
	{
		temp = temp->next;
		--n;
		if (n <= 0)
		{
			pred = current;
			current = current ? current->next : head;
		}
	}

	if (current == NULL)
	{
		return head;
	}

	if (pred == NULL)
	{
		head = head->next;
	}
	else
	{
		pred->next = current->next;
		//delete current;
	}

	return head;
}

TEST(Pratices, tRemoveNthFromEnd)
{
	// 1 -> 2 -> 3->4->5 2

	ListNode Nodes[] = {1,2,3,4,5};
	for (int i=1; i<sizeof(Nodes)/sizeof(Nodes[0]);++i)
	{
		Nodes[i-1].next = &Nodes[i];
	}

	ListNode* value = removeNthFromEnd(Nodes,4);
	//removeNthFromEnd(Nodes,1);
	//removeNthFromEnd(Nodes,3);
	//removeNthFromEnd(Nodes,4);
	//removeNthFromEnd(Nodes,5);
	//removeNthFromEnd(Nodes,6);

}