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
