/*
 * Author:Abhishek Yadav
 * Linked list data structure (Implementation)
 */

#include "LList.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new node with data and next element (can be NULL)
Node* node_new( int data, Node* next )
{
  Node*n = (Node*) malloc( sizeof( Node ) );
  n->data = data;
  n->next = next;
   return n;
}
// Create an empty list (head shall be NULL)
LList* llist_new()
{
  LList* l = (LList*) malloc( sizeof( LList ) );
  l->head = NULL;
  return l;
}
// Traverse the linked list and return its size
int llist_size( LList* lst )
{
  int i=0;
  Node* n=lst->head;
  while(n!=NULL)
  {
     n=n->next;
     i++;
  }
  return i;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
  Node* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%d ", n->data );
  }
  printf( "\n" );
}

int llist_get( LList* lst, int idx )
{
  int i = 0;
  Node* n=lst->head;
  if(idx<=0 || idx>llist_size(lst))
    return -1;
  while(i<idx){
    n=n->next;
    i++;
    }
  return n->data;
}

// Add a new element at the end of the list
LList* llist_append( LList* lst, int data )
{
    Node*p=lst->head;
    Node*q=(Node*)malloc(sizeof(Node));
    q->data=data;
    q->next=NULL;
    if(p==NULL)
    lst->head=q;
    else{
       while(p->next!=NULL)
          p=p->next;
        p->next=q;
      return lst;
    }
}

// Add a new element at the beginning of the list
LList* llist_prepend( LList* lst, int data )
{
  Node* n = node_new( data, lst->head );
  lst->head = n;
  return lst;
}
// Add a new element at the @idx index
LList* llist_insert( LList* lst, int idx, int data )
{
  if( idx == 0 )
  {
    Node* p = node_new( data, NULL );
    p->next = lst->head;
    lst->head = p;
  }
  else
  {
    int i = 1;
    Node* n=lst->head;
    Node* p = node_new( data, NULL );
    while(i<idx)
    {
       n=n->next;
       i++;
    }
    p->next=n->next;
    n->next =p;
  }

  return lst;
}

// Remove an element from the end of the list
LList* llist_remove_last( LList* lst )
{
  Node* n;
  if(lst->head==NULL)
  return lst;
  else if( lst->head->next == NULL )
  {
    free( lst->head );
    lst->head = NULL;
  }
  else
  {
    n=lst->head;
    while(n->next->next!=NULL)
      n=n->next;
    free( n->next );
     n->next = NULL;
  }
  return lst;
}

// Remove an element from the beginning of the list
LList* llist_remove_first( LList* lst )
{
  Node* n = lst->head;
  if(n==NULL)
  return lst;
  lst->head=n->next;
  free(n);
  return lst;
}

// Remove an element from an arbitrary position in the list
LList* llist_remove( LList* lst, int idx )
{
  Node* n=lst->head;
  Node*temp=(Node*)malloc(sizeof(Node));
  if( idx == 0 )
    free( n );
    else if(llist_size(lst)<=idx)
    return lst;
  else
  {
    int i = 1;
    while(i<idx){
      n=n->next;
      i++;}
    temp=n->next;
    n->next=temp->next;
    free(temp);
  }

  return lst;
}

