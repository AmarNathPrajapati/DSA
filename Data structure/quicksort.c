#include <stdio.h>
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    while(i<j);
    
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
}
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int partitionIndex; // Index of pivot after partion
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);  //sort left subarray
        quickSort(a, partitionIndex + 1, high); //sort right subarray}
    }
}
void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {8, 0, 7, 1, 3,12,32,45,65,78,90,78,99,901,999};
    int n = 15;
    printarray(a, n);
    quickSort(a, 0, n - 1);
    printf("Sorted array using Quicksort algorithm.....\n");
    printarray(a, n);
    return 0;
}