#include <stdio.h>

int main () {
	char* firstName = "Reality";
	char* middleName = "J";
	char* lastName = "Fabric";

	char firstInitial = 'R';
	char middleInitial = 'J';
	char lastInitial = 'F';

	printf("Name: %s %s %s\n", firstName, middleName, lastName);
	printf("Initials: %c%c%c\n", firstInitial, middleInitial, lastInitial);

	return 0;
}
