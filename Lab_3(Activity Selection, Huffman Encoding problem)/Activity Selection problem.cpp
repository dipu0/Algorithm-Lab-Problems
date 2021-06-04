#include <stdio.h>

int main(void)
{

    int s[] =  {1, 3, 0, 5, 5, 8};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = 6;
    int temp_finish;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(f[j] > f[j+1])
            {
                temp_finish = f[j];
                f[j] = f[j+1];
                f[j+1] = temp_finish;
            }
        }
    }

    printf("Finish time Ascending order ");
    for(int i = 0; i < n; i++)
    {
        printf("(%d , %d) ", s[i], f[i]);
    }

    printf("\nActivities are: ");
    printf("(%d , %d) ", s[0], f[0]);

    int c=1,i = 0;
    for(int j = 1; j < n; j++)
    {
        if(s[j] >= f[i])
        {
            printf("(%d , %d) ", s[j], f[j]);
            c++;
            i = j;
        }
    }
    printf("\nNumber of activities can be selected: %d\n",c);
    return 0;
}
