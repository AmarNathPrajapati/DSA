#include<stdio.h>
void main()
{
    int x=1,i,y=2;
    for (int j= 0; j< 5; j++)
    {
        x<<1;
        y=x+1;
    }
    printf("%d,%d",x,y);
    
}