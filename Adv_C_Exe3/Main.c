#include <stdio.h>
#include "Stack.h"
#include "Queue.h"


void main()
{
	printf("\n############################### Testing part 1 - stack ###############################\n");

	// Testing stack funtions
	printf("\n==============Testing stack functions==============\n");
	printf("\n----1st test(initStack and push and howManyInStack)----\n");
	Stack Test;
	initStack(&Test); //test initStack
	push(&Test, 'A'); //test push + addToHead
	push(&Test, 'B');
	push(&Test, 'C');
	push(&Test, 'D');
	push(&Test, 'C');
	push(&Test, 'B');
	push(&Test, 'A');
	printList(Test.head); //test printList
	printf("There are %d items in stack\n", howManyInStack(&Test)); //test howManyInStack
	/*
	printf("\n----next test(pop)----\n");
	char tav = pop(&Test); //test pop + removeItem
	printList(Test.head);
	printf("\nThe tav that was poped is: %c\n", tav);
	printf("\n----next test(isEmptyStack and destroyStack)----\n");
	printf("Before destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
	destroyStack(&Test); //test destroy
	printf("After destroy: %d\n", isEmptyStack(&Test)); //test isEmptyStack
	*/
	printf("\n===================================================\n");

	// Testing flipBetweenHashes
	printf("\n==============Testing flipBetweenHashes==============\n");
	printf("\n1st test: ");
	const char* sentence1 = "Remem#reb# thi#carp s#tice";
	flipBetweenHashes(sentence1);
	printf("\nnext test: ");
	const char* sentence2 = "#meR#embe#siht r# practice";
	flipBetweenHashes(sentence2);
	printf("\nnext test(In case string is empty): ");
	flipBetweenHashes(NULL);
	printf("\n===================================================\n");

	// Testing isPalindrome
	printf("\n==============Testing isPalindrome==============\n");
	printf("\n----1st test(In case stack does not exist)----\n");
	printf("%d\n", isPalindrome(NULL)); //In case stack does not exist
	printf("\n----next test(Check if palindrom)----\n");
	printf("%d\n", isPalindrome(&Test));
	printf("\n===================================================\n");

	// Testing rotateStack
	printf("\n==============Testing rotateStack==============\n");
	printf("\n----1st test(In case stack does not exist)----\n");
	rotateStack(NULL, 2); // n=2 (for test)
	printList(Test.head);
	printf("\n----next test(In case n is negative)----\n");
	rotateStack(&Test, -3); // n=-3 (for test)
	printList(Test.head);
	printf("\n----next test(In case n is bigger than stack size)----\n");
	rotateStack(&Test, 8); // n=8 (for test)
	printList(Test.head);
	printf("\n----next test(Check if rotateStack worked)----\n");
	rotateStack(&Test, 2); // n=2 (for test)
	printList(Test.head);
	printf("\n===================================================\n");


	printf("\n############################### Testing part 2 - Queue ###############################\n");
}