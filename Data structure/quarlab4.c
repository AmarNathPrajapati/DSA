#include <stdio.h>
#include <stdlib.h>
struct queqe
{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueqe(struct queqe *q, int data)
{
    if (q->r == q->size - 1)
    {
        printf("The queqe is Full!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
        printf("The enqueued element is %d:\n",data);
    }
}
int dequeqe(struct queqe *q)
{
    int a = -1;
    if (q->r == q->f)
    {
        printf("\nThe queqe is Empty!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
        return (a);
}

int main()
{
    struct queqe q;
    q.size = 100;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueqe(&q, 12);
    enqueqe(&q, 15);
    enqueqe(&q, 18);
    enqueqe(&q, 20);
    for (int i = 0; i < 5; i++)
    {
        int d = dequeqe(&q);
        printf("The dequeqing element is :%d\n", d);
    }
}