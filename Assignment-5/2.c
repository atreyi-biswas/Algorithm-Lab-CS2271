#include <stdio.h>
#include <stdlib.h>


int *parent;
int *rank;


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
}


int main()
{
    int n,m,i;


    printf("Enter number of students: ");
    scanf("%d",&n);


    parent=(int*)malloc(n*sizeof(int));
    rank=(int*)malloc(n*sizeof(int));


    for(i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }


    printf("Enter number of friendship operations: ");
    scanf("%d",&m);


    for(i=0;i<m;i++)
    {
        int x,y;


        printf("Enter two students forming friendship: ");
        scanf("%d %d",&x,&y);


        Union(x,y);


        if(Find(x)==Find(y))
            printf("They belong to same friend group\n");
        else
            printf("Different groups\n");
    }


    free(parent);
    free(rank);


    return 0;
}
