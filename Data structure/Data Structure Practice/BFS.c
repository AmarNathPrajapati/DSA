#include<stdio.h>
#include<stdlib.h>
 struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueue(struct queue *q,int data)
{
    if(q->r==q->size-1)
    {
        //printf("queue is full!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=data;
        //printf("\nthe enqueued data is: %d\n",data);
    }
}
int isEmpty(struct queue*q){
    if (q->r==q->f)
    {
        //printf("the queue is empty!\n");
    }
    else{
        return 1;
    }
}
int dequeue(struct queue*q)
{ 
    int a=-1;
    if (q->r==q->f)
    {
        //printf("the queue is empty!");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
        return a;
}
int main()
{
    struct queue *q = (struct queue* )malloc( sizeof(struct queue));
    q->r=q->f=-1;
    q->size=4;
    q->arr= (int*)malloc(q->size*sizeof(int));
    // enqueue(q,1);
    // enqueue(q,2);
    // enqueue(q,3);
    // enqueue(q,4);
    // enqueue(q,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     int d = dequeue(q);
    //     printf("the dequeued element is : %d\n",d);
    // }
    /**************BFS Traversal************/
    int node;
    int i = 0;//starting with '0' node
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}        
    };
    printf("%d",i);
    visited[i]=1;// i is visited
    enqueue(q,i);
    //for exploration
    // while (isEmpty(q))
    // {
        node = dequeue(q);
        printf(" node is %d",node);
         //printf("node is %d",node);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
        
    //}
    
}