/* Eric Prioleau
   ECE 2230
   HW3 - Queue ADT: prototype .h file
*/

// Makes sure that the .h file is recognized
#ifndef queue_h
#define queue_h 1

typedef void* ItemType;

typedef struct node
{
    ItemType    item;
    struct node *next;
} node;

typedef struct
{
    node   *head;
    node   *tail;
} queue;

// Prototypes located in a different .c file
extern void InitializeQueue(queue *Q);
extern void enqueue(queue *Q, ItemType R);
extern void dequeue(queue *Q);
extern void print_queue(queue *Q);

#endif