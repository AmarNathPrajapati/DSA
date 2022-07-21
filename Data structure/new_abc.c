#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push1(struct stack *ptr, int val)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow\n can't push  element %d \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("The enqueud Element in s1:%d\n",val);
    }
}
void push2(struct stack *ptr, int val)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow\n can't push  element %d \n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop1(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack underflow\n can't pop element");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int pop2(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack underflow\n can't pop element");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void enqueue(struct stack *s1, int x)
{
    push1(s1, x);
    int count = count + 1;
    printf("Count:%d\n",count);
}
void dequeue(struct stack *s1, struct stack *s2,int count)
{
    int a,b,i;
    if (s1->top == -1 && s2->top == -1)
    {
        printf("queue is empty");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a=pop1(s1);
            push2(s2,a);
        }
        b=pop2(s2);
        printf("the dequeued element is %d\n",b);
        count--;
        for(i=0;i<count;i++)
        {
            a=pop2(s2);
            push1(s1,a);
        }
    }
}
// void display(struct stack *s1)
// {
//     int i;
//     for(i=0;i<(s1->top);i++)
//     {
//         printf("%d",s1[i]);
//     }
// }
int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->size = 5;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    struct stack *s2 = (struct stack *)malloc(sizeof(struct stack));
    s2->size = 5;
    s2->top = -1;
    s2->arr = (int *)malloc(s2->size * sizeof(int));
    enqueue(s1,16);
    enqueue(s1,15);
    enqueue(s1,14);
    enqueue(s1,13);
    dequeue(s1,s2,4);
    // dequeue(s1,s2,)
    // int val=pop(s);
    // // printf("%d\n",isempty(s));
    // // printf("%d\n",isfull(s));
    // printf("the poped value is %d\n",val);
    // // // peek(s,2)
    // for (int j = 0; j < s->top+1; j++)
    // {
    //    printf("%d element in stack is %d\n",j+1,peek(s,j+1));
    // }
}