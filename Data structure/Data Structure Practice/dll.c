#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *pre;
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
    head->pre = NULL;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data in node %d:", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        newnode->pre = temp;
        temp->next = newnode;
        temp = temp->next;
    }
}
struct node *insertion_at_first(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = ptr;
    newnode->pre = NULL;
    ptr->pre = newnode;
    ptr=newnode;
    return ptr;
}
struct node *insertion_at_end(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = ptr;
    ptr->next = newnode;
    return head;
}
struct node *insertion_at_given_index(struct node *head, int data, int index)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    for (int i = 1; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    newnode->data = data;
    newnode->next = ptr->next;
    newnode->pre = ptr;
    ptr->next->pre=newnode;
    ptr->next = newnode;
    return head;
}
struct node *deletion_at_front(struct node *head)
{
    struct node *ptr = head;
    head = ptr->next;
    head->pre=NULL;
    free(ptr);
    return head;
}
struct node *deletion_at_end(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
struct node *deletion_at_given_index(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        q = q->next;
    }

    p->next = q->next;
    q->next->pre=p;
    free(q);
    return head;
}
void traverse_node_using_recusion(struct node *head)
{
    if (head)
    {
        printf("%d ", head->data);
        traverse_node_using_recusion(head->next);
    }
}
void reverse_traverse_node_using_recusion(struct node *head)
{
    if (head)
    {
        reverse_traverse_node_using_recusion(head->next);
        printf("%d ", head->data);
    }
}
void traversenode(struct node *p)
{
    printf("Data in Doubly Linked list is:\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void reverse_traverse(struct node *p)
{
    printf("\nData in Doubly Linked list in reverse order:\n");
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->pre;
    }
}
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    creatnode(n);
    traversenode(head);
    reverse_traverse(head);
    head = insertion_at_first(head, 1);
    printf("\nData in linked list after insertion at first:\n");
    traversenode(head);
    reverse_traverse(head);
    head = insertion_at_end(head, 6);
    printf("\nData in linked list after insertion at end:\n");
    traversenode(head);
    reverse_traverse(head);
    // head=insertion_at_given_index(head,10,3);
    // printf("\nData in linked list after insertion at given  index:\n");
    // traversenode(head);
    // reverse_traverse(head);
    // head=deletion_at_front(head);
    // printf("\nData in linked list after deletion at first:\n");
    // traversenode(head);
    // reverse_traverse(head);
    // head=deletion_at_end(head);
    // printf("\nData in linked list after deletion at end:\n");
    // traversenode(head);
    // reverse_traverse(head);
    // head=deletion_at_given_index(head,2);
    // printf("\nData in linked list after deletion at given  index:\n");
    // traversenode(head);
    // reverse_traverse(head);
    printf("\nTraversing using recursion:\n");
    traverse_node_using_recusion(head);
    printf("\nReverse Traversing using recursion:\n");
    reverse_traverse_node_using_recusion(head);

}