/*
	Based on my memory from a C# textbook, and rewritten to make sense as a prompt for C:
	Write a series of functions:
		- write a function that creates a boolean array with 100 elements
		  these elements will represent integers 0 through 99
		  if the value at index i == true, integer i is in the set.
		  initialize each set to false for each index
		- write a function that inserts a value into the array
		  for value i: 0 <= i < 100
		  for array a: a[i] = true
		- write a function that deletes a value from the array
		  for value i: 0 <= i < 100
		  for array a: a[i] = false
		- write a function which prints the values in the set
		- write a function which creates a new array representing the union set between two sets
*/

#include <stdio.h>
#include "csharpsetproblem.h"

int main () {
	boolean a[100], b[100], c[100];

	initializeSet(a);
	initializeSet(b);
	initializeSet(c);

	insertValue(a, 1);
	insertValue(a, 2);
	insertValue(a, 3);
	insertValue(a, 4);
	insertValue(a, 5);

	insertValue(b, 2);
	insertValue(b, 4);
	insertValue(b, 6);
	insertValue(b, 8);
	insertValue(b, 10);

	printf("Printing set A:\n");
	printSet(a);
	printf("Printing set B:\n");
	printSet(b);

	findUnionSet(a, b, c);
	printf("Printing set C (union set):\n");
	printSet(c);

	deleteValue(a, 4);

	findUnionSet(a, b, c);
	printf("Printing set A after deleting value 4:\n");
	printSet(a);
	printf("Printing set C (union set):\n");
	printSet(c);

	return 0;
}

// initialize a boolean array with 100 elements so that each element = false
boolean* initializeSet (boolean* arr) {
	for (int i = 0; i < 100; i++) {
		arr[i] = false;
	}

	return arr;
}

// set element at index 'value' = true
// 0 <= value < 100
// arr MUST have 100 elements
boolean* insertValue (boolean* arr, int value) {
	if (value >= 0 && value < 100)
		arr[value] = true;
	else
		printf("Invalid Argument: %d. Value must be in 0-99.\n", value);

	return arr;
}

// set element at index 'value' = false
// 0 <= value < 100
// arr MUST have 100 elements
boolean* deleteValue (boolean* arr, int value) {
	if (value >= 0 && value < 100)
		arr[value] = false;
	else
		printf("Invalid Argument: %d. Value must be in 0-99.\n", value);

	return arr;
}

// prints each value in set 'arr' to the console
// arr MUST have 100 elements
void printSet (boolean* arr) {
	for (int i = 0; i < 100; i++) {
		if (arr[i])
			printf("%d ", i);
	}
	printf("\n");
}

// returns the union set of a and b
// a, b, and result MUST EACH have 100 elements
boolean* findUnionSet (boolean* a, boolean* b, boolean* result) {
	for (int i = 0; i < 100; i++) {
		result[i] = (a[i] && b[i]); // if a[i] AND b[i] THEN result[i] == true (else == false)
	}

	return result;
}
