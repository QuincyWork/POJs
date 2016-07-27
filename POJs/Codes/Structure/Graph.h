#include <list>
#include <map>
using namespace std;

//class Graph2
//{
//public:
//	enum vertexColor
//	{
//		White,
//		Gray,
//		Black
//	};
//
//	typedef pair<int,int> IntegerPair;
//	typedef list<IntegerPair> VertexList;
//	typedef map<int, VertexList*> VertexMap;
//	
//	Graph2()
//	{
//		m_count = 0;
//		m_directed = false;
//	}
//
//	Graph2(int n, bool directed);
//	Graph2(int n);
//	~Graph2()
//	{
//		VertexMap::iterator it = m_vertexMap.begin();
//		for (; it != m_vertexMap.end(); ++it)
//		{
//			delete it->second;
//		}
//		m_vertexMap.clear();
//	}
//
//	bool directed() const
//	{
//		return m_directed;
//	}
//
//	int numVertices() const
//	{
//		return m_count;
//	}
//
//	bool isEdge(int u, int v)
//	{
//		int edgeWeight = 0;
//		return isEdge(u, v, edgeWeight);
//	}
//
//
//	bool isEdge(int u, int v, int& weight)
//	{
//		bool bEdge = false;
//		VertexMap::const_iterator it = m_vertexMap.find(u);
//		if (it != m_vertexMap.end())
//		{
//			VertexList* vList = it->second;
//			for (VertexList::const_iterator itV = vList->begin();
//					itV != vList->end(); ++itV)
//				{
//					if (itV->first == v)
//					{
//						bEdge = true;
//						weight = itV->second;
//						break;
//					}
//				}
//		}
//
//		return bEdge;
//	}
//
//	int edgeWeight(int u, int v)
//	{
//		int edgeWeight = 0;
//		isEdge(u, v, edgeWeight);
//		return edgeWeight;
//	}
//
//	void addEdge(int u, int v)
//	{
//		addEdge(u,v,0);
//	}
//
//	void addEdge(int u, int v, int weight)
//	{
//		VertexMap::iterator it = m_vertexMap.find(u);
//		if (it != m_vertexMap.end())
//		{
//			it->second->push_back(make_pair(v,weight));
//		}
//		else
//		{
//			VertexList* newList = new VertexList();
//			newList->push_back(make_pair(v,weight));
//			m_vertexMap.insert(make_pair(u,newList));
//		}
//	}
//
//	bool removeEdge(int u, int v)
//	{
//		bool remove = false;
//		VertexMap::iterator it = m_vertexMap.find(u);
//		if (it != m_vertexMap.end())
//		{
//			VertexList* vList = it->second;
//			for (VertexList::iterator itV = vList->begin();
//				itV != vList->end(); ++itV)
//			{
//				if (itV->first == v)
//				{
//					vList->erase(itV);
//					remove = true;
//					break;
//				}
//			}
//		}
//
//		return remove;
//	}
//
//	VertexList::const_iterator begin(int u)
//	{
//		VertexMap::iterator it = m_vertexMap.find(u);
//		if (it != m_vertexMap.end())
//		{
//			return it->second->begin();
//		}
//	}
//
//	VertexList::const_iterator end(int u)
//	{
//		VertexMap::iterator it = m_vertexMap.find(u);
//		if (it != m_vertexMap.end())
//		{
//			return it->second->end();
//		}
//	}
//
//private:
//	bool m_directed;
//	VertexMap m_vertexMap;
//	int m_count;
//};

class Graph
{
public:
	enum vertexColor
	{
		White,
		Gray,
		Black
	};

	typedef pair<int,int> IntegerPair;
	typedef list<IntegerPair> VertexList;

	Graph()
	{
		m_count = 0;
		m_directed = false;
		m_vertexList = NULL;
	}

	Graph(int n, bool directed)
	{
		m_count = n;
		m_directed = directed;
		m_vertexList = NULL;
		if (n)
		{
			m_vertexList = new VertexList[n];
		}
	}

	Graph(int n)
	{
		Graph(n,false);
	}

	~Graph()
	{
		if (m_vertexList)
		{
			delete[] m_vertexList;
		}
		m_vertexList = NULL;
	}

	bool directed() const
	{
		return m_directed;
	}

	int numVertices() const
	{
		return m_count;
	}

	bool isEdge(int u, int v)
	{
		int edgeWeight = 0;
		return isEdge(u, v, edgeWeight);
	}


	bool isEdge(int u, int v, int& weight) const
	{
		bool bEdge = false;
		if ( u > m_count)
		{
			return false;
		}

		for (VertexList::const_iterator itV = m_vertexList[u].begin();
			itV != m_vertexList[u].end(); ++itV)
		{
				if (itV->first == v)
				{
					bEdge = true;
					weight = itV->second;
					break;
				}
		}

		return bEdge;
	}

	int edgeWeight(int u, int v) const
	{
		int edgeWeight = 0;
		isEdge(u, v, edgeWeight);
		return edgeWeight;
	}

	void addEdge(int u, int v)
	{
		addEdge(u,v,0);
	}

	void addEdge(int u, int v, int weight)
	{
		if (u > m_count)
		{
			return;
		}

		if (m_directed)
		{
			m_vertexList[u].push_back(make_pair(v,weight));
		}
		else
		{
			// 无向图，需要添加两个边
			m_vertexList[u].push_back(make_pair(v,weight));
			m_vertexList[v].push_back(make_pair(u,weight));
		}
	}

	bool removeEdge(int u, int v)
	{
		if (u > m_count)
		{
			return false;
		}

		bool remove = false;
		for (VertexList::iterator itV = m_vertexList[u].begin();
			itV != m_vertexList[u].end(); ++itV)
		{
			if (itV->first == v)
			{
				m_vertexList[u].erase(itV);
				remove = true;
				break;
			}
		}

		if (!m_directed)
		{
			for (VertexList::iterator itV = m_vertexList[v].begin();
			itV != m_vertexList[v].end(); ++itV)
			{
				if (itV->first == u)
				{
					m_vertexList[v].erase(itV);
					remove = true;
					break;
				}
			}
		}

		return remove;
	}

	VertexList::const_iterator begin(int u) const
	{
		return m_vertexList[u].begin();
	}

	VertexList::const_iterator end(int u) const
	{
		return m_vertexList[u].end();
	}

private:
	bool m_directed;
	VertexList* m_vertexList;
	int m_count;
};