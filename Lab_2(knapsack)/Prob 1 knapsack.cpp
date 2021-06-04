#include <stdio.h>

struct Item
{
    int weight;
    int value;
    float density;
};

void fk(Item items[], int n, int W)
{
    int i, wf;
    float value;

    float totalWeight = 0, totalBenefit = 0;

    for(i = 0; i < n; i++)
    {
        if(items[i].weight + totalWeight <= W)
        {

            totalWeight += items[i].weight;
            totalBenefit += items[i].value;
        }
        else
        {
            wf = (W - totalWeight);
            value = wf * (float(items[i].value) / items[i].weight);

            totalWeight += wf;
            totalBenefit += value;
            break;
        }
    }

    printf("Total Benefit: %0.1f\n", totalBenefit);
};

int main(void)
{

    int i, j, n = 5, W = 60;

    Item temp, items[5] =
    {
        {5, 30, 0},
        {10, 40, 0},
        {15, 45, 0},
        {22, 77, 0},
        {25, 90, 0},

    };

    for(i=0; i<n; i++)
    {
        items[i].density = float(items[i].value) / items[i].weight;
    }

    //Bubble Sort by density
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < n - i; j++)
        {
            if(items[j+1].density > items[j].density)
            {
                temp = items[j+1];
                items[j+1] = items[j];
                items[j] = temp;
            }
        }
    }

    fk(items, n, W);

    return 0;
}
