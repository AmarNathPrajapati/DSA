#include<stdio.h>
int* insertion(int*a)
{
    int i=0;
    for(int j=2;j<5; j++)
    {
        int key=a[j];
        i=j-1;
        while(i>0 && a[i]>key){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
        return a;
    }
}
int main()
{
    int a[]={5,4,3,2,1};
    int b[]=insertion(&a);
    for(int i=0;i<5;i++)
    {
        printf("%d\n",b[i]);
    }
}