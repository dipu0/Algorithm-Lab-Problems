#include<stdio.h>
int Max_Item(int x, int y);
void knap_Sack(int W, int n, int value[], int weight[])
{

    int i,w;
    int matrix[n+1][W+1];
    for(i=0; i<=n; i++)
    {
         printf("\n");
        for(w=0; w<=W; w++)
        {
            if(i==0 || w==0){
                    matrix[i][w]=0;
                 printf("%d\t",matrix[i][w]);
            }

            else if(weight[i] <= w)
            {
                matrix[i][w] = Max_Item(matrix[i-1][w], value[i]
                                        + matrix[i-1][w - weight[i]]);
               printf("%d\t",matrix[i][w]);
            }
            else
            {
                matrix[i][w] = matrix[i-1][w];
                printf("%d\t",matrix[i][w]);
            }
        }
    }
    printf("\n\n Profit is : %d\n", matrix[n][W]);


}

int main()
{
    int i, Total_Weight=11, Total_item = 4;

   // int value[] = {0,10,4,6,2};
   // int weight[] = {0,7,5,2,1};

    // jenny video
   // int value[] ={0,2,3,4,1}; int weight[] = {0,3,4,5,6};

    int value[] ={0,2,4,6,10};
    int weight[] = {0,1,5,2,7};


   /* printf("Enter Total Item: ");
    scanf("%d",&Total_item);
    printf("Enter Total Weight: ");
    scanf("%d",&Total_Weight);
    int value[Total_item], weight[Total_item];
    value[0]=0;weight[0]=0;
    for(i=1;i<=Total_item;i++){
        printf("Enter Item %d :Weight & Value: ",i);
        scanf("%d%d",&weight[i],&value[i]);
    }
*/

    knap_Sack(Total_Weight, Total_item, value, weight);

    return 0;
}

int Max_Item(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

