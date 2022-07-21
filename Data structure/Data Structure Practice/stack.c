#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
void push(struct stack*s,int data)
{
    if(s->top==s->size-1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        s->top++;
        s->arr[s->top]=data;
        printf("The pushed elements is : %d\n",data);
    }
}
int pop(struct stack *s)
{
    if ( s->top==-1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        int a= s->arr[s->top];
        s->top--;
        return a;
    }
}
int main()
{
    struct stack *s= (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=10;
    s->arr=(int*)malloc(s->size* sizeof(int));
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    for (int i = 0; i < 10; i++)
    {
        int a= pop(s);
        printf("the poped element is : %d\n",a);
    }
    

}
