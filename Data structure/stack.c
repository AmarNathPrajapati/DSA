#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push(struct stack *ptr, int val)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow\n can't push  element %d \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("The pushed element is :%d\n", val);
    }
}
int pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack underflow\n can't pop element\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *s, int i)
{
    if (s->top - i + 1 < 0)
    {
        printf("invalid position\n");
        return -1;
    }
    else
        return (s->arr[s->top - i + 1]);
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 16);
    push(s, 15);
    push(s, 14);
    push(s, 13);
    push(s, 12);
    push(s, 11);
    push(s, 10);
    push(s, 9);
    push(s, 8);
    for (int i = 0; i < 9; i++)
    {
        int val = pop(s);
        printf("the poped value is %d\n", val);
    }
    // // peek(s,2)
    // for (int j = 0; j < s->top+1; j++)
    // {
    //    printf("%d element in stack is %d\n",j+1,peek(s,j+1));
    // }
}