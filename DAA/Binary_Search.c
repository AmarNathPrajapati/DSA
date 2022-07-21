#include<stdio.h>
int Binary_Search(int arr[],int low,int high ,int mid,int n){
    mid=(low+high)/2;
    if(arr[mid]==n){
        return mid;
    }
    else if(arr[mid]>n){
        high=mid;
        Binary_Search(arr,low,high ,mid, n);
    }
    else if(arr[mid]<n){
        low=mid +1;
        Binary_Search(arr,low,high ,mid, n);
    }
}
int main(){
    int element;
    int arr[] = {1,22,345,677,889,1000};
    printf("Enter the number which you want to search in given array\n");
    scanf("%d", &element);
    int low=0;
    int high= (sizeof(arr)/sizeof(int))-1;
    int mid=(low+high)/2;
    int index=Binary_Search(arr,low,high,mid,element);
    printf("The %d is found at index %d of Array\n",element,index);
}