#include<stdio.h>
#include<stdlib.h>
int visited[7]={0,0,0,0,0,0,0};
    int G[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}        
    };    
void DFS(int i)//here i is starting node
{
    printf("%d ",i);
    visited[i]=1;
    for (int j = 0; j < 7; j++)
    {
        if (G[i][j]==1 && !visited[j])
        {
            DFS(j);
        }    
    }  
}
int main(){
    DFS(1);
}
    