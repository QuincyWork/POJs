#include <gtest/gtest.h>
using namespace std;


struct ListNode {

	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(NULL)
	{}
};

void deleteNode(ListNode* node)
{
	if (!node)
		return;

	node->val = node->next->val;
	node->next = node->next->next;
}

TEST(Pratices, tDeleteNode)
{
	ListNode data[] = {1,3,5,3,6,10};
	for (int i = 1; i < sizeof(data) / sizeof(data[0]); ++i)
	{
		data[i - i].next = &data[i];
	}

	deleteNode(&data[2]);
	deleteNode(&data[3]);
}