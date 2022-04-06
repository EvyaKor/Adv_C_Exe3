#include <stdio.h>
#include "Stack.h"
#include "Queue.h"


void main()
{
	Stack Test;
	initStack(&Test); //test initStack
	push(&Test, 'A'); //test push + addToHead
	push(&Test, 'B');
	push(&Test, 'C');
	printList(Test.head); //test printList
	printf("\n\n==========================\n\n");
	char tav = pop(&Test); //test pop + removeItem
	printList(Test.head);
	printf("\nthe tav that was poped is: %c\n", tav);
	printf("\n\n==========================\n\n");
	printf("before destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
	printf("\n\n==========================\n\n");
	destroyStack(&Test); //test destroy
	printf("after destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
}