#include<stdio.h>
#define MAX 20

typedef struct Edge
{
	int u,v,w;
}edge;

typedef struct edgelist
{
	edge data[MAX];
	int n;
}edgelist;

edgelist newlist;

int Graph[MAX][MAX],n;
edgelist s;
int look(int b[],int v)
{
	return(b[v]);
}

void union1(int b[],int c,int d)
{
	int i;

	for(i=0;i<n;i++)
		if(b[i]==d)
			b[i]=c;
}

void sort1()
{
	int i,j;
	edge temp;

	for(i=1;i<newlist.n;i++)
		for(j=0;j<newlist.n-1;j++)
			if(newlist.data[j].w>newlist.data[j+1].w)
			{
				temp=newlist.data[j];
				newlist.data[j]=newlist.data[j+1];
				newlist.data[j+1]=temp;
			}
}

void kruskal()
{
	int b[MAX],i,j,p,q;
	newlist.n=0;

	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(Graph[i][j]!=0)
			{
				newlist.data[newlist.n].u=i;
				newlist.data[newlist.n].v=j;
				newlist.data[newlist.n].w=Graph[i][j];
				newlist.n++;
			}
		}

	sort1();

	for(i=0;i<n;i++)
		b[i]=i;

	s.n=0;

	for(i=0;i<newlist.n;i++)
	{
		p=look(b,newlist.data[i].u);
		q=look(b,newlist.data[i].v);

		if(p!=q)
		{
			s.data[s.n]=newlist.data[i];
			s.n=s.n+1;
			union1(b,p,q);
		}
	}
}
int main()
{
	int i,j,cost=0;

	printf("Enter the number of vertices:");

	scanf("%d",&n);

	printf("\nEnter The Adjacency Matrix:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&Graph[i][j]);

	kruskal();
	printf("\nThe Spanning Tree is : ");
	for(i=0;i<s.n;i++)
	{
		printf("\n%d\t%d\t%d",s.data[i].u,s.data[i].v,s.data[i].w);
		cost=cost+s.data[i].w;
	}

	printf("\n\nCost of the panning tree is : %d units",cost);
}


