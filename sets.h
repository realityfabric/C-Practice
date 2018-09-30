#ifndef __SETS__
#define __SETS__

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* values;
	int length;
} IntArray;

IntArray initializeIntArray (IntArray arr);
IntArray insertElement (IntArray arr, int value);
IntArray bubbleSortIntArray (IntArray arr);
void printIntArray ();
IntArray findUnion (IntArray a, IntArray b);

#endif
