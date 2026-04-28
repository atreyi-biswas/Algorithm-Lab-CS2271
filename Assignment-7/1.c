#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define V 10

// Adjacency List Node
struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* adj[V];
int matrix[V][V];

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    matrix[u][v] = w;
}

// Dijkstra using adjacency list (simple version)
void dijkstraList(int src) {
    int dist[V], visited[V] = {0};

    for(int i=0;i<V;i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int count=0; count<V-1; count++) {
        int u = -1, min = INT_MAX;

        for(int i=0;i<V;i++)
            if(!visited[i] && dist[i] < min)
                min = dist[i], u = i;

        visited[u] = 1;

        struct Node* temp = adj[u];
        while(temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

            temp = temp->next;
        }
    }

    printf("\nAdj List Distances:\n");
    for(int i=0;i<V;i++)
        printf("%d -> %d\n", i, dist[i]);
}

// Dijkstra using matrix
void dijkstraMatrix(int src) {
    int dist[V], visited[V] = {0};

    for(int i=0;i<V;i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int count=0; count<V-1; count++) {
        int u = -1, min = INT_MAX;

        for(int i=0;i<V;i++)
            if(!visited[i] && dist[i] < min)
                min = dist[i], u = i;

        visited[u] = 1;

        for(int v=0; v<V; v++) {
            if(matrix[u][v] != INT_MAX && dist[u] + matrix[u][v] < dist[v])
                dist[v] = dist[u] + matrix[u][v];
        }
    }

    printf("\nAdj Matrix Distances:\n");
    for(int i=0;i<V;i++)
        printf("%d -> %d\n", i, dist[i]);
}

int main() {
    for(int i=0;i<V;i++) {
        adj[i] = NULL;
        for(int j=0;j<V;j++)
            matrix[i][j] = INT_MAX;
    }

    int e;
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i=0;i<e;i++) {
        int u,v,w;
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u,v,w);
    }

    int src;
    printf("Enter source: ");
    scanf("%d", &src);

    clock_t t1 = clock();
    dijkstraList(src);
    clock_t t2 = clock();

    clock_t t3 = clock();
    dijkstraMatrix(src);
    clock_t t4 = clock();

    printf("\nTime (List): %lf ms", (double)(t2-t1));
    printf("\nTime (Matrix): %lf ms\n", (double)(t4-t3));

    return 0;
}