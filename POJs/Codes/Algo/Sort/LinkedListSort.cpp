#include <gtest/gtest.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MergeSort(ListNode* head)
{
	if (head == NULL || head->next==NULL)
	{
		return head;
	}

	ListNode* l = head;
	ListNode* r = head->next;

	l->next = l->next->next;
	if (r->next)
	{
		r->next = r->next->next;
	}

	ListNode* A = MergeSort(l);
	ListNode* B = MergeSort(r);
	return Merge(A,B);
}

ListNode* Merge(ListNode* A, ListNode* B)
{

}

ListNode* sortList(ListNode* head)
{	
	return MergeSort(head);
}