/*
    1.In linked list implementation , I didn't want to lost head pointer.
*/
#include<stdio.h>
#include<stdlib.h>
/*
    malloc - it return a void pointer.
             it take size, whatever you want
             
    NOTE: Time complexity in worst case:
    traversal - O(n);
    insertion at first in - O(1);
    insertion at end in -O(n);
    deletion at end in -O(n);
    deletion at first in-O(1);
    insertion at particular index -O(n);
    insertion at particular index -O(n);
*/
struct node{
    int data;
    struct node*next;
};
// traversing of linked list
void traversal(struct node*head){
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
//insertion at first position
struct node* insertAtFirst(struct node*head){
    struct node*newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = 12;
    newNode->next = head;
    head = newNode;
    return head;

}
//insertion at end
struct node* insertionAtEnd(struct node*head){
    struct node*ptr = head;
    struct node*newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = 16;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}
// insertion at given index
struct node* insertionAtIndex(struct node*head,int index){
    struct node * newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = 15;
    struct node *p = head;
    for (int i = 1; i < index-1; i++)
    {
        p = p->next;
    }
    newNode->next = p->next;
    p->next=newNode;
    return head;
}
//deletion at first
struct node * deletionAtFirst(struct node*head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;

}
//deletion at end
struct node* deletionAtEnd(struct node * head){
    struct node * p = head;
    struct node * q = head->next;
    while(q->next!=NULL){
        q = q->next;
        p = p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//deletion at given index
struct node * deletionAtIndex(struct node * head, int index){
    struct node*p = head;
    struct node*q = head->next;
    for (int i = 1; i < index-1; i++)
    {
       p = p->next;
       q = q->next;
    }
    p->next = q ->next;
    free(q);
    return head;
}
int main(){

    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*n1 = (struct node*)malloc(sizeof(struct node));
    struct node*n2 = (struct node*)malloc(sizeof(struct node));
    struct node*n3 = (struct node*)malloc(sizeof(struct node));
    struct node*n4 = (struct node*)malloc(sizeof(struct node));
    head = n1;
    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = n4;
    n4->data = 4;
    n4->next = NULL;
    // head = insertAtFirst(head);
    // head = insertionAtEnd(head);
    // head = deletionAtFirst(head);
    // head = deletionAtEnd(head);
    // head = insertionAtIndex(head,3);
    head = deletionAtIndex(head,3);
    traversal(head);
    return 0;
}