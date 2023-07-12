/*
Направете функция, която извежда в стандартния изход резултата от функцията f 
извършена върху целочислен масив arr, който е с n на брой елементи.
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));
*/

#include <stdio.h>

int sum(int* arr, int n)
{
	if (!arr || !n)
	{
		printf("Array is empty!\n");
		return -1;
	}
	int sumArr = 0;
	for (int i = 0; i < n; i++)
	{
		sumArr += arr[i];
	}
	return sumArr;
}

int mult(int* arr, int n)
{
	if (!arr || !n)
	{
		printf("Array is empty!\n");
		return -1;
	}
	int multArr = 1;
	for (int i = 0; i < n; i++)
	{
		multArr *= arr[i];
	}
	return multArr;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*, int))
{
	printf("%d\n", f(arr, n));
}

int main(void)
{
	int arr[] = { 1, 2, 3 };
	size_t n = 3;
	arrayEvaluate(arr, n, sum);
	arrayEvaluate(arr, n, mult);
	return 0;
}
