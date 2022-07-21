#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void creatnode(int n)
{
    struct node *temp, *newnode;
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data in node 1:");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in node %d:", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;
}
struct node *insertionatfirst(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    newnode->data = data;
    newnode->next = head;
    ptr->next=newnode;
    return newnode;
}
struct node *insertionatend(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    newnode->data = data;
    newnode->next = head;
    ptr->next=newnode;
    return head;
}
struct node *insertionatgivenindex(struct node *head, int data, int index)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    for (int i = 1; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    newnode->data = data;
    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}struct node *deletionatfront(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(p->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=head->next;
    head=head->next;
    free(q);
    return head;
}
struct node *deletionatend(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->next!=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
    return head;
}
struct node *deletionatgivenindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
void traversenode(struct node *p)
{
    printf("Data in Cicular Linked list is:\n");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } 
    while (p != head);
}
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    creatnode(n);
    traversenode(head);
    head = insertionatfirst(head, 1);
    printf("\nData in linked list after insertion at first:\n");
    traversenode(head);
    head = insertionatend(head, 6);
    printf("\nData in linked list after insertion at end:\n");
    traversenode(head);
    // head=insertionatgivenindex(head,10,4);
    // printf("\nData in linked list after insertion at given  index:\n");
    // traversenode(head);
    // head=deletionatfront(head);
    // printf("\nData in linked list after deletion at first:\n");
    // traversenode(head);
    // head=deletionatend(head);
    // printf("\nData in linked list after deletion at end:\n");
    // traversenode(head);
    // head=deletionatgivenindex(head,2);
    // printf("\nData in linked list after deletion at given  index:\n");
    // traversenode(head);
    
}