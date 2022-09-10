#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int value)
{
    int low = 0;
    int mid;
    int high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout<<"Element Not Found"<<endl;
    return -1;
}
int main()
{
    int arr[] = {1, 2, 34, 56, 78, 89, 99};
    int size = sizeof(arr) / sizeof(int);
    int value = 5;
    int index = binarySearch(arr, size, value);
    cout<<"found at "<<index;
}