#include <gtest/gtest.h>
#include <list>
using namespace std;


class TrieTree
{
public:

	const static int  MAX_CHILD_KEY_COUNT = 30;
	const static char STRING_END_TAG = '\xFF';
	struct TrieNode
	{
		char nodeValue;
		int  nodeFreq;		
		list<TrieNode*> childNodes[MAX_CHILD_KEY_COUNT]; //Ϊ�˱�����������̫�󣬲�������+����ʽ

		TrieNode()
		{
			nodeValue = 0;
			nodeFreq = 0;			
		}
	};

	TrieTree();
	~TrieTree();

public:
	void Insert(const string& strVal);
	void Delete(const string& strVal);
	int  Search(const string& strVal);	
	int  CommonPrefix(const string& strVal);

private:
	void Clean(TrieNode* rootNode);
	bool DeleteNode(TrieNode* rootNode, const string& strVal, int nOffset);
	
	TrieNode m_RootNode;
};

TrieTree::TrieTree()
{
};

TrieTree::~TrieTree()
{
	Clean(&m_RootNode);
};

void TrieTree::Insert(const string& strVal)
{
	if (strVal.empty())
	{
		return;
	}

	// ���ַ���ĩβ���һ�������ַ�����������ǰ׺���������ַ���
	string strValue(strVal);
	strValue += STRING_END_TAG;

	TrieNode* pCurrentNode = &m_RootNode;
	unsigned int nIndex = 0;
	unsigned int nLength = strValue.length();

	do
	{
		bool bExistVal = false;
		char cValue = strValue[nIndex];
		list<TrieNode*>& refListNode = pCurrentNode->childNodes[(unsigned char)cValue % MAX_CHILD_KEY_COUNT];
		if (refListNode.size())
		{
			list<TrieNode*>::iterator it = refListNode.begin();
			list<TrieNode*>::iterator itEnd = refListNode.end();
			for (; it != itEnd; ++it)
			{
				if (cValue == (*it)->nodeValue)
				{
					(*it)->nodeFreq++;
					bExistVal = true;
					pCurrentNode = *it;

					break;
				}
			}
		}

		// ��ǰ�����ڶ�Ӧ���ַ������½�һ��
		if (!bExistVal)
		{
			TrieNode* pNewNode = new TrieNode();
			pNewNode->nodeFreq = 1;
			pNewNode->nodeValue = cValue;

			refListNode.push_back(pNewNode);			
			pCurrentNode = pNewNode;
		}

		++nIndex;
	}
	while(nIndex < nLength);
}

void TrieTree::Delete(const string& strVal)
{	
	if (strVal.empty())
	{
		return;
	}

	string strValue(strVal);
	strValue += STRING_END_TAG;

	DeleteNode(&m_RootNode, strValue, 0);
}

int TrieTree::Search(const string& strVal)
{
	if (strVal.empty())
	{
		return 0;
	}

	string strValue(strVal);
	strValue += STRING_END_TAG;

	return CommonPrefix(strValue);
}

int TrieTree::CommonPrefix(const string& strVal)
{
	if (strVal.empty())
	{
		return 0;
	}

	TrieNode* pCurrentNode = &m_RootNode;
	unsigned int nIndex = 0;
	unsigned int nLength = strVal.length();
	int nFreq = 0;

	do
	{
		bool bExistVal = false;
		char cValue = strVal[nIndex];
		list<TrieNode*>& refListNode = pCurrentNode->childNodes[(unsigned char)cValue % MAX_CHILD_KEY_COUNT];
		if (refListNode.size())
		{
			list<TrieNode*>::iterator it = refListNode.begin();
			list<TrieNode*>::iterator itEnd = refListNode.end();
			for (; it != itEnd; ++it)
			{
				if (cValue == (*it)->nodeValue)
				{
					nFreq = (*it)->nodeFreq;
					bExistVal = true;
					pCurrentNode = *it;
					break;
				}
			}
		}

		// ��ǰ�����ڶ�Ӧ���ַ�����û���ҵ�
		if (!bExistVal)
		{
			nFreq = 0;
			break;
		}

		++nIndex;
	}
	while(nIndex < nLength);

	return nFreq;
}

void TrieTree::Clean(TrieNode* rootNode)
{
	if (!rootNode)
	{
		return;
	}

	for (int i=0; i<MAX_CHILD_KEY_COUNT; ++i)
	{
		list<TrieNode*>& refListNode = rootNode->childNodes[i];
		if (refListNode.size())
		{
			list<TrieNode*>::iterator it = refListNode.begin();
			list<TrieNode*>::iterator itEnd = refListNode.end();
			for (; it != itEnd; ++it)
			{
				Clean(*it);
				delete *it;
			}

			refListNode.clear();
		}
	}
}

bool TrieTree::DeleteNode(TrieNode* rootNode, const string& strVal, int nOffset)
{
	if (!rootNode)
	{
		return false;
	}

	bool bDelChild = false;
	char cValue = strVal[nOffset];
	list<TrieNode*>& refListNode = rootNode->childNodes[(unsigned char)cValue % MAX_CHILD_KEY_COUNT];
	if (refListNode.size())
	{
		list<TrieNode*>::iterator it = refListNode.begin();
		list<TrieNode*>::iterator itEnd = refListNode.end();
		for (; it != itEnd; ++it)
		{
			if ((*it)->nodeValue == cValue)
			{		
				bDelChild = true;
				// �ַ���û�н�����ɾ����һ���ڵ�
				if (++nOffset < (int)strVal.length())
				{
					bDelChild = DeleteNode(*it, strVal, nOffset);
				}
				
				// �ýڵ����Ϊ0��˵���Ѿ�û���ӽڵ��ˣ��Ƴ��ýڵ�
				if (bDelChild && 
					(0 == (--(*it)->nodeFreq)))
				{
					delete *it;
					refListNode.erase(it);					
				}

				break;
			}			
		}
	}

	return bDelChild;
}

TEST(Structure, tTireTree)
{
	// "abc","ab","bd","dda"
	TrieTree tree;
	tree.Insert("abc");
	tree.Insert("ab");
	tree.Insert("bd");
	tree.Insert("dda");

	ASSERT_EQ(tree.Search("ab"), 1);
	ASSERT_EQ(tree.CommonPrefix("ab"), 2);
	tree.Delete("ab");
	ASSERT_EQ(tree.Search("ab"), 0);
	ASSERT_EQ(tree.CommonPrefix("ab"), 1);
	tree.Delete("abcd");
	ASSERT_EQ(tree.Search("ab"), 0);
	ASSERT_EQ(tree.Search("d"), 0);
	ASSERT_EQ(tree.CommonPrefix("d"), 1);
	ASSERT_EQ(tree.Search("fg"), 0);
	tree.Delete("fg");
}