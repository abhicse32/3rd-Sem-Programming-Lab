/*
 * Name (Rollno)
 * Quicksort
 */

#include "quicksort.h"
void quicksort(int first,int last,int*arr)
{
 if (first==last)      //if array has only one element it's sorted(basis step for recursion)
 return ;
    int fix_point;     //it's an arbitrary position in the array or part of the array to be sorted
    if(first<last)
    {
    fix_point=find_fix_point(arr,first,last);    //recursion condition
     quicksort(first,fix_point-1,arr);         //it will sort the array left of the fixed_point
     quicksort(fix_point+1,last,arr);          // it will sort right array
    }
}
//function finds the fixed point such that all the elements lest to it are 
//either less than or equal to it and rest all in the right are bigger  
int find_fix_point(int *arr, int first, int last)
{
  int i,j,k,fix_point,temp;
       fix_point=first;
       i=first;
       j=last;
       while(i<j){
       while(arr[i]<=arr[fix_point] && i<last)
       i++;
           while(arr[j]>arr[fix_point])
             j--;
        if(i<j)
        {
           temp=arr[j];
           arr[j]=arr[i];
           arr[i]=temp;
        }
     }
     //swap the elements to get the new position of the fix_point
     temp=arr[fix_point];
     arr[fix_point]=arr[j];
     arr[j]=temp;
     return j;
}
