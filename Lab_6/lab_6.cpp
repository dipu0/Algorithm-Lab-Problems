#include <bits/stdc++.h>
int main()
{
    int n,arr[50],j,Min,Min_elemnt,i,k;
    printf("Enter a Amount of Inputs: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);

    int Matrix[n][n]= {0};
    int x[n][n]= {0};

    for(int l=1; l<n-1; l++)
    {

        for(i=1; i<n-l; i++)
        {
            j=i+l;
            Min=INT_MAX;
            for( k=i; k<=j-1; k++)
            {
                Min_elemnt=Matrix[i][k]+Matrix[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(Min_elemnt<Min)
                {
                    Min=Min_elemnt;
                    x[i][j]=k;
                }

            }
            Matrix[i][j]=Min;

            //printf(" %d ",Matrix[i][j]);

        }


    }

    for(int r=1;r<n;r++)
    {
        for(int y=1;y<n;y++)
        {
            printf("%d\t",Matrix[r][y]);
        }
        printf("\n ");
    }

    printf("\nCOST: %d", Matrix[1][n-1]);

}
