#include<stdio.h>
#include<string.h>

int Find_Max(int a, int b)
{

    if(a>b)
        return a;

    else
        return b;

}

int main(void)
{
    int i, c, k;
    char X[20], Y[20];
    //char x[] = "ABCF"; char y[] = "ACF";
    printf("Enter string number 1 : ");
    scanf("%s",X);

    printf("Enter string number 2 : ");
    scanf("%s",Y);

    int Str_X = strlen(X);
    int Stre_Y = strlen(Y);


    int L[Str_X + 1][Stre_Y + 1];
    printf("Table : ");

    for(k = 0; k <= Str_X; k++)
    {
        printf("\n");

        for(c = 0; c <= Stre_Y; c++)
        {

            if(k == 0 || c == 0)
            {

                L[k][c] = 0;
                printf("%d\t",L[k][c]);

            }
            else if(X[k - 1] == Y[c - 1])
            {

                L[k][c] = L[k - 1][c - 1] + 1;
                printf("%d\t",L[k][c]);

            }
            else
            {

                L[k][c] = Find_Max(L[k - 1][c], L[k][c - 1]);
                printf("%d\t",L[k][c]);
            }
        }
    }

    k = Str_X; c = Stre_Y;
    i = L[k][c];

    char LCS[i+1];


    LCS[i] = '\0';
    while(c > 0 && k > 0 )
    {

        if(X[k - 1] == Y[c - 1])
        {

            LCS[i - 1] = X[k - 1];

            i--; k--; c--;

        }
        else if(L[k - 1][c] > L[k][c - 1])
            k--;

        else
            c--;
    }
    printf("\n\n");
    printf("LCS: %s\n", LCS);
    printf("Length: %d\n", L[Str_X][Stre_Y]);
    return 0;
}
