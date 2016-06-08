/*
 * Author: Abhishek Yadav
 * Stack data structure (Implementation)
 */
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
// Create a new empty queue
Queue* queue_new()
{
   Queue* node=(Queue*)malloc(sizeof(Queue));
   node=NULL;
   return node;
}
// Deletes the queue, frees memory.
Queue* queue_delete( Queue* st)
{
     Queue*p=st;               //local variable to point to the same address as the passed one
      while(p!=NULL)
       p=queue_pop(p);
       return p;
}

// Inserts @val to the back of the queue
Queue* queue_push( Queue* st, int val )
{
      Queue*p=st;
      Queue*q=(Queue*)malloc(sizeof(Queue));
      q->data=val;
      q->link=NULL;
      if(p==NULL)
         st=q;
        else{
              while(p->link!=NULL)
                  p=p->link;
       
            p->link=q;
      }
      return st;
}

// Remove the element at the front of the queue - also frees memory
Queue* queue_pop( Queue* st )
{
    Queue*p=st;
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q=p;
    st=q->link;
    free(q);
    return st;
}

// Returns the element currently at the top of the queue. If the queue is empty,
// @error should be set to 1, else 0.
int queue_top( Queue* st, int* error )
{
   int k;
   if(st==NULL){
          k=1;
        error=&k;
        return -1;
        }
       else{
          k=0;
         error=&k;
        return st->data;
        }
}

// Returns the number of elements in the queue
int queue_size( Queue* st )
{
   Queue*p=st;
    int count=0;
    while(p!=NULL)
    {
       p=p->link;
       count++;
    }
    return count;
}


// Prints the elements currently in the queue
void queue_print( Queue* st )
{
     Queue*p=st;
   while(p!=NULL){
   printf("%d  ",p->data);
   p=p->link;
   }
}


