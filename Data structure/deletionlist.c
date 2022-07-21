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
 struct node*deleteatfirst(struct node*head) 
 {  
     struct node*p=head;
     head=head->next;
     free(p);
     return(head);
 }
 struct node*deletionatend(struct node*head) 
 {
     struct node*p=head;
     struct node*q=head->next;
     while(q->next!=NULL)
     {
         p=p->next;
         q=q->next;
     }
     p->next=NULL;
     free(q);
     return(head);
 }
 struct node*deletionatbetween(struct node*head,int index)
 {
     struct node*p=head;
     struct node*q=head->next;
     for(int i=0;i!=index-1;i++)
     {
         p=p->next;
         q=q->next;
     }
     p->next=q->next;
     free(q);
     return(head);
 }
 struct node* delete3(struct node*head,int data)
 {
     struct node*p=head;
     struct node*q=head->next;
     while(q->data!=data)
     {
         p=p->next;
         q=q->next;
     }
     p->next=q->next;
     free(q);
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
    head=deleteatfirst(head);
    printf("\ndata in list after deletion at first \n");
    traversenode();
    head=deletionatend(head);
    printf("\ndata in list after deletion at end \n");
    traversenode();
    int d;
    printf("If you want to delete node in between list\n please write position of that number");
    scanf("%d",&d);
    head=deletionatbetween(head,d-1);
    printf("\ndata in list after deletion in between the list \n");
    traversenode();
    int f,d;
    printf("Enter the frequency of number and number respectvely,which you want to delete");
    scanf("%d%d",&f,&d);
    for(int j=0;j<f;j++)
    {
        head=delete3(head,d);
    }
     printf("list without %d\n",d);
    traversenode();
//     head=deleteatfirst(head);
//     printf("\ndata in list after deletion at first \n");
//     traversenode();
}

