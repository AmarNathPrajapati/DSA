#include<stdio.h>
void insertionSort(int *a, int n)
{
    printf("Insertion sort is running...\n");
    int i,key;
    for(int j=1;j<n; j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    } 
}
void printarray(int *a,int n){
   for (int i = 0; i < n; i++)
   {
       printf("%d ",a[i]);
   }
   printf("\n");
   
}
int main()
{
    int a[]={5,23,2,20,1,4,6,7,3,7,5,3,8,10,99};
    int n=15;
    printarray(a,n);
    insertionSort(a,n);
    printarray(a,n);
}