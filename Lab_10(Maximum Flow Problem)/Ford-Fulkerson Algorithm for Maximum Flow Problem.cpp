/*Ford-Fulkerson Algorithm for Maximum Flow Problem*/
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int ResGraph[][6],int s,int t,int parent[])
{
    bool visit[6];
    memset(visit,0,sizeof(visit));
    queue <int> Q;
    Q.push(s);
    visit[s]=true;
    parent[s]=-1;
    while(!Q.empty())
    {
        int i=Q.front();
        Q.pop();
        for (int j=0; j<6; j++)
        {
            if(visit[j]==false && ResGraph[i][j]>0)
            {
                Q.push(j);
                parent[j]=i;
                visit[j]=true;
            }
        }
    }
    return (visit[t]==true);
}

void Ford_Fulkerson(int graph[100][100],int s,int t)
{
    int i,j;
    int ResGraph[6][6];
    for (i=0; i<t+1; i++)
    {
        for (j=0; j<t+1; j++)
        {
            ResGraph[i][j]=graph[i][j];
        }
    }
    int p[t+1];
    int MaxFlow=0;
    while(bfs(ResGraph,s,t,p))
    {
        int PathFlow=INT_MAX;
        for(j=t; j!=s; j=p[j])
        {
            i=p[j];
            PathFlow=min(PathFlow, ResGraph[i][j]);
        }
        for(j=t; j!=s; j=p[j])
        {
            i=p[j];
            ResGraph[i][j]-=PathFlow;
            ResGraph[j][i]+=PathFlow;
        }
        MaxFlow+=PathFlow;
    }
    printf("\nMax flow : %d\n\n",MaxFlow);
}
int main()
{
    int graph[100][100];
    int n,e,u,v,w,i,j;
    printf("Enter number of vertex: ");
    scanf("%d",&n);
    printf("Enter number of edge: ");
    scanf("%d",&e);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            graph[i][j]=0;
        }
    }
    printf("Enter edges with capacity:\n");

    for(i=0; i<e; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]=w;
    }
    printf("\n");

    Ford_Fulkerson(graph,0,n);

    return 0;
}

