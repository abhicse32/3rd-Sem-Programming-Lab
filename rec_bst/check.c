#include<>stdio.h>
#include<stdlib.h>
int main()
{  // Read a number N.
    int N,i,j;
    scanf("%d",&N);
    // Read the maze of NxN characters.
    char**maze=malloc((N+2)*(N+2)*sizeof(char));
    
    for(j=1;j<=N;j++)
    {
        maze[j]=(char*)malloc((N+2)*sizeof(char));
        for(i=1;i<=N;i++)
       scanf("%c",&maze[j][i]);
    }
    for(j=1;j<=N;j++)
    {
        maze[j]=(char*)malloc((N+2)*sizeof(char));
        for(i=1;i<=N;i++)
        printf("%c ",maze[j][i]);
        printf("\n");
    }
    return 0;
    }
   
    //search for the enemy and your position 
