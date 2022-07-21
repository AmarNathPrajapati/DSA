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
}
struct node *insertionatfirst(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = ptr;
    ptr = newnode;
    return ptr;
}
struct node *insertionatend(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newnode->data = data;
    newnode->next = NULL;
    ptr->next = newnode;
    return head;
}
struct node *insertionatuserspe(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    while (ptr->data != 3)
    {
        ptr = ptr->next;
    }
    newnode->data = data;
    newnode->next = ptr->next;
    ptr->next = newnode;
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
}
struct node *deletionatfront(struct node *head)
{
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}
struct node *deletionatend(struct node *head)
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
struct node *deletionatuserspe(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != 3)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
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
void traversenodeusingrecusion(struct node *head)
{
    if (head)
    {
        printf("%d ", head->data);
        traversenodeusingrecusion(head->next);
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
struct node* reverse_list_recursion(struct node *prenode, struct node *curr)
{
    if (curr->next)
    {
        reverse_list_recursion(curr, curr->next);
        curr->next = prenode;
    }
    else{
        prenode=head;
    }
   return prenode;

}
struct node* reverse_list_iteration(struct node*curr)
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
void traversenode(struct node *p)
{
    printf("Data in Linked list is:\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
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
    // head=insertionatuserspe(head,10);
    // printf("\nData in linked list after insertion afrer 3 :\n");
    // traversenode(head);
    // head=insertionatgivenindex(head,10,5);
    // printf("\nData in linked list after insertion at given  index:\n");
    // traversenode(head);
    // head=deletionatfront(head);
    // printf("\nData in linked list after deletion at first:\n");
    // traversenode(head);
    // head=deletionatend(head);
    // printf("\nData in linked list after deletion at end:\n");
    // traversenode(head);
    // head=deletionatuserspe(head);
    // printf("\nData in linked list after deletion afrer 3 :\n");
    // traversenode(head);
    // head=deletionatgivenindex(head,2);
    // printf("\nData in linked list after deletion at given  index:\n");
    // traversenode(head);
    // printf("\nTraversing using recursion:\n");
    // traversenodeusingrecusion(head);
    // printf("\nReverse Traversing using recursion:\n");
    // reverse_traverse_node_using_recusion(head);
    // printf("\nreversing of linked list using recursion:\n");
    // head=reverse_list_recursion(NULL, head);
    // printf("\nreversing of linked list using iterative version:");
    // head=reverse_list_iteration(head);
    // printf("\nTraversing using recursion:\n");
    // traversenodeusingrecusion(head);

}