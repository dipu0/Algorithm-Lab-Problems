#include<stdio.h>

void main()
{
    int n,u,v,j,i,d[10],from[10];
    int Graph[10][10], span[10][10], c[10][10];
    int edges, IsVisited[10], MinDistance, MinCost;
    printf("Enter No. of Vertices:");
    scanf("%d",&n);

    printf("\nEnter The Adjacency Matrix:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&Graph[i][j]);
        }

    }


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(Graph[i][j]==0)
            {
                c[i][j]=99999;
            }

            else
            {
                c[i][j]=Graph[i][j];
            }


            span[i][j]=0;
        }
    d[0]=0;
    IsVisited[0]=1;

    for(i=1; i<n; i++)
    {
        d[i]=c[0][i];
        from[i]=0;
        IsVisited[i]=0;
    }

    MinCost=0;
    edges=n-1;

    while(edges>0)
    {
        MinDistance=99999;
        for(i=1; i<n; i++)
            if(IsVisited[i] == 0&& d[i]<MinDistance)
            {
                v=i;
                MinDistance=d[i];
            }

        u=from[v];
        span[u][v]=d[v];
        span[v][u]=d[v];
        edges--;
        IsVisited[v]=1;
        for(i=1; i<n; i++)
            if(IsVisited[i]==0&&c[i][v]<d[i])
            {
                d[i]=c[i][v];
                from[i]=v;
            }

        MinCost+=c[u][v];
    }

    printf("\nSpanning tree:\n");

    for(i=0; i<n; i++)
    {
        printf("\n");
        for(j=0; j<n; j++)
            printf("%d\t",span[i][j]);
    }


    printf("\n\nTotal Cost : %d",MinCost);

}


