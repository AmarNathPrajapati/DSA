#include<stdio.h>
int linear_search(int *arr,int num,int size){
    for (int i = 0; i < size; i++)
    {
       if(arr[i]==num){
           return i;
       }
    }
    return -1;
}
void print_array(int *arr,int size){
    for (int i = 0; i <size; i++)
    {
        printf("%d  ",arr[i]);
    }
    
}
int main(){
    int num;
    int arr[]={2,3,5,7,8,45,67,98,99};
    int size = sizeof(arr)/sizeof(int);
    print_array(arr,size);
    printf("\nChoose the number from given array for search: ");
    scanf("%d",&num);
    int index = linear_search(arr,num,size);
    if(index==-1){
        printf("Element not found\n");
    }else{
        printf("Element has found at index:  %d\n",index);
    }
}