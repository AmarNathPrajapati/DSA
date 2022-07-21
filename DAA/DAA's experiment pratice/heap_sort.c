#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void heapify(int *arr, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1; // here l is index of left node of i
    int r = 2 * i + 2; // here r is index of right node of i
    while (l < size && arr[l] > arr[largest])
    {
        largest = l;
    }
    while (r < size && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}
void heap_sort(int *arr, int size)
{
    //building the heap
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    //delete heap
    for(int i = size - 1 ; i>=0; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
    int num;
    int arr[] = {12, 43, 55, 37, 28, 45, 67, 198, 99};
    int size = sizeof(arr) / sizeof(int);
    print_array(arr, size);
    printf("Sorting through heap sort.....\n");
    heap_sort(arr,size);
    print_array(arr,size);
    return 0;
}