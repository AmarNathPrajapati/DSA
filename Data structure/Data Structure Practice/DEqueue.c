#include<stdio.h>
#include<stdlib.h>
 struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueueR(struct queue *q,int data)
{
    if(q->r==q->size-1)
    {
        printf("queue is full!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=data;
        printf("the enqueued data from rear is: %d\n",data);
    }
}
void enqueueF(struct queue *q,int data)
{
    if(q->f==-1)
    {
        printf("queue is full!\n");
    }
    else
    {
        q->arr[q->f]=data;
        q->f--;
        printf("the enqueued data from front is : %d\n",data);
    }
}
int dequeueF(struct queue*q)
{ 
    int a=-1;
    if (q->r==q->f)
    {
        printf("the queue is empty!");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
        return a;
}
int dequeueR(struct queue*q)
{ 
    int a=-1;
    if (q->r==q->f)
    {
        printf("the queue is empty!");
    }
    else
    {
        a=q->arr[q->r];
        q->r--;
    }
        return a;
}
int main()
{
    struct queue *q = (struct queue* )malloc( sizeof(struct queue));
    q->r=q->f=-1;
    q->size=10;
    q->arr= (int*)malloc(q->size*sizeof(int));
    enqueueR(q,1);
    enqueueR(q,2);
    enqueueR(q,3);
    enqueueR(q,4);
    enqueueR(q,5);
    enqueueR(q,6);
    for (int i = 0; i < 3; i++)
    {
        int d = dequeueF(q);
        printf("the dequeued element is : %d\n",d);
    }
    enqueueF(q,10);
    enqueueF(q,20);
    enqueueF(q,30);
    int d = dequeueR(q);
    printf("%d\n",d);
     for (int i = 0; i < 5; i++)
    {
        int d = dequeueF(q);
        printf("the dequeued element from front is : %d\n",d);
    }

    

}