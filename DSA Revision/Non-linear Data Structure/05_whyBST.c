/**
 *  Why BST-
 *      i. Searching of a element in BST take O(logn) time.
 *      ii.Inorder traversal of any BST gives an sorted array.
 *      iii.Elements are arranged in proper way.
 *      iv.Insertion and deletion in BST take logn time whereas linked list or other linear data structure take O(n) time.
 */
/*Searching in binary search tree
eg.     5(n1)
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
//1.Recursive algorithm for searching
struct node * searchInBST(struct node*root,int key){
    if(!root){
        return NULL;
    }
    if(key==root->data){
        return root;
    }else if(key<root->data){
        return searchInBST(root->left, key);
    }else{
        return searchInBST(root->right,key);
    }
}
//2.iterative algorithm for searching
struct node* searchIter(struct node* root , int key){
    while (root)
    {
        if(root->data == key){
            return root;
        }else if(key<root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    if(!root){
        return NULL;
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
    struct node* root = searchInBST(n1,6);
    if(root){
        printf("found :%d\n",root->data);
    }else{
        printf("Not found \n");
    }
    struct node* root1 = searchIter(n1,11);
    if(root1){
        printf("found :%d\n",root1->data);
    }else{
        printf("Not found\n ");
    }
    return 0;
}