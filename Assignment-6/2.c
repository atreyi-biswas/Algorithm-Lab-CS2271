#include<stdio.h>
#include<limits.h>


#define V 6


int graph[V][V] = {
{0,3,1,6,0,0},
{3,0,5,0,3,0},
{1,5,0,5,0,4},
{6,0,5,0,0,2},
{0,3,0,0,0,6},
{0,0,4,2,6,0}
};


int minKey(int key[], int mstSet[])
{
    int min = INT_MAX, min_index;


    for(int v=0; v<V; v++)
        if(mstSet[v]==0 && key[v]<min)
            min=key[v], min_index=v;


    return min_index;
}


void primMST()
{
    int parent[V];
    int key[V];
    int mstSet[V];


    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=0;
    }


    key[0]=0;
    parent[0]=-1;


    for(int count=0; count<V-1; count++)
    {
        int u=minKey(key,mstSet);
        mstSet[u]=1;


        for(int v=0; v<V; v++)
        {
            if(graph[u][v] && mstSet[v]==0 && graph[u][v]<key[v])
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }


    int total=0;


    printf("Edges in MST:\n");
    for(int i=1;i<V;i++)
    {
        printf("C%d - C%d = %d\n",parent[i]+1,i+1,graph[i][parent[i]]);
        total+=graph[i][parent[i]];
    }


    printf("Total Cost = %d\n",total);
}


int main()
{
    primMST();
    return 0;
}
