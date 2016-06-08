#include<stdio.h>
#include<stdlib.h>
int main()
{  // Read a number N.
    int N,i,j;
    scanf("%d\n",&N);
    // Read the maze of NxN characters.
    char**maze=(char**)malloc((N+2)*(N+2)*sizeof(char));
    for(i=1;i<=N;i++)
    {
        maze[i]=(char*)malloc((N+2)*sizeof(char));
        for(j=1;j<=N;j++)
       scanf("%c ",&maze[i][j]);
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++){
        printf("%c",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
 }
   
    //search for the enemy and your position 
