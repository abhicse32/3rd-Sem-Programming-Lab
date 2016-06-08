/*
*  Problem Definition :
Given an undirected graph, you are to report the following -

1. Is the graph connected? ( could be done using BFS/DFS concept )
2. Is the graph cyclic? ( implement using DFS )
3. Is the graph a tree? ( Note that this comes directly from the previous question , but it's still a required answer )
4. Given two nodes , find the shortest distance between the two nodes. ( Most efficient algorithm only )
*
*
    Each input file should contain one graph. The format is as follows. First you have an integer 'n'
which represents the number of vertices on which the graph is defined. Given n, the n-element
vertex set is implicitly understood to be {0,1,2..,n-1}. Then you will be given a n x n binary matrix
where each element indicates whether there is an edge from node I to node j.
For example :
4
1 0 0 1
0 1 0 0
0 0 0 0
0 1 1 0


Note : The given matrix may not be symmetric matrix. For this assignment, you must first make this
a symmetric matrix. More precisely, if either a ij = 1 or a ji = 1 then set a ij = a ji =1.
The next line contains an integer 't' denoting the number of queries that the user would make for the
shortest distance part of the assignment. The next t lines contain 2 integers separated by a space
which are the two nodes whose shortest distance has to be computed. In case the two nodes are not
connected , return -1.
Example test file :
4
1 0 0 1
0 1 0 0
0 0 1 0
0 1 0 1
2
1 4
2 3
Output Format :
The output should contain 't+3' lines. The first 3 lines will contain either 'Yes' or 'No' as the output
for the 3 questions mentioned above ( connected , cyclic , tree ). Then each of the next t lines will
contain the distance computed between the two nodes.
Example Output :
No
No
Yes
1
-1
*/


