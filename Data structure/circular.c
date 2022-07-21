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
        newnode->next=head;
        temp->next=newnode;
        temp=temp->next;
    }
}
 void traversenode()
 {
     struct node*p=head;
     do{
        printf("Element:%d\n",p->data);
        p=p->next;
     }while(p!=head);
 }  
 struct node*insertatfirst(struct node*head,int data)
 {
     struct node*ptr=(struct node*)malloc(sizeof(struct node));
     struct node*p=head;
     do{
         printf("Element:%d\n",p->data);
         p=p->next;
     }while(p->next!=head);
     ptr->data=data;
     ptr->next=p->next;
     p->next=ptr;
     return(ptr);
 }
int main()
{
    int n;
    printf("Enter the number of node:");
    scanf("%d",&n);
    creatnode(n);
    printf("\ndata in list\n");
    traversenode();
    head=insertatfirst(head,56);
    printf("\ndata in list\n");
    traversenode();
    
}