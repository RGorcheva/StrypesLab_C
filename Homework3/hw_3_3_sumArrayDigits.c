/*
Направете функция, която намира сумата на всички цифри от масив с цели положителни числа.
unsigned sumArrayDigits(const int* arr, size_t n);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned sumArrayDigits(const int* arr, size_t n)
{
	if (!n)
	{
		return 0;
	}
	unsigned sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		unsigned private = abs(arr[i]);
		while(private)
		{
			unsigned remainder = private % 10;
			private /= 10;
			sum += remainder;
		}
	}
	return sum;
}
int main(void)
{
	size_t num = 0;
	int isScanned = 0;
	printf("Enter number of elements of array: ");
	isScanned = scanf("%zu", &num);
	while(getchar() != '\n');
	while(!isScanned)
	{
		printf("You must enter number greater than 0: ");
		isScanned = scanf("%zu", &num);
		while(getchar() != '\n');
	}
	int* arr = (int*)malloc(num*sizeof(int));
	printf("Enter %zu elements of array: ", num);
	for(int i = 0; i < num; i++)
	{
        isScanned = scanf("%d", arr + i);
        while(getchar() != '\n');
	    while(!isScanned)
	    {
		    printf("You must enter int number: ");
		    isScanned = scanf("%d", arr + i);
		    while(getchar() != '\n');
	    }
	}
	printf("Sum of array digits: %u\n", sumArrayDigits(arr, num));
   	return 0;
}
