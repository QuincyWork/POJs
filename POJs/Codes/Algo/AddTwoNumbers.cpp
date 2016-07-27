#include <gtest/gtest.h>

using namespace std;

struct ListNode {
	
	int val;
	ListNode *next;
	ListNode(int x) : 
		val(x), next(NULL) 
	{}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode* result = 0;
	ListNode* current = 0;
	int carry = 0;

	while (l1 != NULL || l2 != NULL)
	{
		int value = 0;
		if (l1 != NULL)
		{
			value += l1->val;
			l1 = l1->next;
		}

		if (l2 != NULL)
		{
			value += l2->val;
			l2 = l2->next;
		}
		
		if (current == NULL)
		{
			current = result = new ListNode(value % 10);			
			carry = value / 10;
		}
		else
		{
			current->next = new ListNode((value + carry) % 10);
			carry = (value + carry) / 10;
			current = current->next;
		}
	}

	if (carry)
	{
		if (current == NULL)
		{
			current = result = new ListNode(carry);			
		}
		else
		{
			current->next = new ListNode(carry);			
			current = current->next;
		}
	}

	return result;
}

TEST(Pratices, tAddTwoNumbers)
{
	// (2 -> 4 -> 3) + (5 -> 6 -> 4)  7 -> 0 -> 8
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* result = addTwoNumbers(l1,l2);

	// NULL + (2 -> 4 -> 3)   
	result = addTwoNumbers(NULL,l1);

	// (2 -> 4 -> 3) + (5 -> 6 -> 4 -> 4) 
	l2->next->next->next = new ListNode(4);
	result = addTwoNumbers(l1,l2);


	// 1 + 9->9
	l1 = new ListNode(1);
	l2 = new ListNode(9);
	l2->next = new ListNode(9);

	result = addTwoNumbers(l1,l2);
}