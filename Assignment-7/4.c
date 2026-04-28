#include <stdio.h>
#include <limits.h>

struct Edge {
    int u,v,w;
};

int main() {
    int V,E;
    printf("Enter vertices and edges: ");
    scanf("%d %d",&V,&E);

    struct Edge edges[E];

    printf("Enter edges (u v w):\n");
    for(int i=0;i<E;i++)
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);

    int src;
    printf("Enter source: ");
    scanf("%d",&src);

    int dist[V];
    for(int i=0;i<V;i++) dist[i]=INT_MAX;
    dist[src]=0;

    // Relax edges
    for(int i=1;i<V;i++){
        for(int j=0;j<E;j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;

            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }

    // Check negative cycle
    for(int j=0;j<E;j++){
        int u=edges[j].u;
        int v=edges[j].v;
        int w=edges[j].w;

        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            printf("Negative Weight Cycle Detected!\n");
            return 0;
        }
    }

    printf("\nShortest Distances:\n");
    for(int i=0;i<V;i++)
        printf("%d -> %d\n", i, dist[i]);

    return 0;
}