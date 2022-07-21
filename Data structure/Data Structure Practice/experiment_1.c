#include <stdio.h>
#include <stdlib.h>
struct node{
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
}
struct node* reverse_list_using_iteration(struct node*curr)
{
    struct node*prenode=NULL;
    struct node*nextnode=NULL;
    while(curr)
    {
        nextnode= curr->next;
        curr->next=prenode;
        prenode=curr;
        curr=nextnode;
    }
    return prenode;
}
void traversenode(struct node *ptr)
{
    printf("\nData is:\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    creatnode(n);
    printf("Data in linked list before reverse the elements in Single Linked List\n");
    traversenode(head);
    head=reverse_list_using_iteration(head);
    printf("\nData in linked list after reverse the elements in Single Linked List using Iterative version:\n");
    traversenode(head);
}