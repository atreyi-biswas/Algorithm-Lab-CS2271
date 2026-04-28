#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 100
#define ES 120
#define ED 4500


// Node for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};


struct Node* adjList[N];


// Add edge to adjacency list
void addEdgeList(int src, int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}


// Display adjacency list
void displayList() {
    for(int i=0;i<N;i++) {
        printf("%d -> ", i);
        struct Node* temp = adjList[i];
        while(temp) {
            printf("(%d,w=%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {


    srand(time(NULL));


    for(int i=0;i<N;i++)
        adjList[i]=NULL;


    // Sparse graph
    for(int i=0;i<ES;i++) {
        int u = rand()%N;
        int v = rand()%N;
        int w = rand()%50+1;


        addEdgeList(u,v,w);
        addEdgeList(v,u,w);
    }


    printf("\nSparse Graph (Adjacency List)\n");
    displayList();


    // Dense Graph (Adjacency Matrix)
    int matrix[N][N]={0};
    int weight[N][N]={0};


    for(int i=0;i<ED;i++) {
        int u = rand()%N;
        int v = rand()%N;
        int w = rand()%50+1;


        matrix[u][v]=1;
        matrix[v][u]=1;


        weight[u][v]=w;
        weight[v][u]=w;
    }


    printf("\nDense Graph (Adjacency Matrix - Unweighted)\n");
    for(int i=0;i<10;i++) { // printing first 10 rows to limit output
        for(int j=0;j<10;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }


    printf("\nDense Graph (Adjacency Matrix - Weighted)\n");
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++)
            printf("%d ",weight[i][j]);
        printf("\n");
    }


    return 0;
}
