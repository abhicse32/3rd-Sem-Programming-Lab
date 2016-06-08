/*
 * Name (Rollno)
 * Mergesort Main
 */

#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "selectionsort.h"

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
time_t t;
  srand((unsigned)time(&t));
 struct timeval start1,end1;
 struct timeval start2,end2;
 struct timeval start3,end3;
 struct timeval start4,end4;
 
  int i, n;
  int* arr;
  // Read a count n, and a stream of integers
  scanf( "%d", &n );
  arr = (int*) malloc( sizeof(int) * n );
  for( i = 0; i < n; i++ )
  scanf("%d",&arr[i]);
   // arr[i]=rand()%n;

  #ifdef MERGESORT
  // printf("mergesort\n");
  // gettimeofday(&start1,NULL);
   mergesort( n, arr );
   //gettimeofday(&end1,NULL);
  #endif /*MERGESORT */

  #ifdef QUICKSORT
  // printf("quicksort\n");
  // gettimeofday(&start2,NULL);
  quicksort(0,n-1, arr );
  // gettimeofday(&end2,NULL);
  #endif /*QUICKSORT */

  #ifdef INSERTIONSORT
  // printf("insertionsort\n");
   //gettimeofday(&start3,NULL);
   insertionsort( n-1, arr );
   //gettimeofday(&end3,NULL);
  #endif /*MERGESORT */

  #ifdef SELECTIONSORT
  // printf("selectionsort\n");
  //gettimeofday(&start4,NULL);
  selectionsort( n,arr );
  //gettimeofday(&end4,NULL);
  #endif /*QUICKSORT */
  double t1,t2,t3,t4;
  print_array( n, arr );
 // t1=(end1.tv_sec*1000000+end1.tv_usec)-(start1.tv_sec*1000000+start1.tv_usec);
  //t2=(end2.tv_sec*1000000+end2.tv_usec)-(start2.tv_sec*1000000+start2.tv_usec);
  //t3=(end3.tv_sec*1000000+end3.tv_usec)-(start3.tv_sec*1000000+start3.tv_usec);
  //t4=(end4.tv_sec*1000000+end4.tv_usec)-(start4.tv_sec*1000000+start4.tv_usec);
  //printf("%d %f %f %f %f\n",n,t1/1000,t2/1000,t3/1000,t4/1000);
  return 0;
}

