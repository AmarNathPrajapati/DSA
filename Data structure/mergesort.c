#include <stdio.h>
void merge (int *a , int mid ,int low,int high)
{
   int i, j, k;
   int b[100];
   i= low;
   j= mid+1;
   k= low;
   while (i<=mid && j<=high)
   {
       if (a[i]<a[j]){
           b[k]=a[i];
           i++;
           k++;
       }
       else{
           b[k]=a[j];
           j++;
           k++;
       }
   }
   while (i<=mid)
   {
       b[k]= a[i];
       k++; i++;
   }
   while (j<=high)
   {
       b[k]= a[j];
       k++; j++;
   }
   for (int  i = low; i <= high; i++)
   {
       a[i]=b[i];
   }
   
   
}
void mergesort( int *a, int low, int high)
{
    int mid;
    if(low<high){
        mid = (low + high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
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
    int a[] = {0,4,5,2,3,78,56,78,98,909,1001 ,7, 1, 3.101};
    int n = 15;
    printarray(a, n);
    mergesort(a,0,n-1);
    printf("Sorted Array using Mergesot algorithm.....\n");
    printarray(a, n);
    return 0;
}