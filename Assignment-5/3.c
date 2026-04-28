#include <stdio.h>
#include <stdlib.h>


int *parent;
int *rank;
int components;


int Find(int x)
{
    if(parent[x]!=x)
        parent[x]=Find(parent[x]);
    return parent[x];
}


void Union(int x,int y)
{
    int rootX=Find(x);
    int rootY=Find(y);


    if(rootX==rootY)
        return;


    if(rank[rootX]<rank[rootY])
        parent[rootX]=rootY;


    else if(rank[rootX]>rank[rootY])
        parent[rootY]=rootX;


    else
    {
        parent[rootY]=rootX;
        rank[rootX]++;
    }


    components--;
}


int main()
{
    int N,M,i;


    printf("Enter number of buildings: ");
    scanf("%d",&N);


    parent=(int*)malloc(N*sizeof(int));
    rank=(int*)malloc(N*sizeof(int));


    for(i=0;i<N;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }


    components=N;


    printf("Enter number of road connections: ");
    scanf("%d",&M);


    for(i=0;i<M;i++)
    {
        int u,v;


        printf("Enter buildings to connect: ");
        scanf("%d %d",&u,&v);


        Union(u,v);


        if(components==1)
            printf("City is fully connected\n");
        else
            printf("City is NOT fully connected\n");
    }


    free(parent);
    free(rank);


    return 0;
}
