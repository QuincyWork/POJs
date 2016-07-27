#include <gtest/gtest.h>
#include <vector>
#include "..\Structure\Graph.h"
using namespace std;

void dfs_visit(Graph const& graph, int u, vector<int>& pred, 
	vector<Graph::vertexColor>& color,vector<int>& d,vector<int>& f,
	int& index)
{
	color[u] = Graph::Gray;
	d[u] = ++index;
	
	for (Graph::VertexList::const_iterator it = graph.begin(u);
		it != graph.end(u);
		++it)
	{
		int v = it->first;
		if (color[v] == Graph::White)
		{
			pred[v] = u;
			dfs_visit(graph,v,pred,color,d,f,index);
		}
	}

	color[u] = Graph::Black;
	f[u] = ++index;
}

void dfs_search(Graph const& graph, int s, vector<int>& pred, vector<int>& d, vector<int>& f)
{
	const int n = graph.numVertices();
	int index = 0;
	pred.assign(n, -1);
	d.assign(n,-1);
	f.assign(n,-1);

	vector<Graph::vertexColor> color(n, Graph::White);
	dfs_visit(graph, s, pred, color,d,f,index);
	for (int u = 0; u < n; ++u)
	{
		if (color[u] == Graph::White)
		{
			dfs_visit(graph,u,pred,color,d,f,index);
		}
	}
}

TEST(Algo, tDfsSearch)
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
	vector<int> d;
	vector<int> f;
	
	dfs_search(g,0,pred,d,f);
}