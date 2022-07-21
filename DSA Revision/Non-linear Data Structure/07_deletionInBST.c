/**
 *  Deletion in BST
 *      1.there can be three case for the deletion
 *          i.deletion of leaf node
 *          ii. deletion of internal node.
 *          iii. deletion of the root node.
 * process for deletion of leaf node.
 *      Step1. find the node
 *      Step2. delete the node
 * but problem arrises in deletion of internal and root node
 * problem: which node replace the  deleted node
 *  solution: replacement is done with inOrderPre or inOrderPost
 * 
 * inOrderPredecessor:
 *      1. it is the most right node of left node of root node.
 * 
    eg.  5(n1)
 *     /     \
 *    3(n2)   6(n3)
 *   /    \
 *  2(n4)  4(n5)
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*left;
    int data;
    struct node*right;
};
struct node * createNode(int data){
    struct node*newNode = (struct node *) malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}
void inOrder(struct node*root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct node* inOrderPredecessor(struct node*root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root ->right;
    }
    return root;
    
}
// deletion in BST
struct node* deleteNode(struct node*root , int key){
    struct node * ipre;
    if(root==NULL){
        return NULL;
    }
    // if you are at leaf node that delete that node
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //searching for the node to be deleted
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }else{
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left,ipre->data);
    }
    return root;
}
int main(){
    struct node*n1 = createNode(5);
    struct node*n2 = createNode(3);
    struct node*n3 = createNode(6);
    struct node*n4 = createNode(2);
    struct node*n5 = createNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    inOrder(n1);
    deleteNode(n1,3);
    printf("\n");
    inOrder(n1);
    return 0;
}