#include<stdio.h>
void Merge(int arr[],int mid, int S,int End)
{
    int i,j,C,Arr2[20];
    i=S;
    j=mid+1;
    C=S;
    while(i<=mid && j<=End)
    {
        if(arr[i]<arr[j])
        {
            Arr2[C]=arr[i];
            i++;
            C++;
        }
        else
        {
            Arr2[C]=arr[j];
            j++;
            C++;
        }
    }
    while(i<=mid)
    {
        Arr2[C]=arr[i];
        C++;
        i++;
    }

    while(j<=End)
    {
        Arr2[C]=arr[j];
        C++;
        j++;
    }
    for(int x=S; x<=End; x++)
    {
        arr[x]=Arr2[x];
    }
}
void MSort(int arr[],int S,int End)
{
    int mid;
    if(S<End)
    {
        mid=((S+End)/2);
        MSort(arr,S,mid);
        MSort(arr,mid+1,End);
        Merge(arr,mid,S,End);
    }

}
int main()
{
    int arr[50],n;
    printf("Enter the amount of elements N: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("\nEnter Item  %d :",i);
        scanf("%d",&arr[i]);
    }
    MSort(arr,0,n-1);
    printf("The sorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf(" %d ",arr[i]);
    }
    return 0;

}
