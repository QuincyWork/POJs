#include <gtest/gtest.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 

ListNode* swapPairs(ListNode* head)
{
	if (head==NULL)
		return NULL;

	int i = 0;
	ListNode* newHead = head;
	ListNode* pred = NULL;

	while (head)
	{
		ListNode* next = head->next;
		if (next)
		{
			head->next = next->next;
			if (pred==NULL)
			{
				newHead = next;
			}
			else
			{
				pred->next = next;
			}

			pred = head;
			next->next = head;
		}

		head = head->next;
	}

	return newHead;
}

TEST(Pratices, tSwapPairs)
{
	//1 -> 2 -> 3-> 4
	//2,1,4,3

	ListNode l1[] = {1,2};
	for (int i=1; i<sizeof(l1)/sizeof(l1[0]);++i)
	{
		l1[i-1].next = &l1[i];
	}

	ListNode* ret = swapPairs(l1);
}