#include <stdio.h>
int power(int a, int n)
{
    if (n > 1)
    {
        a=a*power(a, n - 1);
    }
    else if (n==0)
    {
        a=1;
    }
    return a;
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