#include<stdio.h>
#include<stdlib.h>


#define V 6
#define E 9


struct Edge {
    int src, dest, weight;
};


struct Edge edges[E]={
{0,1,3},
{0,2,1},
{0,3,6},
{1,2,5},
{1,4,3},
{2,3,5},
{2,5,4},
{3,5,2},
{4,5,6}
};


int parent[V];


int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}


void unionSet(int i,int j)
{
    parent[i]=j;
}


int compare(const void* a,const void* b)
{
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}


void kruskal()
{
    qsort(edges,E,sizeof(edges[0]),compare);


    int count=0,i=0;
    int cost=0;


    while(count<V-1)
    {
        struct Edge next=edges[i++];


        int x=find(next.src);
        int y=find(next.dest);


        if(x!=y)
        {
            printf("C%d - C%d = %d\n",next.src+1,next.dest+1,next.weight);
            cost+=next.weight;
            unionSet(x,y);
            count++;
        }
    }


    printf("Total Cost = %d\n",cost);
}


int main()
{
    kruskal();
    return 0;
}
