#include <stdio.h>
#include <stdlib.h>


struct Edge
{
    int src, dst;
};

struct Graph
{
    int V, E;
    Edge * edges;
};

Graph createGraph(int V, int E)
{
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges = (Edge*) malloc (sizeof(Edge) * E);
    return graph;
}

int findParent(int * parent, int pos)
{
    if(parent[pos] == pos)
    {
        return pos;
    }
    return findParent(parent, parent[pos]);
}

bool isCycle(Graph g)
{
    int parent[g.V];
    parent[0] = 3;

    // make sets
    for(int i = 0; i < g.V; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < g.E; i++)
    {
        int src = g.edges[i].src;
        int dst = g.edges[i].dst;

        int srcParent = findParent(parent, src);
        int dstParent = findParent(parent, dst);

        if(srcParent == dstParent)
        {
            return true;
        }

        parent[srcParent] = dstParent;
    }

    return false;
}

int main()
{
    int V = 4;
    int E = 4;
    Graph g = createGraph(V, E);
    g.edges[0].src = 0;
    g.edges[0].src = 1;
    g.edges[1] = {1, 2};
    g.edges[2] = {2, 3};
    g.edges[3] = {0, 2};

    printf("Graph is %s\n", isCycle(g) ? "circuit" : "safe");

    return 0;
}