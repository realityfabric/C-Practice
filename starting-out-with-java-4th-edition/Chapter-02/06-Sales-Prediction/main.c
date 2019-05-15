#include <stdio.h>

int main () {
	// division A brings in 62% of total sales for company COM
	// predict how much they'll make if the total sales is $4.6 million

	double percent = 0.62;
	double totalSales = 4.6; // in millions
	double prediction = totalSales * percent;

	printf("Division A will bring in $%f\n", prediction);

	return 0;
}
