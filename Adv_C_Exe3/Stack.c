#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

charNode* addToHead(charNode* head, charNode* toAdd);
void removeItem(charNode** head);
void printList(charNode* head);


/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* temp;
	while (s->head != NULL)
	{
		temp = s->head;
		s->head = s->head->next;
		free(temp);
	}
}

void push(Stack* s, char data)
{
	charNode* newitem = (charNode*)malloc(sizeof(charNode));
	if (!newitem)
	{
		printf("push: Memory allocation failed\n");
		return;
	}
	newitem->data = data;
	s->head = addToHead(s->head, newitem); // Recall private function 
}

char pop(Stack* s)
{
	char res;
	res = s->head->data;
	removeItem(&(s->head)); //pop current head from the stack
	return(res);
}

int isEmptyStack(const Stack* s)
{
	if (!s->head)
	{
		return 1;
	}
	return 0;
}


/*************** Functions using stacks - Implementation/definition ***************/

void flipBetweenHashes(const char* sentence)
{
	// add your code here
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}


/***************** Private functions for Linked List *****************/

// Adds new List Item to head of list
charNode* addToHead(charNode* head, charNode* toAdd)
{
	toAdd->next = head;
	head = toAdd;
	return head;
}

// Deletes the first List Item from list
void removeItem(charNode** head)
{
	if (*head == NULL) return; //if stack empty
	charNode* temp = *head;
	*head = (*head)->next;
	free(temp);
}

// Prints Linked List
void printList(charNode* head)
{
	charNode* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%c\n", temp->data);
		temp = temp->next;
	}
}

