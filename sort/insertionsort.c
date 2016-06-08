/*
 * Name (Rollno)
 * Insertion Sort
 */

#include "insertionsort.h"
#include<stdio.h>
void insertionsort( int n, int* arr )
{
 int i,j,k;
   if(n>1)
   insertionsort(n-1,arr);
  k=arr[n];
  for(i=n-1;i>=0;i--)
  {
     if(k<arr[i])
     arr[i+1]=arr[i];
     else 
     break;
  }
  arr[i+1]=k;
}

