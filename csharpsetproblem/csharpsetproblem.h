#ifndef __CSHARPSETPROBLEM__
#define __CSHARPSETPROBLEM__

typedef enum { false, true } boolean;

boolean* initializeSet (boolean* arr);
boolean* insertValue (boolean* arr, int value);
boolean* deleteValue (boolean* arr, int value);
void printSet (boolean* arr);
boolean* findUnionSet (boolean* a, boolean* b, boolean* result);

#endif
