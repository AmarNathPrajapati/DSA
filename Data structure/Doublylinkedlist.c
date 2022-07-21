#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
} * head;
void creatnode(int n)
{
    struct node *temp, *newnode;
    int data, i;
    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in node 1:");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        head->pre = NULL;
        temp = head;
    }
    else
    {
        printf("the numbere of node is 0");
    }
    for (i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in node %d:", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        newnode->pre = temp;
        temp->next = newnode;
        temp = newnode;
    }
}
struct node *traversenode(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *reversenode(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr!= NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr=ptr->pre;
    }
}
struct node*insertionatfirst(struct node*head,int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*ptr=head;
    newnode->data=data;
    newnode->next=ptr;
    newnode->pre=NULL;
    ptr->pre=newnode;
    ptr=newnode;
    head=ptr;
    return(head);
}
struct node*insertionatend(struct node*head,int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newnode->data=data;
    newnode->next=NULL;
    newnode->pre=ptr;
    ptr->next=newnode;
    return(head);
}
struct node*insertionatmid(struct node*head,int data,int index)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node *ptr = head;
    for(int i=0; i<index-1 ;i++)
    {
        ptr = ptr->next;
    }
    newnode->data=data;
    newnode->next=ptr->next;
    newnode->pre=ptr;
    ptr->next->pre=newnode;
    ptr->next=newnode;
    return(head);
}

int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    creatnode(n);
    printf("\ndata in list:\n");
    traversenode(head);
    printf("\ndata in list in reverse direction:\n");
    reversenode(head);
    head=insertionatfirst(head,12);
    printf("\ndata in list after insertion at first:\n");
    traversenode(head);
    printf("\ndata in list in reverse direction:\n");
    reversenode(head);
    head=insertionatend(head,21);
    printf("\ndata in list after insertion at end:\n");
    traversenode(head);
    printf("\ndata in list in reverse direction:\n");
    reversenode(head);
    head=insertionatmid(head,21,2);
    printf("\ndata in list after insertion at mid:\n");
    traversenode(head);
     printf("\ndata in list in reverse direction:\n");
    reversenode(head);
}
