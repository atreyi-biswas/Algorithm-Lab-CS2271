#include<stdio.h>


#define V1 4
#define V2 4


// Example graphs
int G1[V1][V1]={
{0,2,0,6},
{2,0,3,8},
{0,3,0,0},
{6,8,0,0}
};


int G2[V2][V2]={
{0,5,2,0},
{5,0,4,6},
{2,4,0,3},
{0,6,3,0}
};


void prim(int graph[V2][V2], int V)
{
    int selected[V];
    int no_edge=0;


    for(int i=0;i<V;i++)
        selected[i]=0;


    selected[0]=1;


    int total=0;


    while(no_edge<V-1)
    {
        int min=999;
        int x=0,y=0;


        for(int i=0;i<V;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<V;j++)
                {
                    if(!selected[j] && graph[i][j])
                    {
                        if(min>graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }


        printf("%d-%d : %d\n",x,y,graph[x][y]);
        total+=graph[x][y];
        selected[y]=1;
        no_edge++;
    }


    printf("Prim MST cost: %d\n",total);
}


int main()
{
    printf("MST of Dense Graph G2 using Prim:\n");
    prim(G2,V2);


    int mandatoryEdge=20;
    printf("\nMandatory Edge connecting G1 and G2 cost = %d\n",mandatoryEdge);


    return 0;
}
