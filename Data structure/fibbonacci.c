#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void traversenode(struct node*p)
{
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p =p->next;
    }
    
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));
    n1->data=1;
    n2->data=2;
    n3->data=3;
    n4->data=4;
    head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=NULL;
    traversenode(head);
}