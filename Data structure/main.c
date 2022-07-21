#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

void creatnode(int n)
{
    struct node*temp,*newnode;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data in node 1:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data in node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}
 void traversenode()
 {
     struct node*temp;
     temp=head;
     while(temp!=NULL)
     {
         printf("Element: %d\n",temp->data);
         temp=temp->next;
     }
 }  


struct node*insertatfirst(struct node*head,int data)
{
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return(ptr);
}
 struct node* insertatend(struct node*head,int data)
 {
     struct node*ptr=(struct node*)malloc(sizeof(struct node));
     struct node*p=head;
     while(p->next!=NULL)
     {
         p=p->next;
     }
     ptr->data=data;
     p->next=ptr;
     ptr->next=NULL;
     return (head);

 }
 struct node*insertatsecond(struct node*head,int data)
 {
     struct node*ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=data;
     ptr->next=head->next->next;
     head->next->next=ptr;
     return(head);
 }
 struct node*insertatbetween(struct node*head,int position ,int data)
 {
     struct node*ptr=(struct node*)malloc(sizeof(struct node));
     struct node*p=head;
     int i=0;
     while(i!=position-1)
     {
         p=p->next;
         i++;
     }
     ptr->data=data;
     ptr->next=p->next;
     p->next=ptr;
     return(head);
 }
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    creatnode(n);
    printf("\ndata in list\n");
    traversenode();
    printf("what do you want insert at first position:\n");
    int ins1;
    scanf("%d",&ins1);
    head=insertatfirst(head,ins1);
    printf("\ndata in list after insert at first\n");
    traversenode();
    int insend;
    printf("\nWhat do you want insert at end of the list:\n");
    scanf("%d",&insend);
    head=insertatend(head,insend);
    printf("\ndata in list after insert at end\n");
    traversenode();
    int ins3;
    printf("What do you want to insert after second position:\n");
    scanf("%d",&ins3);
    head=insertatsecond(head,ins3);
    printf("\ndata in list after insert at after second position\n");
    traversenode();
    int insb;
    int position;
    printf("If you want a node insert at between int the list\n,please write data and position\n");
    scanf("%d%d",&insb,&position);
    head=insertatbetween(head,position-1,insb);
    printf("\ndata in list after insert at between at list\n");
    traversenode();
}