#include <stdio.h>
int binary_search(int *arr, int low, int high, int num)
{
    if (low == high)
    {
        if (arr[low] == num)
        {
            return low;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        if (arr[mid] > num)
        {
            return binary_search(arr, low, mid - 1, num);
        }
        else
        {
            return binary_search(arr, mid + 1, high, num);
        }
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
    int arr[] = {2, 3, 5, 7, 8, 45, 67, 98, 99};
    int size = sizeof(arr) / sizeof(int);
    print_array(arr, size);
    printf("\nChoose the number from given array for search: ");
    scanf("%d", &num);
    int index = binary_search(arr, 0, size - 1, num);
    if (index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element has found at index:  %d\n", index);
    }
    return 0;
}