#include <gtest/gtest.h>
#include "..\Structure\Graph.h"

void singleSourceShortest(Graph const& graph, int s, vector<int>& dist, vector<int>& pred)
{
	const int n = graph.numVertices();
	pred.assign(n,-1);
	dist.assign(n,numeric_limits<int>::max());
	vector<bool> visited(n,false);

	dist[s] = 0;
	while (true)
	{
		int u = -1;
		int sd = numeric_limits<int>::max();
		
		// Get the min dist
		for (int i=0; i<n; ++i)
		{
			if (!visited[i] && dist[i] < sd)
			{
				sd = dist[i];
				u = i;
			}
		}

		if (u == -1)
			break;

		visited[u] = true;
		for (Graph::VertexList::const_iterator it = graph.begin(u);
			it != graph.end(u);
			++it)
		{
			int v = it->first;
			int newLen = dist[u] + it->second;
			if (newLen < dist[v])
			{
				dist[v] = newLen;
				pred[v] = u;
			}
		}
	}
}

TEST(Algo, tSingleSourceShortest)
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