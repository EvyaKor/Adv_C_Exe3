#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	intNode* temp;
	while (q->head != NULL)
	{
		temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
	q->head = q->tail = NULL;
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* newitem = (intNode*)malloc(sizeof(intNode));
	if (!newitem)
	{
		printf("push: Memory allocation failed\n");
		exit(0);
	}
	newitem->data = data;
	newitem->next = NULL;

	// In case queue is empty
	if (isEmptyQueue(q))
	{
		q->head = q->tail = newitem;
		return;
	}

	// In case queue is not empty
	q->tail->next = newitem;
	q->tail = newitem;
}

unsigned int dequeue(Queue* q)
{
	unsigned res;
	res = q->head->data;
	intNode* temp = q->head;
	q->head = q->head->next;
	if (q->head == NULL) // if queue gets empty both head and tail NULL
	{
		q->tail = NULL;
	}
	free(temp);
	return res;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
	{
		return 1;
	}
	return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// In case queue does not exist
	if (q == NULL)
	{
		printf("Uninitialized queue!\n");
		return;
	}

	// In case queue is empty
	if (isEmptyQueue(q))
	{
		return;
	}

	// In case queue is not empty
	Queue Temp; // Create auxiliary queue
	initQueue(&Temp); // Init queue
	unsigned int num;
	while (q->head != q->tail) //dequeue all items besides the last item(tail) from queue and enqueue to Temp
	{
		num = dequeue(q);
		enqueue(&Temp, num);
	}
	while (Temp.head != NULL) //dequeue all items from Temp and enqueue back to queue
	{
		num = dequeue(&Temp);
		enqueue(q, num);
	}
	destroyQueue(&Temp); // Delete auxiliary queue
}

void cutAndReplace(Queue* q)
{
	// In case queue does not exist
	if (q == NULL)
	{
		printf("Uninitialized queue!\n");
		return;
	}

	int size = howManyInQueue(q);
	int avarage = 0;
	intNode* ptr = q->head; // pointer to read from queue
	if (size % 2 != 0) // in case size is odd
	{
		while (ptr != NULL)
		{
			avarage = avarage + ptr->data;
			ptr = ptr->next;
		}
		avarage = avarage / size; // now avarage is the avarage of the items in the queue
		enqueue(q, avarage);
	}
	// now size of queue is even
	size = howManyInQueue(q); // update size of queue
	Queue Temp; // Create auxiliary queue
	initQueue(&Temp); // Init queue
	unsigned int num;
	for (int i = 0; i < (size / 2); i++) //dequeue half of the queue and enqueue to queue
	{
		num = dequeue(q);
		enqueue(&Temp, num);
	}
	//reversing the tail half of the queue using 3 pointers
	intNode* temp_curr = q->head; 
	intNode* temp_next = NULL; 
	intNode* temp_prev = NULL;
	while (temp_curr != NULL)
	{
		temp_next = temp_curr->next;
		temp_curr->next = temp_prev;
		temp_prev = temp_curr;
		temp_curr = temp_next;
	}
	q->tail = q->head;
	q->head = temp_prev;
	while (Temp.head != NULL) //dequeue all items from Temp and enqueue back to queue
	{
		num = dequeue(&Temp);
		enqueue(q, num);
	}
	destroyQueue(&Temp); // Delete auxiliary queue
}

void sortKidsFirst(Queue* q)
{
	// In case queue does not exist
	if (q == NULL)
	{
		printf("Uninitialized queue!\n");
		return NULL;
	}
	// In case queue is empty
	if (isEmptyQueue(q))
	{
		return NULL;
	}

	unsigned int num = 0;
	Queue Temp; // Create auxiliary queue
	initQueue(&Temp); // Init queue
	intNode* temp_read = q->head; // pointer to read from queue
	while (q->head != NULL) //dequeue all itmes from queue and enqueue to Temp
	{
		num = dequeue(q);
		enqueue(&Temp, num);
	}

	intNode* index; // pointer to hold minimum value index
	while (!isEmptyQueue(&Temp))
	{
		index = minValueIndex(&Temp); // get minimum value index
		moveIndexToHead(&Temp, index); // move it to head of Temp
		num = dequeue(&Temp); // dequeue from Temp and enqueue back to q
		enqueue(q, num);
	}
	destroyQueue(&Temp); // Delete auxiliary queue
}


/***************** Private functions for Linked List *****************/

// Prints Linked List
void printList_Queue(intNode* head)
{
	intNode* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

// Counts how many in queue
int howManyInQueue(Queue* q)
{
	int counter = 0;
	intNode* temp;
	temp = q->head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

// Finds the index of the min value in queue
intNode* minValueIndex(Queue* q)
{
	// In case queue does not exist
	if (q == NULL)
	{
		printf("Uninitialized queue!\n");
		return NULL;
	}
	// In case queue is empty
	if (isEmptyQueue(q))
	{
		return NULL;
	}
	intNode* ptr_read = q->head; // pointer to read from queue
	intNode* ptr_min = q->head; // pointer to hold min value index
	unsigned int min = 4294967295; // maximum unsigned integer possible
	while (ptr_read != NULL)
	{
		if (ptr_min->data > ptr_read->data)
		{
			ptr_min = ptr_read;
		}
		ptr_read = ptr_read->next;
	}
	// now ptr_min points to the smallest number in the queue
	return ptr_min;
}

// Moves given index to head of queue
void moveIndexToHead(Queue* q, intNode* index)
{
	// In case queue does not exist
	if (q == NULL)
	{
		printf("Uninitialized queue!\n");
		return;
	}
	// In case queue is empty
	if (isEmptyQueue(q))
	{
		return;
	}
	intNode* ptr = q->head; // pointer to read from queue
	while ((ptr != NULL) && (ptr != index)) // moves head of queue to tail until reaches index
	{
		int num = dequeue(q);
		enqueue(q, num); 
		ptr = q->head;
	}
}

