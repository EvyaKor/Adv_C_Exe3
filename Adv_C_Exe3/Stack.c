#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

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
		exit(0);
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
	// In case stack does not exist
	if (s == NULL)
	{
		printf("Uninitialized stack!\n");
		return 0;
	}

	// In case stack is empty
	if (isEmptyStack(s))
	{
		return 1;
	}
	
	// In case stack is not empty
	Stack Temp; // Create auxiliary stack
	initStack(&Temp); // Init stack
	int midsize = howManyInStack(s) / 2; // Get the size of half the stack
	charNode* ptr1 = s->head; // pointer to read from stack
	charNode* ptr2; // pointer to read from auxiliary stack
	while (ptr1 != NULL)
	{
		push(&Temp, ptr1->data); // Copy stack to auxiliary stack in reverse
		ptr1 = ptr1->next;
	}
	ptr1 = s->head;
	ptr2 = Temp.head;
	for (int i = 0; i < midsize; i++) // Loop to check palindrom, works for both odd and even size options
	{
		if (ptr1->data != ptr2->data)
		{
			return 0;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	destroyStack(&Temp); // Delete auxiliary stack
	return 1;
}

void rotateStack(Stack* s, int n)
{
	// In case stack does not exist
	if (s == NULL)
	{
		printf("Uninitialized stack!\n");
		return;
	}

	// In case stack is empty
	if (isEmptyStack(s))
	{
		return;
	}

	// In case n is negative
	if (n < 0)
	{
		return;
	}

	// In case n is bigger than stack size
	int size = howManyInStack(s);
	if (n > size) 
	{
		return;
	}

	// In case stack is not empty and n is valid
	Stack Temp1; // Create auxiliary stack 1
	initStack(&Temp1); // Init stack 1
	Stack Temp2; // Create auxiliary stack 2
	initStack(&Temp2); // Init stack 2
	char tempchar;
	for (int i = 0; i < (size - n); i++) // pop size-n items from stack and push to Temp1
	{
		tempchar = pop(s);
		push(&Temp1, tempchar);
	}
	while (s->head != NULL) // pop the rest of the items from stack and push to Temp2
	{
		tempchar = pop(s);
		push(&Temp2, tempchar);
	}
	// now stack is empty
	while (Temp1.head != NULL) // pop all items from Temp1 and push back to stack
	{
		tempchar = pop(&Temp1);
		push(s, tempchar);
	}
	while (Temp2.head != NULL) // pop all items from Temp1 and push back to stack
	{
		tempchar = pop(&Temp2);
		push(s, tempchar);
	}
	destroyStack(&Temp1); // Delete auxiliary stack 1
	destroyStack(&Temp2); // Delete auxiliary stack 2
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
void printList_Stack(charNode* head)
{
	charNode* temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%c\n", temp->data);
		temp = temp->next;
	}
}

// Counts how many in stack
int howManyInStack(Stack* s)
{
	int counter = 0;
	charNode* temp;
	temp = s->head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

