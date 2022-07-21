#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
void push1(struct stack*s1,int data)
{
    if(s1->top==s1->size-1)
    {
        printf("Stack Overflow!");
    }
    else
    {
        s1->top++;
        s1->arr[s1->top]=data;
        printf("The enqueued elements is : %d\n",data);
    }
}
int pop1(struct stack *s1)
{
    if ( s1->top==-1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        int a= s1->arr[s1->top];
        s1->top--;
        return a;
    }
}
void push2(struct stack*s2,int data)
{
    if(s2->top==s2->size-1)
    {
        printf("Stack Overflow!");
    }
    else
    {   
        s2->top++;
        s2->arr[s2->top]=data;
        printf("The pushed elements is s2: %d\n",data); 
    }
}
int pop2(struct stack *s2)
{
    if ( s2->top==-1)
    {
        printf("Stack Underflow!");
    }
    else
    {
        int a= s2->arr[s2->top];
        s2->top--;
        return a;
    }
}
int main()
{
    struct stack *s1= (struct stack*)malloc(sizeof(struct stack));
    struct stack *s2= (struct stack*)malloc(sizeof(struct stack));
    s1->top=-1;
    s2->top=-1;
    s1->size=10;
    s2->size=10;
    s1->arr=(int*)malloc(s1->size* sizeof(int));
    s2->arr=(int*)malloc(s2->size* sizeof(int));
    push1(s1,1);
    push1(s1,2);
    push1(s1,3);
    push1(s1,4);
    push1(s1,5);
    //this  code for enqueue in queue
    for (int i = 0; i < 5; i++)
    {
        int a= pop1(s1);
        push2(s2,a);
    }
    // This code for dequeue in queue
    for (int i = 0; i < 5; i++)
    {
        int b= pop2(s2);
        printf("the dequeued element is: %d\n",b);  
    }
    

}
