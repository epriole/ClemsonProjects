/* Eric Prioleau
   ECE 2230
   HW3 - Queue ADT: test functionality .c file
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main()
{
    queue *q = (queue *)malloc(sizeof(queue)); //
    dequeue(q);                         //check to see if no errors will occur by trying to remove something thats not in the queue
    enqueue(q,(ItemType)77);            //check to see if no errors will occur by trying to place something in an non-created queue
    print_queue(q);                     //ensure that nothing is in the queue
    dequeue(q);
    print_queue(q);                     //ensure nothing is in the queue
    assert(q != NULL); 
    InitializeQueue(q);
    enqueue(q,(ItemType)50);            //place values in the queue
    enqueue(q,(ItemType)40);
    enqueue(q,(ItemType)30);
    enqueue(q,(ItemType)20);
    enqueue(q,(ItemType)10);
    print_queue(q);
    dequeue(q);                         //take things out of the queue
    dequeue(q);
    print_queue(q);                     //ensure that there are 2 less things in the queue
    dequeue(q);
    dequeue(q);
    dequeue(q);
    print_queue(q);                     //ensure that the list is empty, and no errors happen from trying to remove things from an
    return 0;                           //empty queue
}