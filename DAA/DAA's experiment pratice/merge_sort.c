#include<stdio.h>
void merge(int a[],int low,int mid ,int high){
    int b[100],i,j,k;
    i=low;j=mid+1;k=low;
    while (i<=mid && j<=high)
    {
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;k++;
        }else{
            b[k]=a[j];
            j++;k++;
        }
    }
    while (i<=mid)//copy all the remaining element from a to b
    {
        b[k]=a[i];
        i++;k++;
    }
    while (j<=high)
    {
        b[k]=a[j];
        j++;k++;
    }
    for ( i = low; i <= high; i++)
    {
        a[i]=b[i];
    }
    
}
void merge_sort(int a[],int low ,int high){
    if(low<high){
        int mid= (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,low);
        merge(a,low,mid,high);
    }
}
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int main(){
    int num;
    int arr[] = {52,11111,43, 25, 37, 78, 45, 67, 98, 99};
    int size = sizeof(arr) / sizeof(int);
    print_array(arr, size);
    printf("\nAfter sorting through merge sort\n");
    merge_sort(arr,0,size-1);
    print_array(arr,size);
    return 0;
}