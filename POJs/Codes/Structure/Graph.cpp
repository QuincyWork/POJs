#include <gtest/gtest.h>
#include "Graph.h"


TEST(Algo, tGraph)
{
	// A B C D E F
	// A -> B, A -> D
	//
	Graph g(6,true);
	g.addEdge(0,1,6);
	g.addEdge(0,4,3);
	g.addEdge(0,5,4);
	g.addEdge(1,3,5);
	g.addEdge(2,5,10);
	g.addEdge(3,4,7);
	g.addEdge(4,5,11);

	ASSERT_TRUE(g.isEdge(0,1));
	ASSERT_TRUE(g.isEdge(3,4));
	ASSERT_FALSE(g.isEdge(3,0));

}