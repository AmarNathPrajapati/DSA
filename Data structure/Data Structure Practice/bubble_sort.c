#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {      
        printf("The total number of pass is:%d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;               
            }
            
        }
    }
}
void bubbleSortAdaptive(int *a, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        printf("The total number of pass is:%d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
            
        }
             if(issorted)
              return;
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
    int arr[] = {1, 3, 2, 4, 5};
    PrintArray(arr, 5);
    bubbleSort(arr, 5);
    PrintArray(arr, 5);
    bubbleSortAdaptive(arr, 5);
    PrintArray(arr, 5);
}