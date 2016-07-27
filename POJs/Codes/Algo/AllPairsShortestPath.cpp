#include <gtest/gtest.h>
#include "..\Structure\Graph.h"

using namespace std;

void allPairsShortestPath(Graph const& graph,vector< vector<int> >& dist,
	vector< vector<int> >& pred)
{
	// Init
	const int n = graph.numVertices();
	dist.assign(n,vector<int>());
	pred.assign(n,vector<int>());

	for (int u=0; u<n;++u)
	{
		dist[u].assign(n,numeric_limits<int>::max());
		pred[u].assign(n,-1);
		dist[u][u] = 0;
		for (Graph::VertexList::const_iterator it = graph.begin(u);
				it != graph.end(u);
				++it)
		{
			int v= it->first;
			dist[u][v] = it->second;
			pred[u][v] = u;
		}
	}

	for (int t =0; t<n;++t)
	{
		for (int u=0;u<n;++u)
		{
			for (int v=0; v<n;++v)
			{
				int newLen = dist[u][t] + dist[t][v];
				if (newLen < dist[u][v])
				{
					dist[u][v] = newLen;
					pred[u][v] = pred[t][v];
				}
			}
		}
	}
}

void constructShortestPath(int s, int t, vector< vector<int> >& pred, list<int>& path)
{
	if (s < 0 || s >= (int)pred.size() || t < 0 || t >= (int)pred.size())
		return;

	path.clear();
	path.push_front(t);
	while (s != t)
	{
		t = pred[s][t];
		if (t == -1)
		{
			path.clear();
			return;
		}
		path.push_front(t);
	}
}

TEST(Algo, tAllPairsShortestPath)
{
	Graph g(6,true);
	g.addEdge(0,1,6);
	g.addEdge(0,2,8);
	g.addEdge(0,3,18);
	g.addEdge(1,4,11);
	g.addEdge(2,3,9);
	g.addEdge(4,5,3);
	g.addEdge(5,2,7);

	vector< vector<int> > dist;
	vector< vector<int> > pred;
	allPairsShortestPath(g,dist,pred);

	list<int> path;
	constructShortestPath(0,5,pred,path);
}