/*
  Nam: Abhishek Yadav
  Roll No: CS12B032
*/

#include<stdio.h>
#include<stdlib.h>
void mean_(int *arr, int start ,int end,int z)
{
  if(end-start<=1){
  if(end-start==1)
  arr[end]=arr[start]+z/2;
  return;
  }
  else 
   {
     int pivot=partition(arr,start,end,z);
     mean_(arr,start,pivot,z*2);
     mean_(arr,pivot+1,end,z*2);
      }
      
}
int partition(int *arr, int start, int end,int n)
{
   int k=(end-start)/2;
   int i=start,flag;
    while(i<k+start){
    flag=i;
      arr[++i]=arr[flag]+n;    //in each upcoming position powers of two are added.
    }
    arr[++i]=arr[start]+(n/2);
    return (k+start);
}
int main()
{
    int N;
    scanf("%d",&N);
    int *arr=malloc(N*sizeof(int));
    int i,z=2;
    for(i=0;i<N;i++)
    arr[i]=i+1;
    mean_(arr,0,N-1,z);
    
    printf("Resulting permutation is :\n");
    
    for(i=0;i<N;i++)
    printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
