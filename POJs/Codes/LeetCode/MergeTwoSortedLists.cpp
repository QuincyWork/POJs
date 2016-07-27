#include <gtest/gtest.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* newList = NULL;
	ListNode* current = NULL;
	while (l1 || l2)
	{
		int val1 = numeric_limits<int>::max();
		int val2 = numeric_limits<int>::max();
		if (l1)
		{
			val1 = l1->val;
		}

		if (l2)
		{
			val2 = l2->val;
		}

		ListNode* temp = NULL;
		if (val1 <= val2)
		{
			temp = l1;
			l1 = l1->next;
		}
		else
		{
			temp = l2;
			l2 = l2->next;
		}

		if (newList==NULL)
		{
			newList = temp;
			current = newList;
		}
		else
		{
			current->next = temp;
			current = temp;
		}
	}

	return newList;
}

TEST(Pratices, tMergeTwoLists)
{
	// 1,3,5
	// 2,4,6 => 1,2,3,4,5,6

	ListNode l1[] = {-1,2,3,5};
	for (int i=1; i<sizeof(l1)/sizeof(l1[0]);++i)
	{
		l1[i-1].next = &l1[i];
	}
	ListNode l2[] = {2,4,6};
	for (int i=1; i<sizeof(l2)/sizeof(l2[0]);++i)
	{
		l2[i-1].next = &l2[i];
	}

	ListNode* newList = mergeTwoLists(l1,NULL);
	//newList = mergeTwoLists(l1,NULL);
}