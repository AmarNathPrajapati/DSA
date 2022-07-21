#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *creatnode(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *p = creatnode(1);
    struct node *p1 = creatnode(2);
    struct node *p2 = creatnode(3);
    struct node *p3 = creatnode(4);
    struct node *p4 = creatnode(5);
    struct node *p5 = creatnode(6);
    struct node *p6 = creatnode(7);

    p->left = p1;
    p1->left = p2;
    p2->right = p3;
    p->right = p4;
    p4->right = p5;
    p5->left = p6;
    inorder(p);
}