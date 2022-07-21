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
    if(n>=1)
    {head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data in node 1:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;}
    else{
        printf("the numbere of node is 0");
    }
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data in node %d:",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
    temp->next=head;
}
 int traversenode()
 {
     int count=0;
     struct node*ptr=head;
     do
     {
         count = count+1;
         printf("data:%d\n",ptr->data);
         ptr=ptr->next;
     }
     while(ptr!=head);
     return count;
 }
 struct node* insertionatfirst(struct node*head, int data)
 {
     struct node*newnode=(struct node*)malloc(sizeof(struct node));
     struct node*ptr=head;
     while(ptr->next!=head)
     {
         ptr=ptr->next;
     }
     newnode->data=data;
     newnode->next=ptr->next;
     ptr->next=newnode;
     head=newnode;
     return(head);
 }
 struct node* insertionatend(struct node*head, int data)
 {
     struct node*newnode=(struct node*)malloc(sizeof(struct node));
     struct node*ptr=head;
     while(ptr->next!=head)
     {
         ptr=ptr->next;
     }
     newnode->data=data;
     newnode->next=ptr->next;
     ptr->next=newnode;
     return(head);
 }
 struct node* insertionatmid(struct node*head, int data,int index)
 {
     struct node*newnode=(struct node*)malloc(sizeof(struct node));
     struct node*ptr=head;
     for(int i=0;i<index-1;i++)
     {
         ptr=ptr->next;
     }
     newnode->data=data;
     newnode->next=ptr->next;
     ptr->next=newnode;
     return(head);
 }
 
 int main()
{
    int n,count;
    printf("Enter the number of node:");
    scanf("%d",&n);
    creatnode(n);
    printf("\ndata in list:\n");
    traversenode();
//    count = traversenode();
//    printf("number of nodes:%d",count);
//    printf("Data in list after insertion at first:\n");
//    head=insertionatfirst(head,12);
//    traversenode();
//    printf("Data in list after insertion at end:\n");
//    head=insertionatend(head,21);
//    traversenode();
   int index;
   printf("Enter the index where you want to insert:\n");
   scanf("%d",&index);
   int data;
   printf("Enter the data:\n");
   scanf("%d",&data);
   head=insertionatmid(head,data,index);
   printf("Data in list after insertion at mid:\n");
   traversenode();
}