/*
 * Author: <Your Name>
 * Stack data structure (Implementation)
 */
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
// Create a new empty queue
Queue* queue_new()
{
   Queue* node=NULL;
   return node;
}
// Deletes the queue, frees memory.
void queue_delete( Queue* st)
{
     
      stack *p=st;               //local variable to point to the same address as the passed one
      if(p==NULL)
      printf("it's an empty queue\n");
      
      else{
             while(p!=NULL){
                 p=st->link;
                 free(st);
                 st=p;
                 p=p->link;         //It will already check for the next element
             }
             free(p);            // Last node in the queue is freed
             st=NULL:
             printf("queue is empty\n");
      }
      
}

// Inserts @val to the back of the queue
Queue* queue_push( Queue* st, int val )
{
      Queue*p=st;
      Queue*q=(Queue*)malloc(sizeof(Queue));
      q->data=val;
      q->link=NULL;
      if(p==NULL)
      {
         st=q;
      }else{
              while(p->next!=NULL)
                  p=p->link;
       
            p->next=q;
      }
      return st;
}

// Remove the element at the front of the queue - also frees memory
Queue* queue_pop( Queue* st )
{
    Queue*p=st;
    Queue*q=(Queue*)malloc(sizeof(Queue));
    q=p;
    p=q->link;
    free(q);
    st=p;
    return st;
}

// Returns the element currently at the top of the queue. If the queue is empty,
// @error should be set to 1, else 0.
int queue_top( Queue* st, int* error );
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
       p=p->next;
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
   p=p->next;
   }
}


#endif // queue_H

