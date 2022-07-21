#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*pre;
    int data;
    struct node*next;

}*head;
 struct node*traversenode(struct node*head)
{
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }

}
struct node*reversenode(struct node*n4)
{
    struct node*ptr=n4;
    while(ptr!=NULL)
    {
        printf("element:%d\n",ptr->data);
        ptr=ptr->pre;
    }
}
int main()
{
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*n2=(struct node*)malloc(sizeof(struct node));
    struct node*n3=(struct node*)malloc(sizeof(struct node));
    struct node*n4=(struct node*)malloc(sizeof(struct node));
    head->pre=NULL;
    head->data=5;
    n2->data=10;
    n3->data=15;
    n4->data=20;
    head->next=n2;
    n2->next=n3;
    n2->pre=head;
    n3->next=n4;
    n3->pre=n2;
    n4->next=NULL;
    n4->pre=n3;
    traversenode(head);
    reversenode(n4);
}