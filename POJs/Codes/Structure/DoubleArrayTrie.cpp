#include <gtest/gtest.h>
#include <list>
using namespace std;

class DoubleArrayTrie 
{
	static const int BUF_SIZE = 0x4000;
	static const int UNIT_SIZE = 8;

public: 

	DoubleArrayTrie();
	~DoubleArrayTrie();

	int GetUnitSize() const;
	int GetSize() const;
	int GetTotalSize() const;
	int GetNonZeroSize() const;

	int Build(const list<string>& key);
	int Build(const list<string>& key, int* length, int* value, int keysize);

	int ExactMatchSearch(const string& key);
	int ExactMatchSearch(const string& key, int pos, int len, int nodePos);
	list<int> CommonPrefixSearch(const string& key);
	list<int> CommonPrefixSearch(const string key, int pos, int len, int nodePos);


private:
	struct Node 
	{
		int code;
		int depth;
		int left;
		int right;
	};

	int Resize(int newsize);
	int Fetch(Node* pParent, list<Node*>& siblings);
	int Insert(list<Node*>& siblings);

private:


	int*	m_pCheck;
	int*	m_pBase;
	bool*	m_pUsed;
	int		m_nSize;
	int		m_nAllocSize;
	list<string> m_lstKey;
	int		m_nKeySize;
	int*	m_pLength;
	int*	m_pValue;
	int		m_nProgress;
	int		m_nNextCheckPos;
};


DoubleArrayTrie::DoubleArrayTrie()
{
	m_pCheck = NULL;
	m_pBase = NULL;
	m_pUsed	= NULL;
	m_nSize = m_nAllocSize = 0;
}

DoubleArrayTrie::~DoubleArrayTrie()
{
	delete[] m_pCheck;
	delete[] m_pBase;
	delete[] m_pUsed;
	m_nSize = m_nAllocSize = 0;
}

int DoubleArrayTrie::GetUnitSize() const
{
	return UNIT_SIZE;
}

int DoubleArrayTrie::GetSize() const
{
	return m_nSize;
}

int DoubleArrayTrie::GetTotalSize() const
{
	return m_nSize * UNIT_SIZE;
}

int DoubleArrayTrie::GetNonZeroSize() const
{
	int nResult = 0;
	for (int i=0; i < m_nSize; ++i)
	{
		if (m_pCheck[i] != 0)
			nResult++;
	}

	return nResult;
}

int DoubleArrayTrie::Build(const list<string>& key)
{
	return Build(key, NULL, NULL, key.size());
}

int DoubleArrayTrie::Build(const list<string>& key, int* length, int* value, int keysize)
{
	if (keysize > key.size())
	{
		return 0;
	}

	m_lstKey = key;
	m_pLength = length;
	m_nKeySize = keysize;
	m_pValue = value;
	m_nProgress = 0;

	Resize(0x10000 * 32);

	m_pBase[0] = 1;
	m_nNextCheckPos = 0;

	Node* pRoot = new Node();
	pRoot->left = 0;
	pRoot->right = keysize;
	pRoot->depth = 0;

	list<Node*> siblings;
	Fetch(pRoot, siblings);
	Insert(siblings);

	delete[] m_pUsed;
	m_pUsed = NULL;
	m_lstKey.clear();

	return 1;
}

int DoubleArrayTrie::ExactMatchSearch(const string& key)
{
	return ExactMatchSearch(key,0,0,0);
}

int DoubleArrayTrie::ExactMatchSearch(const string& key, int pos, int len, int nodePos)
{
	if (len <= 0)
	{
		len = key.length();
	}

	if (nodePos <= 0)
	{
		nodePos = 0;
	}

	int nResult = -1;
	int b = m_pBase[nodePos];
	int p;

	for (int i = pos; i < len; ++i)
	{
		p = b + (int)key[i] + 1;
		if (b == m_pCheck[p])
		{
			b = m_pBase[p];
		}
		else
		{
			return nResult;
		}
	}

	p = b;
	int n = m_pBase[p];
	if (b == m_pCheck[p] && n < 0)
	{
		nResult = -n - 1;
	}

	return nResult;
}

list<int> DoubleArrayTrie::CommonPrefixSearch(const string& key)
{
	return CommonPrefixSearch(key, 0, 0, 0);
}

list<int> DoubleArrayTrie::CommonPrefixSearch(const string key, int pos, int len, int nodePos)
{
	if (len <= 0)
	{
		len = key.length();
	}

	if (nodePos <= 0)
	{
		nodePos = 0;
	}

	list<int> lstResult;
	int b = m_pBase[nodePos];
	int n;
	int p;

	for (int i = pos; i < len; ++i)
	{
		p = b;
		n = m_pBase[p];

		if (b == m_pCheck[p] && n < 0)
		{
			lstResult.push_back(-n - 1);
		}

		p = b + (int)key[i] + 1;
		if (b == m_pCheck[p])
		{
			b = m_pBase[p];
		}
		else
		{
			return lstResult;
		}
	}

	p = b;
	n = m_pBase[p];

	if (b == m_pCheck[p] && n < 0)
	{
		lstResult.push_back(-n - 1);
	}

	return lstResult;
}

int DoubleArrayTrie::Resize(int newSize)
{
	int* pNewBase = new int[newSize];
	int* pNewCheck = new int[newSize];
	bool* pNewUsed = new bool[newSize];

	if (m_nAllocSize > 0)
	{
		memcpy(pNewBase, m_pBase, m_nAllocSize*sizeof(int));
		memcpy(pNewCheck, m_pCheck, m_nAllocSize*sizeof(int));
		memcpy(pNewUsed, m_pUsed, m_nAllocSize*sizeof(int));

		delete[] m_pBase;
		delete[] m_pCheck;
		delete[] m_pUsed;
	}

	m_pBase = pNewBase;
	m_pCheck = pNewCheck;
	m_pUsed = pNewUsed;
	m_nAllocSize = newSize;

	return m_nAllocSize;
}

int DoubleArrayTrie::Fetch(Node* pParent, list<Node*>& siblings)
{
	int nPrev = 0;
	vector<string> vecKeys(m_lstKey.begin(), m_lstKey.end());
	for (int i = pParent->left; i < pParent->right; ++i)
	{
		if ((m_pLength != NULL ? m_pLength[i] : vecKeys[i].length()) < pParent->depth)
		{
			continue;
		}

		string tmp = vecKeys[i];
		int cur = 0;
		if ((m_pLength != NULL ? m_pLength[i] : tmp.length()) != pParent->depth)
			cur = (int)tmp.at(pParent->depth) + 1;

		if (nPrev > cur)
		{
			return 0;
		}

		if (cur != nPrev || siblings.size() == 0)
		{
			Node* tmp_node = new Node();
			tmp_node->depth = pParent->depth + 1;
			tmp_node->code = cur;
			tmp_node->left = i;
			if (siblings.size() != 0)
				//siblings.

			siblings.push_back(tmp_node);
		}

		nPrev = cur;
	}

	//if ()

	return siblings.size();
}