#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*left;
   struct node*right;
};
struct node* creatnode(int data)
{
    struct node*n=(struct node*) malloc (sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int NN(struct node* t)
{
    if (t)
    {
        return(1 + NN(t->left)+ NN(t->right));
    }
    else{
        return 0;
    }
}
int main()
{
    struct node*p=creatnode(2);
    struct node*p1=creatnode(3);
    struct node*p2=creatnode(5);
    p->left=p1;
    p->right=p2;
    int nn=NN(p);
    printf("\nThe number of node is %d:",nn);

}
