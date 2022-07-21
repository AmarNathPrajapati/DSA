#include <stdio.h>
void insertion_sort(int*arr,int size){
    for (int j = 1; j < size; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i>=0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
    
}
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int main()
{
    int num;
    int arr[] = {52,11111,43, 25, 37, 78, 45, 67, 98, 99};
    int size = sizeof(arr) / sizeof(int);
    print_array(arr, size);
    printf("\nAfter sorting by insertion sort\n");
    insertion_sort(arr,size);
    print_array(arr,size);
    return 0;
}