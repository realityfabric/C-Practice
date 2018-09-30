#include "sets.h"

int main () {
	IntArray a, b, c;
	a = initializeIntArray(a);
	b = initializeIntArray(b);
	c = initializeIntArray(c);

	a = insertElement (a, 1);
	a = insertElement (a, 2);
	a = insertElement (a, 3);
	a = insertElement (a, 4);
	a = insertElement (a, 5);

	b = insertElement (b, 2);
	b = insertElement (b, 4);
	b = insertElement (b, 6);
	b = insertElement (b, 8);
	b = insertElement (b, 10);

	c = findUnion(a,b);

	printf("Printing A:\n");
	printIntArray(a);
	printf("Printing B:\n");
	printIntArray(b);
	printf("Printing C (union set):\n");
	printIntArray(c);

	return 0;
}

IntArray initializeIntArray (IntArray arr) {
	arr.values = NULL;
	arr.length = 0;

	return arr;
}

IntArray insertElement (IntArray arr, int value) {
	// check if array is supposed to have elements in it
	// if it is supposed to have no elements, make sure that's true
	if (arr.length == 0) {
		free(arr.values);
		arr.values = NULL;
	}

	if (arr.values == NULL) {
		arr.values = malloc(1*sizeof(int));
	} else if (sizeof(arr.values) / sizeof(int) == arr.length) {
		arr.values = realloc(arr.values, (arr.length*2)*sizeof(int));
	}

	arr.values[arr.length++] = value; // add value to end and then increase length by 1

	arr = bubbleSortIntArray(arr);

	return arr;
}

IntArray bubbleSortIntArray (IntArray arr) {
	int a, b;

	for (int i = 0; i < arr.length - 1; i++) {
		for (int j = 0; j < arr.length - 1; j++) {
			a = arr.values[j];
			b = arr.values[j + 1];
			if (a > b) {
				arr.values[j] = b;
				arr.values[j + 1] = a;
			}
		}
	}
	return arr;
}

void printIntArray (IntArray arr) {
	for (int i = 0; i < arr.length; i++) {
		printf("%d ", arr.values[i]);
	}
	printf("\n");
}

// returns IntArray with unique values which exist in both A and B
IntArray findUnion (IntArray a, IntArray b) {
	IntArray result;
	result = initializeIntArray(result);

	for (int i = 0; i < a.length; i++) {
		for (int j = 0; j < b.length; j++) {
			if (a.values[i] == b.values[j]) {
				result = insertElement (result, a.values[i]);
				printf("Element %d added to union\n", a.values[i]);
				break;
			}
		}
		printf("Next Value in A\n");
	}

	return result;
}
