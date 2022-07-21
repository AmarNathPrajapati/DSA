#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*top;
struct node*push(struct node*top,int data)
{
    int a=data;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("The pushed element in linked list is : %d\n",a);
        newnode->data=data;
        newnode->next=top;
        return newnode;
    }
}
struct node* pop(struct node*top)
{
    struct node*q=top;
    if(q==NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        // top=newnode->next;
        // int data=newnode->data;
        // free(newnode);
        // return(data);
        printf("the poped element is : %d\n",q->data);
        top=top->next;
        free(q);
        return top;
    }
}
struct node* linkedlisttraversal(struct node*ptr)
{
    while(ptr!=NULL)
    {
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    top=(struct node*)malloc(sizeof(struct node));
    top=NULL;
    top=push(top,12);
    top=push(top,15);
    top=push(top,18);
    top=push(top,34);
    top=push(top,56);
    top=push(top,67);
    top=push(top,45);
    top=push(top,90);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    // for(int i=0;i<5;i++)
    //  {int d=pop(top);
    // printf("the deleted element is %d\n",d);}
    // printf("Rest element in Stack\n");
    // linkedlisttraversal(top);
}