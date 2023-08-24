#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices
#define E 7 // Number of edges

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge *edge;
};

struct Graph *createGraph(int numVertices, int numEdges) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edge = (struct Edge *)malloc(numEdges * sizeof(struct Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST(struct Graph *graph) {
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    qsort(graph->edge, graph->numEdges, sizeof(graph->edge[0]), compareEdges);

    int mstWeight = 0;
    printf("Edge \tWeight\n");

    for (int i = 0; i < graph->numEdges; i++) {
        int src = graph->edge[i].src;
        int dest = graph->edge[i].dest;
        int srcSet = find(parent, src);
        int destSet = find(parent, dest);

        if (srcSet != destSet) {
            printf("%d - %d \t%d\n", src, dest, graph->edge[i].weight);
            mstWeight += graph->edge[i].weight;
            unionSet(parent, srcSet, destSet);
        }
    }

    printf("Minimum Spanning Tree Weight: %d\n", mstWeight);
}

int main() {
    struct Graph *graph = createGraph(V, E);
    
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    graph->edge[5].src = 1;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 8;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 12;

    kruskalMST(graph);

    free(graph->edge);
    free(graph);

    return 0;
}

