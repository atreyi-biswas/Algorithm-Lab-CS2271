#include <stdio.h>
#include <stdlib.h>


int *parent;
int *rank;


int Find(int x)
{
    if(parent[x] != x)
        parent[x] = Find(parent[x]);   // Path Compression
    return parent[x];
}


void Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);


    if(rootX == rootY)
        return;


    if(rank[rootX] < rank[rootY])
        parent[rootX] = rootY;


    else if(rank[rootX] > rank[rootY])
        parent[rootY] = rootX;


    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}


int main()
{
    int n,m,i;


    printf("Enter number of elements: ");
    scanf("%d",&n);


    parent = (int*)malloc(n*sizeof(int));
    rank = (int*)malloc(n*sizeof(int));


    for(i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }


    printf("Enter number of union operations: ");
    scanf("%d",&m);


    for(i=0;i<m;i++)
    {
        int x,y;
        printf("Enter elements to union: ");
        scanf("%d %d",&x,&y);


        Union(x,y);
    }


    printf("Parent array:\n");
    for(i=0;i<n;i++)
        printf("%d ",parent[i]);


    int x;
    printf("\nEnter element to find representative: ");
    scanf("%d",&x);


    printf("Representative = %d\n",Find(x));


    free(parent);
    free(rank);


    return 0;
}
