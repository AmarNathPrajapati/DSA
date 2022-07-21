#include <stdio.h>
#include <stdlib.h>
struct circularqueqe
{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueqe(struct circularqueqe *q, int data)
{
    if ((q->r+1)%q->size==q->f)
    {
        printf("The queqe is Full!");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = data;
        printf("Enqueqed Element:%d\n",data);
    }
}
int dequeqe(struct circularqueqe *q)
{
    int a = -1;
    if (q->r == q->f)
    {
        printf("The queqe is Empty!\n");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
        return (a);
}

int main()
{
    struct circularqueqe q;
    q.size = 10;
    q.r = q.f = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueqe(&q, 12);
    enqueqe(&q, 15);
    enqueqe(&q, 18);
    enqueqe(&q, 20);
    enqueqe(&q, 19);
    enqueqe(&q, 34);
    enqueqe(&q, 14);
    enqueqe(&q, 90);
    for (int i = 0; i < 5; i++)
    {
        int d = dequeqe(&q);
        printf("The dequeqing element is :%d\n", d);
    }
    printf("Again Enqueued element is:\n");
    enqueqe(&q, 23);
    enqueqe(&q, 56);
    enqueqe(&q, 78);
    enqueqe(&q, 55);
    enqueqe(&q, 80);
     for (int i = 0; i < 9; i++)
    {
        int d = dequeqe(&q);
        printf("The dequeqing element is :%d\n", d);
    }

}