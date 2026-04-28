#include <stdio.h>
#include <limits.h>

#define V 10

int graph[V][V];

// Dijkstra
void dijkstra(int src) {
    int dist[V], visited[V] = {0};

    for(int i=0;i<V;i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for(int count=0; count<V-1; count++) {
        int u=-1, min=INT_MAX;

        for(int i=0;i<V;i++)
            if(!visited[i] && dist[i]<min)
                min=dist[i], u=i;

        visited[u]=1;

        for(int v=0; v<V; v++) {
            if(graph[u][v]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
        }
    }

    printf("\nDijkstra Output:\n");
    for(int i=0;i<V;i++)
        printf("%d -> %d\n", i, dist[i]);
}

int main() {
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            graph[i][j]=INT_MAX;

    int e;
    printf("Enter number of edges (negative allowed): ");
    scanf("%d",&e);

    for(int i=0;i<e;i++){
        int u,v,w;
        printf("Enter edge (u v w): ");
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v]=w;
    }

    int src;
    printf("Enter source: ");
    scanf("%d",&src);

    dijkstra(src);

    printf("\nNOTE: Results may be incorrect due to negative weights.\n");

    return 0;
}