#include<stdio.h>
#include<stdlib.h>
 struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueue(struct queue *q,int data)
{
    if(q->r==q->size)
    {
        printf("queue is full!\n");
    }
    else
    {
        q->r=(q->r+1)%(q->size);
        q->arr[q->r]=data;
        printf("the enqueued data is: %d\n",data);
    }
}
int dequeue(struct queue*q)
{ 
    int a=-1;
    if (q->r==q->f)
    {
        printf("the queue is empty!");
    }
    else
    {
        q->f=(q->f+1)%(q->size);
        a=q->arr[q->f];
    }
        return a;
}
int main()
{
    struct queue *q = (struct queue* )malloc( sizeof(struct queue));
    q->r=q->f=0;
    q->size=10;
    q->arr= (int*)malloc(q->size*sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    for (int i = 0; i < 5; i++)
    {
        int d = dequeue(q);
        printf("the dequeued element is : %d\n",d);
    }
    

}