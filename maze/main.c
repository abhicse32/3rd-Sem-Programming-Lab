/*
 * Name (Rollno)
 * Maze Solver main
 */

#include <stdio.h>
#include <stdlib.h>
#include "MazeSolver.h"
int main()
{
    // Read a number N.
    int N,i,j;
    scanf("%d\n",&N);
    // Read the maze of NxN characters.
    char**maze=malloc(N*(N+1)*sizeof(char));
    
    for(j=0;j<N;j++)
    {
        maze[j]=(char*)malloc((N+1)*sizeof(char));
        for(i=0;i<N;i++)
        scanf("%c ",&maze[j][i]);
    }
    int start1_x=0,start1_y=0,flag=0;
    int  start2_x=0,start2_y=0;
    //search for the enemy and your position 
    for(i=0;i<N;i++)
    {
          for(j=0;j<N;j++)
          {
             if(maze[i][j]=='U')
             {
                 start1_x=j;
                 start1_y=i;
                 flag++;
             }
             else if(maze[i][j]=='E')
             {
                start2_x=j;
                start2_y=i;
                flag++;
             }
           }
          if(flag==2)
           break;
     }
   int d1=0,d2=0;
   int*p=(int*)malloc((N/2)*N*sizeof(int));
   Queue*t=queue_new();
 int level=0,z=0;
   p[0]=(start1_x*start1_x)+start1_y;
   t=queue_push(t,p[z]);
  d1=shortestDistance(maze,N,start1_x,start1_y,'R',p,t,d1,level,z);
  //t=queue_delete(t);
 // free(p);
  
  level=0,z=0;
  int*q=(int*)malloc((N/2)*N*sizeof(int));
  Queue*f=queue_new();
   q[0]=(start2_x*start2_x)+start2_y;
  f=queue_push(f,q[z]);
   
  d2=shortestDistance(maze,N,start2_x,start2_y,'R',q,f,d2,level,z);
  // f=queue_delete(f);
  //free(q);
    printf("%d\n",d1);
   printf("%d\n",d2);
    return 0;
}

