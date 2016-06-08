/*
 * Author: <Your Name>
 * Stack data structure (Implementation)
 */
#include<stdio.h>
#include"Stack.h"
#include<stdlib.h>
// Create a new empty stack
Stack* stack_new()
{
   Stack* node=(Stack*)malloc(sizeof(Stack));
   node=NULL;
   return node;
}
Stack* stack_delete( Stack* st )
{
   while(st!=NULL)
   st=stack_pop(st);
   return st;
}
// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val )
{
      Stack*p=st;
    Stack*q=(Stack*)malloc(sizeof(Stack));
      q->data=val;
      q->link=NULL;
      if(p==NULL)
         st=q;
    else{
         q->link=st;
         st=q;
      }
      return st;
}

// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st )
{
    Stack*p=st;
    Stack*q=(Stack*)malloc(sizeof(Stack));
    q=p;
    st=q->link;
    free(q);
    return st;
}

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st)
{
   
   if(st==NULL)
         return -1;
      
       else
         return st->data;
}

// Returns the number of elements in the stack
int stack_size( Stack* st )
{
   Stack*p=st;
    int count=0;
    while(p!=NULL)
    {
       p=p->link;
       count++;
    }
    return count;
}


// Prints the elements currently in the stack
void stack_print( Stack* st )
{
     Stack*p=st;
   while(p!=NULL){
   printf("%d  ",p->data);
   p=p->link;
   }
}



