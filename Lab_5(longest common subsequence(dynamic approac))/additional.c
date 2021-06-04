#include<stdio.h>
#include<string.h>
char X[20],Y[20];
int count=0,cnt[20][20],Str_X=0,Str_Y=0;

void Prinr_SC(int i,int j)
{
    if(i==0 || j==0)
        cnt[i][j]=0;
    else if(X[i-1]==Y[j-1])
    {
        Prinr_SC(i-1,j-1);
        if(count==cnt[Str_X][Str_Y])
        {
            count=0;
            printf("\n");
        }
        printf("%c",X[i-1]);
        count++;
    }
    else if(cnt[i-1][j]==cnt[i][j-1])
    {
        Prinr_SC(i-1,j);
        Prinr_SC(i,j-1);
    }
    else if(cnt[i][j-1]>=cnt[i-1][j])
        Prinr_SC(i,j-1);
    else
        Prinr_SC(i-1,j);

}

void main()
{
    int i,j;
    printf("Enter 1st string: ");
    scanf("%s",X);
    printf("Enter 2nd string: ");
    scanf("%s",Y);

    Str_X=strlen(X);
    Str_Y=strlen(Y);

    for(i=0; i<=Str_X; i++)
    {
        for(j=0; j<=Str_Y; j++)
        {
            if(i==0 || j==0)
                cnt[i][j]=0;

            else if(X[i-1]==Y[j-1])
                cnt[i][j]=cnt[i-1][j-1]+1;

            else if(cnt[i-1][j]>=cnt[i][j-1])
                cnt[i][j]=cnt[i-1][j];

            else
                cnt[i][j]=cnt[i][j-1];

        }
    }
    for(i=0; i<=Str_X; i++)
    {
        for(j=0; j<=Str_Y; j++)
        {
            printf("%d\t",cnt[i][j]);
        }
        printf("\n");
    }
    Prinr_SC(Str_X,Str_Y);

}
