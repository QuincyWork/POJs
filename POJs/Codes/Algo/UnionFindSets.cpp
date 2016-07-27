#include <gtest/gtest.h>
#include <vector>

using namespace std;

class UnionFindSet
{
public:
	void MakeSet(int max)
	{
		m_vecId.assign(max,0);
		for (int i=0; i<max; i++)
		{
			m_vecId[i] = i;
		}

		m_nSetsCount = max;
	}

	int Find(int x)
	{
		return m_vecId[x];
	}

	void UnionSet(int x, int y)
	{
		int xId = Find(x);
		int yId = Find(y);

		if (xId == yId)
		{
			return;
		}

		for (unsigned int i=0; i<m_vecId.size(); ++i)
		{
			if (m_vecId[i] == xId)
			{
				m_vecId[i] = yId;
			}
		}

		--m_nSetsCount;
	}

	int Count()
	{
		return m_nSetsCount;
	}

	bool SameSet(int x, int y)
	{
		return (Find(x) == Find(y));
	}

private:

	vector<int> m_vecId;
	int m_nSetsCount;
};

TEST(Algo, tUnionFindSet)
{
	// 测试集合，按照字母大小写来区分
	char SetData[] = {'A','b','C','E','d','e','F'};

	UnionFindSet uf;
	uf.MakeSet(7);

	uf.UnionSet(0,2); // A C
	uf.UnionSet(2,3); // C E
	uf.UnionSet(3,6); // E F

	uf.UnionSet(1,4); // b d
	uf.UnionSet(4,5); // d e

	ASSERT_TRUE(uf.SameSet(0,3));
	ASSERT_TRUE(uf.SameSet(6,2));
	ASSERT_TRUE(uf.SameSet(1,5));

	ASSERT_FALSE(uf.SameSet(0,5));
	ASSERT_FALSE(uf.SameSet(2,1));
	ASSERT_FALSE(uf.SameSet(6,4));
}
