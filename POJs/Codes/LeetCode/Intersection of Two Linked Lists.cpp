#include <gtest\gtest.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* ReverseLinkedList(ListNode* head)
{
	ListNode* next = head;
	ListNode* prev = NULL;

	while (next)
	{
		ListNode* temp = next->next;
		next->next = prev;
		prev = next;
		next = temp;
	}

	return prev;
}

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB)
		return NULL;

	ListNode* nextA = headA;
	ListNode* nextB = headB;
	int lenA = 1;
	int lenB = 1;

	while (nextA->next)
	{
		++lenA;
		nextA = nextA->next;
	}

	while (nextB->next)
	{
		++lenB;
		nextB = nextB->next;
	}

	if (nextA != nextB)
	{
		return NULL;
	}

	nextA = headA;
	nextB = headB;
	if (lenA > lenB)
	{
		int diff = lenA - lenB;
		while (diff)
			nextA = nextA->next;
	}
	else
	{
		int diff = lenB - lenA;
		while (diff)
			nextB = nextB->next;
	}

	while (nextA != nextB)
	{
		nextA = nextA->next;
		nextB = nextB->next;
	}

	return nextA;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if (!headA || !headB)
		return NULL;

	ListNode* nextA = headA;
	ListNode* nextB = headB;
	bool flagA = true;
	bool flagB = true;

	while (nextA && nextB)
	{
		if (nextA == nextB)
			return nextA;

		nextA = nextA->next;
		nextB = nextB->next;

		if (!nextA && flagA)
		{
			nextA = headB;
			flagA = false;
		}

		if (!nextB && flagB)
		{
			nextB = headA;
			flagB = false;
		}
	}

	return NULL;
}

TEST(Pratices, tGetIntersectionNode)
{
	// 1,2,4,6,
	ListNode ListA[] = {1,3,4,5,7,9,10};
	for (int i=1; i<sizeof(ListA)/sizeof(ListA[0]); ++i)
	{
		ListA[i-1].next = &ListA[i];
	}

	ListNode ListB[] = {4,5,3,3,18,1,10};
	for (int i=1; i<sizeof(ListB)/sizeof(ListB[0]); ++i)
	{
		ListB[i-1].next = &ListB[i];
	}

	ListNode ListC[] = {5,6,33,1,90};
	for (int i=1; i<sizeof(ListC)/sizeof(ListC[0]); ++i)
	{
		ListC[i-1].next = &ListC[i];
	}

	ASSERT_EQ(getIntersectionNode(ListA,ListB),(ListNode*)0);

	ListA[sizeof(ListA)/sizeof(ListA[0])-1].next = &ListC[0];
	ListB[sizeof(ListB)/sizeof(ListB[0])-1].next = &ListC[0];

	ASSERT_EQ(getIntersectionNode(ListA,ListB),&ListC[0]);
}