/**
 * binary Search Tree
 *      1.it is a type of binary tree.
 *      2.left node is always lesser than root node or all the node of left structure are lesser than root node.
 *      3.right node is always greater than root node or all the node of right structure are greater than root node.
 *      4.there are no duplicate node.
 *  note: inOrder traversal of a BST  always gives a sorted array in assending order.
 * Example of BST.
 *      5(n1)
 *     /     \
 *    3(n2)   6(n3)
 *   /    \
 *  2(n4)  4(n5)
 * 
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

// is given BST is BST or not.
int isBST(struct node*root){
    if(root){
        struct node * pre = NULL;
        if(!isBST(root->left)){
            return 0;
        }
        if(pre!=NULL && root->data<=pre->data){
            return 0;
        }
        pre = root;
        return isBST(root->right);
    }else{
        return 1;
    }
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
    if(isBST(n1)){
        printf("The given tree is binary search tree \n");
    }else{
        printf("The given tree is not a binary search tree \n");
    }
    return 0;
}