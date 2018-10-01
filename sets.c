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

	a = deleteElement (a, 2);
	printf("Printing A, with 2 deleted\n");
	printIntArray(a);

	return 0;
}

IntArray initializeIntArray (IntArray arr) {
	arr.values = NULL;
	arr.length = 0;
	arr.size = 0;

	return arr;
}

IntArray insertElement (IntArray arr, int value) {
	// check if array is supposed to have elements in it
	// if it is supposed to have no elements, make sure that's true
	if (arr.size == 0 || arr.length == 0) {
		free(arr.values);
		arr.size = 0;
		arr.length = 0;
		arr.values = NULL;
	}

	if (arr.values == NULL) {
		arr.values = malloc(1*sizeof(*(arr.values)));
		arr.size = 1;
	} else if (arr.length == arr.size) {
		arr.values = realloc(arr.values, (arr.size*2)*sizeof(*(arr.values)));
		arr.size *= 2;
	}

	arr.values[arr.length++] = value; // add value to end and then increase length by 1

	arr = bubbleSortIntArray(arr);

	return arr;
}

IntArray deleteElement (IntArray arr, int value) {
	int index = search (arr, value);

	if (index > -1) {
		for (int i = index; i < arr.length - 1; i++) {
			arr.values[i] = arr.values[i + 1];
		}

		arr.length--;

		// if half the size of the array is greater than the length, reduce size by half
		double halfSize = arr.size / 2;
		if (floor(halfSize) == halfSize
			&& halfSize > arr.length) {
			arr.values = realloc(arr.values, halfSize*sizeof(*(arr.values)));
		}
	} else {
		printf("Value %d was not found. No changes made.\n", value);
	}

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
				break;
			}
		}
	}

	return result;
}

int search (IntArray arr, int value) {
	for (int i = 0; i < arr.length; i++) {
		if (arr.values[i] == value)
			return i;
	}

	return -1;
}
