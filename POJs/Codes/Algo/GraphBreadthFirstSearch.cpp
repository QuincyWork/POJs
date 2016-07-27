#include <gtest/gtest.h>
#include <queue>
#include "..\Structure\Graph.h"


void bfs_search(Graph const& graph, int s, vector<int>& dist, vector<int>& pred)
{	
	const int n = graph.numVertices();

	pred.assign(n,-1);
	dist.assign(n,numeric_limits<int>::max());
	vector<Graph::vertexColor> color(n,Graph::White);
	
	color[s] = Graph::Gray;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	
	while (!q.empty())
	{
		int u = q.front();
		
		for (Graph::VertexList::const_iterator it = graph.begin(u);
			it != graph.end(u); 
			++it)
		{
			int v = it->first;
			if (color[v] == Graph::White)
			{
				pred[v] = u;
				dist[v] = dist[u]+1;
				color[v] = Graph::Gray;
				q.push(v);
			}
		}
		q.pop();
		color[u] = Graph::Black;
	}
}

TEST(Algo, tGraphBfsSearch)
{
	Graph g(16,false);
	g.addEdge(0,1);
	g.addEdge(0,6);
	g.addEdge(0,8);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,10);
	g.addEdge(2,11);
	g.addEdge(3,4);
	g.addEdge(3,12);
	g.addEdge(4,5);
	g.addEdge(4,13);
	g.addEdge(5,6);
	g.addEdge(5,9);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(7,9);
	g.addEdge(8,14);
	g.addEdge(9,15);

	vector<int> pred;
	vector<int> dist;

	bfs_search(g,0,dist,pred);
}