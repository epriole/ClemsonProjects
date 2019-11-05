/* Eric Prioleau
   ECE 2230
   HW3 - Queue ADT: function .c file
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*************************************************************************************************************************************/
// Initialize the queue to ensure the values are not random
void InitializeQueue(queue *Q)
{
	Q->head = NULL;
	Q->tail	= NULL;
}
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
// Insert a value at the front of the singly-linked queue
void enqueue(queue *Q, ItemType R)
{
    	node *newEntry = (node *) malloc(sizeof(node));	// Initializing of the new node, queue, and is used within each function that is applicable.

    	newEntry->item = R;
    	newEntry->next = NULL;

    	if(Q->head == NULL)					// If the list is empty, make the new node the first item in the queue.
    	{
        	Q->head = newEntry;					// Since first item in queue, it's technically the beginning and end of the queue.
        	Q->tail = newEntry;					
    	}
    	else
    	{
        	newEntry->next = Q->head;				// If this is not the first item, the new node must be put into the end of the queue
        	Q->head = newEntry;					// which in this case is the head.
    	}

}
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
// Delete the tail of the singly-linked queue which is technically the first element needing to be removed
void dequeue(queue *Q)
{
    	if(Q->head==NULL)				// If list is empty, nothing needs to occur.
		return;

    	node *temp = Q->head;
    	node *current = Q->head;

    	while(current->next != NULL)		//Iterate through the list so that the next point is pointing to null; effectively meaning that the 
    	{					// pointer is currently on the tail of the list. This approach will eventually make current the new target
        	temp = current;			// for deletion while temp can be used to ensure that the value it is pointing to will be the new tail.
        	current = current->next;
    	}

    	temp->next = NULL;
    	Q->tail = temp;
    	free(current);				// No longer need current pointer so we can free the memory in case we need some later.
}
/*************************************************************************************************************************************/

/*************************************************************************************************************************************/
// Print the data of the singly-linked queue
void print_queue(queue *Q)
{
    	if(Q->head == NULL)  
		return;

    	node *current = Q->head;			// Starts the pointer at the head of the list so it can count and print the elements in the queue
							// in an organized manner.

	while(current->next != NULL)
	{
		printf("%li ", (long)current->item); //li and long cast used since they are the same size in the system.
		current = current->next;			//change the item within the "" and change the cast to whatever data type needs to be printed.
	}

    	puts("\n");
}
/*************************************************************************************************************************************/
