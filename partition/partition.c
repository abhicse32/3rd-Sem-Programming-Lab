/*
 * Name (Rollno)
 * Partition
 */

#include <stdio.h>
#include <stdlib.h>
void swap(int *ar,int x,int y)
{
   int temp;
   temp=ar[x];
   ar[x]=ar[y];
   ar[y]=temp;
}
void partition( int n, int* arr )
{
   int i,pos_last_z=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==2){
        swap(arr,i,n-1);
        n--;i--;
        }
        else if(arr[i]==0 && i!=pos_last_z){
        swap(arr,pos_last_z,i);
        pos_last_z++;
        i--;
        }
    }
}

void print_array( int n, int* arr )
{
  int i;
  for( i = 0; i < n; i++ )
  {
    printf( "%d ", arr[i] );
  }
  printf( "\n" );
}

int main()
{
  int i, n;
  int* arr;
  // Read a count n, and a stream of integers
  scanf( "%d", &n );
  arr = (int*) malloc( sizeof(int) * n );
  for( i = 0; i < n; i++ )
    scanf( "%d", &arr[i] );

  partition( n, arr );
  print_array( n, arr );
  
  return 0;
}

