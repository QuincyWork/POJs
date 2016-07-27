#include <gtest\gtest.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
	if (!head)
		return false;

	ListNode* slow = head;
	ListNode* fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
			return true;

	}

	return false;
}

TEST(Pratices, tHasCycle)
{
	ListNode ListA[] = {1,3,4,5,7,9,10,4,2,2,11,34,5,123,11,3,10};
	for (int i=1; i<sizeof(ListA)/sizeof(ListA[0]); ++i)
	{
		ListA[i-1].next = &ListA[i];
	}

	ASSERT_FALSE(hasCycle(ListA));

	ListA[sizeof(ListA)/sizeof(ListA[0])-1].next = &ListA[5];
	ASSERT_TRUE(hasCycle(ListA));
}