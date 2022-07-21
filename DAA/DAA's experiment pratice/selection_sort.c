#include<stdio.h>
void  selectionSort(int *a, int n)
{
   int indexofmin,temp;
   printf("Running Selection Sort.....\n");
   for (int i = 0; i < n-1; i++)
   {
       indexofmin=i;
       for (int j = i+1; j < n; j++)
       {
           if (a[j]<a[indexofmin]){
               indexofmin=j;
           }
       }
       temp=a[i];
       a[i]=a[indexofmin];
       a[indexofmin]=temp;
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
    int a[]={8,0,07,1,3,02,3,5,7,77,89,98,12,4,5};
    int n=sizeof(a)/sizeof(int);
    printarray(a,n);
    selectionSort(a,n);
    printarray(a,n);
}