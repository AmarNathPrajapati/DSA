#include <stdio.h>
int Linear_Search(int arr[],int size,int n){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int element;
    int arr[] = {1, 2, 3, 4, 5, 9, 7, 6, 8};
    printf("Enter the number which you want to search in given array\n");
    scanf("%d", &element);
    int size= sizeof(arr)/sizeof(int);
    int index=Linear_Search(arr,size,element);
    if(index==-1){
        printf("%d is not found in Array\n",element);
    }
    else{
    printf("The %d is found at index %d of Array\n",element,index);
    }

    
}
