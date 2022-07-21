#include<stdio.h>
int power(int a ,int n){
    if(n==0){
        return 1;
    }
    int ans=power(a,n/2);
    if(n%2==0){
        return ans*ans;
    }
    return ans*ans*a;
}
int main()
{
    int a, n, answer;
    printf("Enter the value of base_a:\n");
    scanf("%d", &a);
    printf("Enter the value of exponent_n:\n");
    scanf("%d", &n);
    answer = power(a, n);
    printf("The value of %d^%d is : %d",a,n,answer);
}