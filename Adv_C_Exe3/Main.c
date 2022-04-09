#include <stdio.h>
#include "Stack.h"
#include "Queue.h"


void main()
{
	// Testing stack funtions
	printf("\n==============Testing stack functions==============\n");
	printf("\n----1st test(initStack and push)---\n");
	Stack Test;
	initStack(&Test); //test initStack
	push(&Test, 'A'); //test push + addToHead
	push(&Test, 'B');
	push(&Test, 'C');
	printList(Test.head); //test printList
	printf("\n----next test(pop from stack)---\n");
	char tav = pop(&Test); //test pop + removeItem
	printList(Test.head);
	printf("\nthe tav that was poped is: %c\n", tav);
	printf("\n----next test(isEmptyStack and destroyStack)---\n");
	printf("before destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
	destroyStack(&Test); //test destroy
	printf("after destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
	printf("\n===================================================\n");

	//Testing flipBetweenHashes
	printf("\n==============Testing flipBetweenHashes==============\n");
	printf("\n1st test: ");
	const char* sentence1 = "Remem#reb# thi#carp s#tice";
	flipBetweenHashes(sentence1);
	printf("\n2nd test: ");
	const char* sentence2 = "#meR#embe#siht r# practice";
	flipBetweenHashes(sentence2);
	printf("\n3rd test: ");
	flipBetweenHashes(NULL);

}