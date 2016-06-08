/*
 * Name (Rollno)
 * Mergesort
 */
#include<stdlib.h>
#include "mergesort.h"
void mergesort( int n, int* arr )
{
     if(n==1)
     return ;
     else
     {
         int*arr1=malloc(sizeof(int)*(n/2));    //devide the array in two equal parts 
         int i,j,k;                            // for the ease of recursion
         for(i=0;i<n/2;i++)
         
         arr1[i]=arr[i];
         
         int*arr2=malloc(sizeof(int)*(n-n/2));
          for(k=0;i<n;i++,k++)
         arr2[k]=arr[i];
         mergesort(n/2,arr1);                 //recursively breaks all the subarrays further 
                                             //untill their length reduces to 1(that is they are sorted)
         mergesort(n-n/2,arr2);
         merge(arr1,n/2,arr2,n-n/2,arr,n);
     }
}
//function compares the elements in the sub arrays and 
//place them in the original array
void merge(int*A,int p,int*B,int q,int*arr,int n)
{
   int i=0,j=0,k=0;
   while(i<p && j<q)
   {
       if(A[i]<=B[j]){
       arr[k]=A[i];
       i++;
     }
       else
       arr[k]=B[j],j++;
       k++;
    }
    if(i==p){
    while(j<q)
    arr[k]=B[j],k++,j++;
    }else{
     while(i<p)
     arr[k]=A[i],k++,i++;
    }
}
