#include <gtest/gtest.h>
#include <vector>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* ReverseLinkedList(ListNode* pHead)
{
	ListNode* pNext = pHead;	
	ListNode* pPrev = NULL;
	
	while (pNext)
	{
		ListNode* pTemp = pNext->m_pNext;
		pNext->m_pNext = pPrev;
		pPrev = pNext;
		pNext = pTemp;
	}

	return pPrev;
}

// µÝ¹é·½Ê½ÊµÏÖ
ListNode* ReverseLinkedList2(ListNode* pHead, ListNode* pPrev = NULL)
{		
	ListNode* pReversedHead = pHead;		
	if (pHead)
	{		
		if (pHead->m_pNext)
		{
			pReversedHead = ReverseLinkedList2(pHead->m_pNext, pHead);
		}

		pHead->m_pNext = pPrev;		
	}

	return pReversedHead;
}

ListNode* CreateLinkedList(const string& data)
{
	ListNode* pHead = NULL;
	ListNode* pLast = NULL;
	for (int i=0; i<data.size(); ++i)
	{
		ListNode* pNext = new ListNode();		
		pNext->m_nKey = data[i];
		pNext->m_pNext = NULL;

		if (!pHead)
		{
			pHead = pLast = pNext;
		}
		else
		{
			pLast->m_pNext = pNext;
			pLast = pNext;
		}
	}

	return pHead;
}

void ReleaseLinkedList(ListNode* pHead)
{
	ListNode* pTemp = NULL;
	while (pHead)
	{
		pTemp = pHead;
		pHead = pHead->m_pNext;
		delete pTemp;
	}
}

string ConvertLinkedList(ListNode* pHead)
{
	string strValue;
	while (pHead)
	{
		strValue+= (char)pHead->m_nKey;
		pHead = pHead->m_pNext;
	}

	return strValue;
}

TEST(Pratices, tReverseLinkedList)
{
	// NULL
	ListNode* pHead = NULL;
	pHead = ReverseLinkedList(pHead);
	ASSERT_TRUE(!pHead);

	// a -> a
	pHead = CreateLinkedList("a");
	pHead = ReverseLinkedList(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"a");
	ReleaseLinkedList(pHead);

	// ab -> ba
	pHead = CreateLinkedList("ab");
	pHead = ReverseLinkedList(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"ba");
	ReleaseLinkedList(pHead);

	// abcedfg -> gfdecba
	pHead = CreateLinkedList("abcedfg");
	pHead = ReverseLinkedList(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"gfdecba");
	ReleaseLinkedList(pHead);

	/// µÝ¹éÄæÐò²âÊÔ
	pHead = NULL;
	pHead = ReverseLinkedList2(pHead);
	ASSERT_TRUE(!pHead);

	// a -> a
	pHead = CreateLinkedList("a");
	pHead = ReverseLinkedList2(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"a");
	ReleaseLinkedList(pHead);

	// ab -> ba
	pHead = CreateLinkedList("ab");
	pHead = ReverseLinkedList2(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"ba");
	ReleaseLinkedList(pHead);

	// abcedfg -> gfdecba
	pHead = CreateLinkedList("abcedfg");
	pHead = ReverseLinkedList2(pHead);
	ASSERT_EQ(ConvertLinkedList(pHead),"gfdecba");
	ReleaseLinkedList(pHead);
}