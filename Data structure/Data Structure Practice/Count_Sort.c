#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maximum(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
}
void countsort(int *a, int n)
{
    int max = maximum(a, n);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    int i=0;//counter of count array
    int j=0;//counter of main array
    while (i<max+1)
    {
        if(count[i]>0){
            a[j]=i;
            count[i]--;
            j++;
            
        }
        else
        i++;
    }
    
}
void PrintArray(int *a, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {3, 4, 6, 5, 1, 7};
    int n = 6;
    PrintArray(arr, n);
    countsort (arr, n);
    PrintArray(arr, n);
}