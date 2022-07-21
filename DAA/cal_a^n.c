#include<stdio.h>
int main(){
    int a,n;
    int ans=1;
    printf("Enter the value of base_a:\n");
    scanf("%d",&a);
    printf("Enter the value of exponent_n:\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        ans=ans*a;
    }
    printf("The value of %d^%d is : %d",a,n,ans);
}