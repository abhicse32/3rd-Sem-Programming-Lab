/*
 * Name (Rollno)
 * Insertion sort
 */

#include "Stack.h"
#include "qsort.h"
#include <stdlib.h>
#include<stdio.h>

#define INTSWAP(x,y) { int tmp; tmp = x; x = y; y = tmp; }

// A range represents [start, end) (end is not included)
typedef struct Range_ {
  int start;
  int end;
} Range;

int partition( int* arr, int i, int j, int p )
{
  int pivot = arr[p];
  for(;i<j;i++)
  {
      if(arr[i]>arr[p]){
      INTSWAP(arr[j],arr[i]);
      i--;j--;
      }
   }
   if(arr[i]<arr[p]){
      INTSWAP(arr[p],arr[i]);
      p=i;
    }
    else {
     INTSWAP(arr[p],arr[i-1]);
     p=i-1;
    }
  return p;  
}
Range mk_range( int start, int end )
{
  Range r = {start, end};
  return r;
}

// A wrapper over stack functions to push and pop ranges instead of just
// integers.
Stack* stack_push_range( Stack* st, Range r )
{
  stack_push( st, r.start );
  return stack_push( st, r.end );
}

Range stack_top_range( Stack* st )
{
  int start, end;
  end = stack_top( st, NULL ); stack_pop( st );
  start = stack_top( st, NULL ); stack_push( st, end );
  return mk_range( start, end );
}

Stack* stack_pop_range( Stack* st )
{
  stack_pop( st );
  return stack_pop( st );
}

void QSort( int n, int* arr )
{
  Range r;
  int p;
  Stack *st = stack_new();

  st=stack_push_range( st, mk_range( 0, n-1) );
  while( stack_size( st ) > 0 )
  {
     r= stack_top_range( st ); 
     st=stack_pop_range( st );
     
     p=partition(arr,r.start,r.end,r.start);\
     if(p>r.start)
     st=stack_push_range(st,mk_range( r.start,p));
     if(p+1<r.end)
     st=stack_push_range(st,mk_range( p+1,r.end));
    }
}

