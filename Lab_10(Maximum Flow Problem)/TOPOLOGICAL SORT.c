#include<stdio.h>
int main()
{
    int i,j,k,n;
    printf("Enter the no of vertex: ");
    scanf("%d",&n);
    int mat[20][20],InDegree[20],t[20];
    int cnt=0;

    printf("Enter the adjacency matrix:\n");

    for(i=0; i<n; i++)
    {

        for(j=0; j<n; j++)
            scanf("%d",&mat[i][j]);
    }
    for(i=0; i<n; i++)
    {
        InDegree[i]=0;
        t[i]=0;
    }

    for(i=0; i<n; i++)

        for(j=0; j<n; j++)

            InDegree[i]=InDegree[i]+mat[j][i];

    printf("\nThe Topological Order: ");

    while(cnt<n)
    {

        for(k=0; k<n; k++)
        {

            if((InDegree[k]==0) && (t[k]==0))
            {

                printf("%d ",(k+1));

                t[k]=1;
            }
            for(i=0; i<n; i++)
            {

                if(mat[i][k]==1)

                    InDegree[k]--;
            }
        }
        cnt++;

    }
    return 0;
}
