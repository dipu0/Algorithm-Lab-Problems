#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 50000
int data[SIZE];

void RandomDataWrite(char *FileName)
{
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++)
    {
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName)
{
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole()
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%10d", data[i]);
    }
}

int TestFunction()
{
    int c = 0;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i > j)
            {
                c++;
            }
        }
    }
    return c;
}


void swap(int *a,int *b)
{

    int t=*a;
    *a=*b;
    *b=t;

}

int BubbleSort()
{
    int i, j,c=0;
    for (i = 0; i < SIZE-1; i++)
        for (j = 0; j < SIZE-i-1; j++)
            if (data[j] > data[j+1])
            {
                swap(&data[i], &data[j+1]);
                c++;
            }

    return c;
}

int RevBubbleSort()
{
    int i, j,c=0;
    for (i = 0; i < SIZE-1; i++)
        for (j = 0; j < SIZE-i-1; j++)
            if (data[j] < data[j+1])
            {
                swap(&data[i], &data[j+1]);
                c++;
            }
    return c;

}

int InsertionSort()
{
    int i,j,c=0;
    for(i=1; i<SIZE; i++)
    {
        int item = data[i];
        j=i-1;
        while(j>=0 && data[j]>item)
        {
            data[j+1] = data[j];
            j = j-1;
            c++;
        }
        data[j+1] = item;
    }
    return c;

}

int RevInsertionSort()
{
    int i,j,c=0;
    for (i = 1; i < SIZE; i++)
    {
        int item = data[i];
        j = i - 1;
        while (item > data[j] && j >= 0)
        {

            data[j + 1] = data[j];
            --j;
            c++;

        }
        data[j + 1] = item;
    }
    return c;
}

int SelectionSort()
{
    int i,j,c=0;
    for(i=0; i<SIZE-1; i++)
    {
        int min_number=i;
        for(j=i+1; j<SIZE; j++)
        {

            if(data[min_number]<data[j])
            {
                min_number=j;
            }
            c++;
        }
        if(min_number!=i)
        {
            int temp=data[i];
            data[i]=data[min_number];
            data[min_number]=temp;
            c++;
        }
    }
    return c;
}
int RevSelectionSort()
{
    int i,j,c=0;
    for(i=0; i<SIZE-1; i++)
    {
        int min_number=i;
        for(j=i+1; j<SIZE; j++)
        {
            if(data[min_number]>data[j])
            {
                min_number=j;
                c++;
            }
        }
        if(min_number!=i)
        {
            int temp=data[i];
            data[i]=data[min_number];
            data[min_number]=temp;
            c++;
        }
    }
    return c;

}

int main()
{
    clock_t start, end;;
    int i, ans;
    double time_taken;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    //WriteToConsole();


    start = clock();
    ans = BubbleSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nBubble Sort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);


    start = clock();
    ans = RevBubbleSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nReverse Bubble Sort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);


    start = clock();
    ans = InsertionSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nInsertion took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

    start = clock();
    ans = RevInsertionSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nReverse Insertion Sort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);


    start = clock();
    ans = SelectionSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nSelection Sort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

     start = clock();
    ans = RevSelectionSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nReverse Selection sort took %f seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);
}
