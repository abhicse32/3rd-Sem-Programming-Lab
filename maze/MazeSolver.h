/*
 * Name: Abhishek Yadav
 * MazeSolver
 */

#ifndef MAZESOLVER_H
#define MAZESOLVER_H


typedef struct Queue_ {
      int data;
      struct Queue_ *link;

} Queue;

// Create a new empty queue
Queue* queue_new();
// Deletes the queue, frees memory.
Queue* queue_delete( Queue* q );

// Inserts @val to the back of the queue
Queue* queue_push( Queue* st, int val );

// Remove the element at the front of the queue - also frees memory
Queue* queue_pop( Queue* st );

// Returns the element currently at the top of the queue. If the queue is empty,
// @error should be set to 1, else 0.
int queue_top( Queue* st);

// Returns the number of elements in the queue
int queue_size( Queue* st );

// Prints the elements currently in the queue
void queue_print( Queue* st );


int shortestDistance( char** maze, int N, int start_x,int start_y, char search_symbol,int *arr,Queue*q,int distance,int,int);
// Finds shortest distance to the 
// search symbol in the maze of size NxN
// from start position (x,y) and return
// a direction.


#endif // TOKENISER_H
