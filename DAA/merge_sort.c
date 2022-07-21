#include <stdio.h>
void merge(int*a, int low, int mid, int high)
{
    int i, j, k;
    int b[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high){
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <=high; i++){
        a[i] = b[i];
    }
}
void merge_sort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid= (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void printarray(int *a, int n)
{
    printf("The element in array are: ");
    for (int i = 0; i < n; i++){
        printf("%d,", a[i]);
    }
    printf("\n");
}
int main()
{
    int a[] = {2, 4, 66, 9, 65, 89, 54, 12, 34, 67};
    int n = sizeof(a) / sizeof(int);
    printarray(a, n);
    merge_sort(a,0,n-1);
    printf("Running Merge Sort.......\n");
    printarray(a,n);
    return 0;
}