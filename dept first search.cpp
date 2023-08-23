#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack) {
    return stack->array[stack->top--];
}

struct Graph {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

void initGraph(struct Graph *graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void DFS(struct Graph *graph, int startNode, int visited[]) {
    visited[startNode] = 1;
    printf("%d ", startNode);

    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjMatrix[startNode][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    struct Graph graph;
    int numNodes = 6;

    initGraph(&graph, numNodes);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);

    int visited[MAX_NODES] = {0};

    printf("Depth First Traversal starting from node 0: ");
    DFS(&graph, 0, visited);
    printf("\n");

    return 0;
}

