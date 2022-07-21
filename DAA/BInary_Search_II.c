#include <stdio.h>
int Binary_Search(int arr[], int size, int n)
{   
    int mid, low, high;
    low=0;
    high=size-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            return mid;
        }
        if (arr[mid] < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    int element;
    int arr[] = {1, 2, 3, 4, 5, 9};
    printf("Enter the number which you want to search in given array\n");
    scanf("%d", &element);
    int size = sizeof(arr) / sizeof(int);
    int index = Binary_Search(arr, size, element);
    if (index == -1)
    {
        printf("%d is not found in Array\n", element);
    }
    else
    {
        printf("The %d is found at index %d of Array\n", element, index);
    }
}
