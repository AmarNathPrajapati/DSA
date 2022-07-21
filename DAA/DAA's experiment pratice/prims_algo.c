/******   SET-C  ********/
/* Experiment No. 02*/


// Prim's Algorithm 
#include<stdio.h>
#include<string.h>
#include<stdbool.h> 

#define INF 9999999

// number of vertices in graph
#define V 9
/*******  Adjacency Matrix of given problem ********/
int G[V][V] = {
  {0, 1, 6, 5, 0, 0, 0, 0, 0},
  {1, 0, 6, 0, 0, 0, 0, 0, 0},
  {6, 6, 0, 0, 7, 3, 0, 0, 0},
  {5, 0, 0, 0, 0, 2, 10,0, 0},
  {0, 0, 7, 0, 0, 0, 0, 12,0},
  {0, 0, 3, 2, 0, 0, 0, 8, 0},
  {0, 0, 0, 10, 0, 0, 0, 7,3},
  {0, 0, 0, 0, 12, 8, 7, 0,8},
  {0, 0, 0, 0, 0, 0, 3, 8, 0}};

int main() {
  int no_edge;  // number of edge

  int selected[V];/* create a array to track selected vertex selected will become true otherwise false*/

  memset(selected, false, sizeof(selected));   // set selected false initially
  
  no_edge = 0;    // set number of edge to 0

  /* the number of egde in minimum spanning tree will be
    always less than (V -1), where V is number of vertices in
    graph*/

  selected[0] = true;   // choose 0th vertex and make it true

  int x;  //  row number
  int y;  //  col number

  
  printf("Edge       : Weight\n");  // print for edge and weight

  while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not selected vertex and 
            if (min > G[i][j]) {          //if there is an edge connected to that vertex
              min = G[i][j];
              x = i;
              y = j;                            
            }
          }
        }
      }
    }
    printf("%d ------ %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}