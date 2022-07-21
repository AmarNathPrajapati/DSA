#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head;
void traversenode(struct node*p)
{
    if(p)
    {
        traversenode(p->next);
        printf("Element:%d\n",p->data);
    }
}
int main()
{
    struct node*head=(struct node*)malloc(sizeof(struct node*));
    struct node*n2=(struct node*)malloc(sizeof(struct node*));
    struct node*n3=(struct node*)malloc(sizeof(struct node*));
    struct node*n4=(struct node*)malloc(sizeof(struct node*));
    head->data=1;
    head->next=n2;
    n2->data=2;
    n2->next=n3;
    n3->data=3;
    n3->next=n4;
    n4->data=4;
    n4->next=NULL;
    traversenode(head);
}