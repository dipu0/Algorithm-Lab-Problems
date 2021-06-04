#include<bits/stdc++.h>
using namespace std;
struct node
{
    int nd,Weight;
}temp;

struct Line
{
    int Name,Key;
    bool flag;
} A[100];

vector<node> g[100];
int n, dis[100],par[100];

int pop()
{
    int min=1000000;
    int index;
    for(int i=0; i<n; i++)
    {
        if(A[i].Key < min && A[i].flag==true)
        {
            min=A[i].Key;
            index=i;
        }
    }
    A[index].flag=false;
    return index;
}

bool isEmpty()
{
    for(int i=0; i<n; i++)
    {
        if(A[i].flag)
            return false;
    }
    return true;
}
int Dijkstra(int n,int u, int v, int w)
{
    while(!isEmpty())
    {
        int u=pop();
        for(int i=0; i<g[u].size(); i++)
        {
            node t=g[u][i];
            int v=t.nd;
            int w=t.Weight;
            if(dis[v]>dis[u]+w)
            {
            dis[v]=dis[u]+w;
            par[v]=u;
            A[v].Key=dis[v];
            }
        }
    }
}

void PrintPath(int parent[],int node,int length)
{
    if(node==-1) return;
    PrintPath(parent,parent[node],length+1);
    cout<<(char)(65+node);
    if(length!=0){
        cout<<", ";
    }
}

int main()
{
    int u,v,w,i,edge;
    cout<<"Enter number of vertex: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>edge;
    cout<<"Enter edges along with Weight:\n";
    for(i=0; i<edge; i++)
    {
        cin>>u>>v>>w;
        temp.nd=v;
        temp.Weight=w;
        g[u].push_back(temp);
        temp.nd=u;
        g[v].push_back(temp);
    }
    for(int k=0;k<n;k++){
        for(i=0; i<n; i++)
        {
            dis[i]=99999;
            par[i]=-1;
        }
        dis[k]=0;
        for(i=0; i<n; i++)
        {
            A[i].Name=i;
            A[i].Key=dis[i];
            A[i].flag=true;
        }

        cout<<"Source node: "<<(char)(65+k);
        cout<<"\nDestination Node      Min Cost         Min path\n"<<endl;
        Dijkstra(n,u,v,w);
        for(i=0; i<n; i++)
        {
            cout<<(char)(65+i)<<"                           ";
            cout<<dis[i]<<"                 ";
            PrintPath(par,i,0);
            cout<<endl;
        }

    }
    return 0;
}

