#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(char data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

void tripleordertraversal1(struct  node* root){
    if(root!=NULL){
        printf("%c ", root->data);
        printf("%c ", root->data);
        tripleordertraversal1(root->left);
        printf("%c ", root->data);
        tripleordertraversal1(root->right);
    }
}

void tripleordertraversal2(struct  node* root){
    if(root!=NULL){
        tripleordertraversal2(root->left);
        printf("%c ", root->data);
        tripleordertraversal2(root->right);
        printf("%c ", root->data);
        printf("%c ", root->data);
    }
}

void tripleordertraversal3(struct  node* root){
    if(root!=NULL){
        tripleordertraversal3(root->left);
        printf("%c ", root->data);
        printf("%c ", root->data);
        tripleordertraversal3(root->right);
        printf("%c ", root->data);
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode('a');
    struct node *p1 = createNode('b');
    struct node *p2 = createNode('c');
    struct node *p3 = createNode('d');
    struct node *p4 = createNode('e');
    // Finally The tree looks like this:
    //      a
    //     / \
    //    b   c
    //   / \
    //  d   e  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("The Triple order Traversal1 is:\n");
    tripleordertraversal1(p);
    printf("\nThe Triple order Traversal2  is:\n");
    tripleordertraversal2(p);
    printf("\nThe  Triple order Traversal3 is:\n");
    tripleordertraversal3(p);
    return 0;
}