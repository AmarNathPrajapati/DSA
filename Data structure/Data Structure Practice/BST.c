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
int isBST(struct node *root)
{
    static struct node *prev;
    prev = NULL;
    if (root == NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key == root->data)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node *searchitr(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d,already in BST");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = creatnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node *inorderprecedessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *delete (struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    //searching
    if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    else
    {
        iPre = inorderprecedessor(root);
        root->data = iPre->data;
        root->left = delete (root->left, iPre->data);
    }
    return root;
}
int main()
{
    struct node *p = creatnode(10);
    struct node *p1 = creatnode(9);
    struct node *p2 = creatnode(6);
    struct node *p3 = creatnode(7);
    struct node *p4 = creatnode(11);
    p->left = p1;
    p1->left = p2;
    p2->right = p3;
    p->right = p4;
    // printf("\n");
    // printf("%d",isBST(p));
    // struct node* n1=search(p,12);
    // if(n1!=NULL){
    // printf("%d",n1->data);
    // }
    // else
    // printf("Element not found!");
    // struct node* n1=searchitr(p,11);
    // if(n1!=NULL){
    // printf("found:%d",n1->data);
    // }
    // else
    // printf("Element not found!");
    // insert(p,11);
    // printf("%d",p->right->right->data);
    inorder(p);
    printf("\n");
    delete (p, 9);
    inorder(p);
}