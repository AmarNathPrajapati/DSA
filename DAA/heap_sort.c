#include<stdio.h>
void swap(int *a,int *b){
    int temp;
     temp=*a;
     *a= *b;
     *b=temp;

}
void printarray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
    
}
void maxheapify(int a[],int n , int i){
    int largest=i;
    int l=(2*i)+1;
    int r=(2*i)+2;
    while (l<n && a[l]>a[largest])
    {
        largest=l;
    }
    while (r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        maxheapify(a,n,largest);
    }
    
}
void heapsort(int a[],int n){
    int i;
    for ( i = (n/2-1); i >=0; i--)//for build heap
    {
        maxheapify(a,n,i);
    }
    for ( i = n-1; i >=0; i--)//for delete element from heap and sorted element
    {
        swap(&a[0],&a[i]);
        maxheapify(a,i,0);
    }
    
    
}
int main(){
    int a[]={23,47,12,14,46,67,78,90,99};
    int n=sizeof(a)/sizeof(int);
    printf("The element in Array:\n");
    printarray(a,n);
    heapsort(a,n);
    printf("The element in sorted Array:\n");
    printarray(a,n);

}