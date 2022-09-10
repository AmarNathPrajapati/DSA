#include<iostream>
using namespace std;
void traversal(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<endl;
    }
}
int indInsertion(int arr[],int size, int index, int value, int capacity){
    if(size>capacity){
        return -1;
    }else{
        for (int i = size; i >=index; i--)
        {
           arr[i] = arr[i-1];
        }
           arr[index-1] = value;
        
    }
}
void deletion(int arr[], int index, int size){
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    
}
int main(){
    int capacity = 100;
    int arr[100] = {1,2,3,4,5};
    int size = 5;
    int index = 2;
    int value = 6;
    // traversal(arr,size);
    // indInsertion(arr,size,index,value,capacity);
    // size+=1;
    deletion(arr,index,size);
    size-=1;
    traversal(arr,size);

return 0;
}