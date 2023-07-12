/*
Направете функция, която намира втория по големина елемент от масив с реални числа.
int secondMax(const int* arr, size_t n, int* secondMax);
Направете така, че да прихванете следните изключителни ситуации, когато не намирате втори по големина елемент:
•	празен масив;
•	масивът има само един елемент;
•	масивът има само еднакви елементи (всички са равни на максималния).
При извикването на функцията в main() направете така че, да изведете съобщения за всички ситуации.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EPS 0.0001

int comp(const void* a, const void* b)
{
	if (fabs(*(double*)a - *(double*)b) < EPS) 
	{
		return 0;
	}
	else if ((*(double*)a - *(double*)b) > 0) 
	{
		return -1;
	}
	return 1;
}

int secondMax(const double* arr, size_t n, double* secondMax)
{
	if (!arr || !n)
	{
		return 1; // arr is NULL pointer or arr is empty
	}
	if (n == 1)
	{
		return 2; // arr has only one element
	}
	double* arrCopy = (double*)malloc(n*sizeof(double));
	if(!arrCopy)
	{
		printf("Cannot alocate memory!\n");
		return -1;
	}
	double* isCopied = memcpy(arrCopy, arr, n*sizeof(double));
	if(!isCopied)
	{
		printf("Error in copying array!\n");
		free(arrCopy);
		return -1;
	}

	qsort(arrCopy, n, sizeof(double), comp);

	for(int i = 1; i < n; i++)
	{
		if ((arrCopy[i-1] - arrCopy[i]) > EPS)
		{
			*secondMax = arrCopy[i];
			free(arrCopy);
			return 0; //OK
		}
	}
	free(arrCopy);
	return 3; // All elements of the array are equal
}

int main(void)
{
	double sm = 0;
	double arr[] = { 12.0, 34.0, 5.0, 70.0, 46.0, 46.1 };
	switch(secondMax(arr, 6, &sm))
	{
		case 0: printf("The second max element of the array is %.2lf.\n", sm); 
				break;
		case 1: printf("The array is empty!\n"); 
				break;
		case 2: printf("The array has only one element!\n"); 
				break;
		case 3: printf("All elements of the array are equal!\n");
				break;
		default: printf("Undefined error!\n");
				break;		
	}
	return 0;
}