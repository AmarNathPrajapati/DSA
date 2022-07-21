/**represeting that tree in c.
 *      5(n1)
 *     /     \
 *    4(n2)   3(n3)
 *   /    \
 *  2(n4)  1(n5)
 * 
 * Binary Tree Traversal--->
 * it will implement traversal using the concepts of recursion.
 *     1.Preorder traversal
 *              root - left - right
 *     2.PostOrder traversal
 *              left - right - root
 *     3.Inorder traversal
 *              left - root - right
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
//implementing preOrder traversal
void preOrder(struct node*root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//implementing inOrder traversal
void inOrder(struct node*root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
//implementing postOrder traversal
void postOrder(struct node*root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node*n1 = createNode(5);
    struct node*n2 = createNode(4);
    struct node*n3 = createNode(3);
    struct node*n4 = createNode(2);
    struct node*n5 = createNode(1);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    preOrder(n1);
    printf("\n");
    inOrder(n1);
    printf("\n");
    postOrder(n1);
    printf("\n");
    return 0;
}