#include<stdio.h>
#include<stdlib.h>
#include"Stack.c"
#include"Queue.c"
int connect_graph(int**,int);
int cyclic(int**,int,int*,int );
int distance(int**,int,int,int);
int check_cyclic(int**,int,int,int);
int main()
{
   int n;
   scanf("%d",&n);
   int**a=(int**)malloc(n*n*sizeof(int));
   int**b=(int**)malloc(n*n*sizeof(int));
   int i,j;
   for(i=0;i<n;i++)
   {
     a[i]=(int*)malloc(n*sizeof(int));
     b[i]=(int*)malloc(n*sizeof(int));
      for(j=0;j<n;j++){
        scanf("%d",&a[i][j]);
        b[i][j]=a[i][j];
        }
 }
   int pair;
   scanf("%d",&pair);
   int*node1=(int*)malloc(pair*sizeof(int));
   int*node2=(int*)malloc(pair*sizeof(int));
    i=0;
    while(i<pair)
    {
       scanf("%d%d",&node1[i],&node2[i]);
       i++;
    }
   int* visit=(int*)malloc(n*sizeof(int));
   int z=0;
   //int connect=connect_graph(a,n);
   int cy_clic=cyclic(a,n,visit,z);
   //if(connect==1)
   //printf("Yes\n");
   //else 
   //printf("No\n");
   if(cy_clic==1)
   printf("Yes\n");
   /*else 
   printf("No\n");
   if(connect==1 && cy_clic==1)
   printf("No\n");
   else if(connect==1 && cy_clic==0)
   printf("Yes\n");
   else 
   printf("No\n");
   i=0;
   while(i<pair)
   {
      j=distance(b,n,node1[i]-1,node2[i]-1);
      printf("%d\n",j);
   }*/
   return 0;
}
int connect_graph(int**p,int n)
{
if(n==1)
 return 1;
    int i,j;
    for(i=0;i<n;i++){
     for(j=i;j<n;j++)
    {
       if(p[i][j]>p[j][i])
       p[j][i]=p[i][j];
       else
       p[i][j]=p[j][i];
    }
  }
    i=0;
  int z=0,counter,flag;
  int top,error=0;
  Queue*st=queue_new();
  st=queue_push(st,i);
  int*visit=(int*)malloc(n*sizeof(int));
  visit[z]=i;
  while(i<n)
  {
       for(j=0;j<n;j++)
       {
          if((p[i][j]>0) && (i!=j))
          flag=0;
          {
             while(flag<=z)
             if(visit[flag]==j)
             break;
             flag++;
          }
          if(flag>z)
          {
             st=queue_push(st,j);
             visit[++z]=j;
          }
          if(j==(n-1))
          st=queue_pop(st);
       }
       if((z+1)==n){
        return 1;
       break;}
       if(st==NULL)
       {
         
         break; 
       }
       i=0;
       top=queue_top(st,&error);
       i+=top;
   }
   return 0; 
}
 int cyclic(int **p,int n,int*visit,int z)
{
if(n<=2 )
   return 0;
int i,j,k;
int counter=0;
  for(i=0;i<n;i++)
  {
     for(j=0;j<n;j++)
     {
        if(p[i][j]>0)
        {
           counter++;
           visit[z]=i;
        }
      }
  }
   Stack*st=stack_new();
   st=stack_push(st,visit[z]);
   int flag,reminder,num=0;
   int x=0,top,error=0;
   i=0;
   while(i<n)
   {
   reminder=0;
      for(j=0;j<n;j++)
      {
         if(p[i][j]>0)
         {
          x=check_cyclic(p,n,i,j);
         flag=0;
          while(flag<=z)
           {
           if(visit[flag]==j){
           break;}
           flag++;
         }
         if(flag>z)
         {
            st=stack_push(st,j);
            visit[++z]=j;
            reminder++;
         }  
       }
       if((reminder==1)|| (x==1))
       break;
      }
      if(reminder!=1)
      st=stack_pop(st);
      i=0;
      top=stack_top(st,&error);
      i+=top;
   }
   if(x==1)
   return x;
   else if(z>=n-3)
   return 0;
   else
   {
      for(i=0;i<=z;i++)
      {
         for(j=0;j<n;j++)
         p[visit[z]][j]=0;
      }
      x=cyclic(p,n,visit,++z);
   }
   return x;
}
 int distance(int**p,int n,int node1,int node2)
{
   if((n==1) || (node1==node2))
 return 0;
    int i,j,k;
    for(i=0;i<n;i++){
        if(p[i][i]!=0)
        p[i][i]=0;               
            for(j=i;j<n;j++)
           {
           if(p[i][j]>p[j][i])
             p[j][i]=p[i][j];
          else
           p[i][j]=p[j][i];
       }
    }
    Queue*q=queue_new();
    q=queue_push(q,node1);
    int*visit1=(int*)malloc(n*sizeof(int));
    int*visit2=(int*)malloc(n*sizeof(int));
    int num=0,z=0,flag;
    int top,count2=0,distance=1;
    int error=0;
    visit1[z]=node1;
    visit2[num]=node1;
    i=node1;
    while(i<n)
    {
         for(j=0;j<n;j++)
         {
            if(p[i][j]>0)
            {
               flag=0;
               while(flag<=z)
               {
                  if(visit1[flag]==j)
                  break;
                  flag++;
               }
            }
            if(flag>z){
            q=queue_push(q,j);
            visit1[++z]=j;
            visit2[++num]=i;
            }
            if(visit1[z]==node2)
            break;
         }
         q=queue_pop(q);
          count2++;
         if(visit1[z]==node2)
         {
            k=0;
             while(k<count2)
             {
                if(visit2[k]!=visit2[k+1])
                distance++;
                k++;
             }
             break;
         }
         else if(q==NULL)
         break;
         i=0;
         top=queue_top(q,&error); 
         i+=top;
    }
    return distance;
}
 int check_cyclic(int**ad_matrix,int n,int node1,int node2)
{
  int k=0,m=0;
  while(k<n)
  {
    if((ad_matrix[node1][k]==1)&&(ad_matrix[node2][k]==1)){
    m++;
    break;
  }
  k++;
}
return m;
}
