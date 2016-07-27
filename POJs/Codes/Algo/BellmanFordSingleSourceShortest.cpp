#include <gtest/gtest.h>
#include "..\Structure\Graph.h"

void singleSourceShortest(Graph const& graph, int s, vector<int>& dist, vector<int>& pred)
{
	const int n = graph.numVertices();
	dist.assign(n, numeric_limits<int>::max());
	pred.assign(n,-1);

	dist[s] = 0;
	for (int i=1 ; i<=n; ++i)
	{
		bool failOnUpdate = (i==n);
		bool bExist = true;

		for (int u = 0; u < n; ++u)
		{
			for (Graph::VertexList::const_iterator it = graph.begin(u);
				it != graph.end(u);
				++it)
			{
				int v = it->first;
				int newLen = dist[u] + it->second;
				if (newLen < dist[v])
				{
					if (failOnUpdate)
						return;

					dist[v] = newLen;
					pred[v] =u;
					bExist = false;
				}
			}
		}

		if (bExist)
			break;
	}
}

TEST(Algo, tBFSingleSourceShortest)
{
	Graph g(6,true);
	g.addEdge(0,1,6);
	g.addEdge(0,2,8);
	g.addEdge(0,3,18);
	g.addEdge(1,4,11);
	g.addEdge(2,3,9);
	g.addEdge(4,5,3);
	g.addEdge(5,2,7);

	vector<int> dist;
	vector<int> pred;
	singleSourceShortest(g,0,dist,pred);
}