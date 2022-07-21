/******   SET-C  ********/
/* Experiment No. 01*/
#include<stdio.h>
int power(int a, int n){
    if(n==0){
        return 1;
    }
    int ans = power(a,n/2);   // recursive call with half value of exponent
    if(n%2==0){               
        return ans*ans;
    }
    return ans*ans*a;
}
int main(){
    int a, n;
    printf("Enter the integer number: ");
    scanf("%d",&a);
    printf("Enter the exponent : ");
    scanf("%d",&n);
    printf(" %d to the power %d is equal to : %d  ",a,n,power(a,n));
}