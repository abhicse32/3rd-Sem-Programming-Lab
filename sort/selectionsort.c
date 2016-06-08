/*
 * Name (Rollno)
 * Selection Sort
 */
#include"selectionsort.h"
void selectionsort( int n, int* arr )
{
int i=0,temp=0,max_index=0;
  for(i=max_index;i<n;i++)
  {
     if(arr[i]>arr[max_index])
      max_index=i;
  }
 temp= arr[n-1];
 arr[n-1]=arr[max_index];
 arr[max_index]=temp;
 if(n>1)
  selectionsort(--n,arr);
}
