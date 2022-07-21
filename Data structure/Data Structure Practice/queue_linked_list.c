#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
struct node *enqueue(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("queue is full!");
    }
    else
    {
        new->data = data;
        new->next = NULL;
        if (f == NULL)
        {
            f = r = new;
        }
        else
        {
            r->next = new;
            r = new;
        }
    }
    return f;
}
int dequeue()
{
    int a = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty!");
    }
    else
    {
        int a = ptr->data;
        f = f->next;
        free(ptr);
    }
        return a;
}
void traversenode(struct node *p)
{
    printf("Data in Linked list is:\n");
    while (p != NULL)
    {
        printf("Element in Queue:%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    traversenode(f);
    for (int i = 0; i < 5; i++)
    {
            int d=dequeue();
            printf("the dequeued element is:%d\n",d);

    }
        
}
