/* let you have five matrix A1,A2,A3,A4's dimentions are (1*2),(2*3),(3*4),(4*3) respectively, we have to find optimized solution for multiplication.*/
#include <stdio.h>
int main(){
    int n=5;
    int p[]={1,2,3,4,3};
    int m[5][5]={0};
    int s[5][5]={0};
    int j,min,q;    
    for (int d = 1; d < n-1; d++)
    {
        for (int i = 1; i < n-d; i++)
        {
            j=i+d;
            min=1000000;
            for (int k = i; k <= j-1; k++)
            {
                q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<min){
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }  
    }
printf("the min no. of multiplication is %d",m[1][n-1]);
}
