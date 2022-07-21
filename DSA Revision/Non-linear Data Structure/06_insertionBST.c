/**
 * Insertion in BST
 * step1: search if node is already exist then insertion is not possible.
 * Step2: use two pointer one for previous and another for that particular node.
 * previous pointer: will stay that place which will be root of the inserted data.
 * eg.  5(n1)
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
void insert(struct node*root,int key){
    struct node*prev = NULL;
    if(root == NULL){
        return;
    }
    // searching and pointing a pointer to root of inserted data.
    while(root){
        prev = root;
        if(key==root->data){
            return;
        }else if(key<root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    struct node*new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }else{
        prev->right =new;
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
    inOrder(n1);
    insert(n1,7);
    printf("\n");
    inOrder(n1);
    insert(n1,1);
    printf("\n");
    inOrder(n1);
    return 0;
}