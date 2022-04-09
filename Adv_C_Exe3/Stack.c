#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	// In case string is empty
	if (!sentence)
	{
		printf("No sentence detected, String must not be empty!\n");
		return;
	}

	// In case string is not empty
	Stack Temp; // Create auxiliary stack
	initStack(&Temp); // Init stack
	int size = strlen(sentence);
	char* resSentence = (char*)calloc(size, sizeof(char) + 1); // Init string for result
	if (!resSentence)
	{
		printf("Memory allocation failed!\n");
		exit(0);
	}
	char* ptr2sentence = sentence; // Pointer to read from string
	char* ptr2res = resSentence; // Pointer to write to result
	while (*ptr2sentence != '\0') // Read from string
	{
		if (*ptr2sentence == '#') // Reached the char '#'
		{
			ptr2sentence++;
			while (*ptr2sentence != '#') 
			{ // Until reaches next '#', push each char to stack
				push(&Temp, *ptr2sentence);
				ptr2sentence++;
			}
			while (!isEmptyStack(&Temp))
			{ // Until stack is empty, pop each char to result string
				*ptr2res++ = pop(&Temp);
			}
			ptr2sentence++;
		}
		strncpy(ptr2res++, ptr2sentence++, sizeof(char)); // Copy string to result, char by char
	}
	printf("The new string is:\n%s\n", resSentence);
	free(resSentence); // Free result string
	destroyStack(&Temp); // Delete auxiliary stack
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

