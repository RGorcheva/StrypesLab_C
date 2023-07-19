#include "comparators.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	double arrReal[COUNT] = { 0.0 };
    comp arrFunc[COUNT_FUNC] = { comparator1, comparator2, comparator3, comparator4 };
	for (int i  = 0; i < COUNT; i ++)
	{
		arrReal[i] = randReal(MIN, MAX);
	}
	int userChoice = 0;
    int isScanned = 0;
    printf("Choose between 1 and 4!\nYour choice: ");
    isScanned = scanf("%d", &userChoice);
    if(!isScanned || (userChoice < 1 || userChoice > 4))
    {
        fprintf(stderr, "Wrong choice!\nYou must choose between 1 and 4!\n");
        exit(EXIT_FAILURE);
    }
	qsort(arrReal, COUNT, sizeof(arrReal[0]), arrFunc[userChoice - 1]);
	for (int i = 0; i < COUNT; i++)
	{
		printf("%5.2lf\n", arrReal[i]);
	}
    exit(EXIT_SUCCESS);
}