#include <stdio.h>
#include <stdbool.h>
#define MAX_EDGES 50
struct Edge
{
    int src, dest, weight;
};
struct Graph
{
    int V, E;
    struct Edge edges[MAX_EDGES];
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
int compareEdges(const void *a, const void *b)
{
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;
    return edge1->weight - edge2->weight;
}
void kruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);
    int parent[V];
    memset(parent, -1, sizeof(parent));
    while (e < V - 1 && i < graph->E)
    {
        struct Edge nextEdge = graph->edges[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);
        if (x != y)
        {
            result[e++] = nextEdge;
            Union(parent, x, y);
        }
    }
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest,
               result[i].weight);
}
int main()
{
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph
    struct Graph *graph = createGraph(V, E);
    // Add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;
    // Add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;
    // Add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;
    // Add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;
    // Add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;
    kruskalMST(graph);
    return 0;
}