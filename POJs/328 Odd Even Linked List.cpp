#include <gtest/gtest.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* oddEvenList1(ListNode* head)
{
	ListNode* pOddListNext = NULL;
	ListNode* pOddListFrist = NULL;
	ListNode* pEvenListNext= NULL;
	ListNode* pEvenListFirst = NULL;
	
	while (head)
	{
		if (head->val % 2)
		{
			if (pOddListNext)
			{
				pOddListNext->next = head;
				pOddListNext = head;
			}
			else
			{
				pOddListFrist = pOddListNext = head;
			}
		}
		else
		{
			if (pEvenListNext)
			{
				pEvenListNext->next = head;
				pEvenListNext = head;
			}
			else
			{
				pEvenListFirst = pEvenListNext = head;
			}
		}

		head = head->next;
	}

	if (pOddListNext)
	{
		pOddListNext->next = pEvenListFirst;
	}

	if (pEvenListNext)
	{
		pEvenListNext->next = NULL;
	}

	return pOddListFrist ? pOddListFrist : pEvenListFirst;
}

ListNode* oddEvenList(ListNode* head)
{
	ListNode* next = head;
	ListNode* evenFirst = NULL;
	ListNode* evenNext = NULL;
	
	while(next && next->next)
	{
		if (evenNext)		
		{
			evenNext = evenNext->next = next->next;			
		}
		else
		{
			evenFirst = evenNext = next->next;
		}

		next->next = next->next->next;		
		if (next->next)
		{
			next = next->next;
		}
	}

	if (next)
	{
		next->next = evenFirst;
	}

	if (evenNext)
	{
		evenNext->next = NULL;
	}

	return head;
}

TEST(LeetCode, tOddEvenList)
{
	ListNode l1[] = {1,2,3,4,5};
	l1[0].next = &l1[1];
	l1[1].next = &l1[2];
	l1[2].next = &l1[3];
	l1[3].next = &l1[4];

	ListNode* pResult = oddEvenList(l1);
}