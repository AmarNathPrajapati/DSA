#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void creatnode(int n)
{
    head=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("enter the data in Node1:");
    scanf("%d",& data);
    head->data=data;


}
int main()
{
    int n;
    printf("enter the number of node:");
    scanf("%d\n", &n);
    creatnode(n);
}
