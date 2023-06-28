/*
Напишете програма, която прочита 2 цели неотрицателни числа от
стандартния вход. Програмата изпечатва най-голямия общ делител на
двете числа на стандартния изход.
*/

#include <stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

unsigned int GCD(unsigned int a, unsigned int b)
{
	unsigned remainder = 1;
	if (b == max(a, b))
	{
		unsigned temp = a;
		a = b;
		b = temp;
	}
	while(remainder)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int main(void)
{
	unsigned a = 0;
	unsigned b = 0;
	int isScanned = 0;
	printf("Enter two non-negative numbers:\n");
	isScanned = scanf("%d %d", &a, &b);
	while (getchar() != '\n');
	while (isScanned != 2 || a < 0 || b < 0)
	{
		printf("You must enter two non-negative numbers:\n");
		isScanned = scanf("%d %d", &a, &b);
		while (getchar() != '\n');
	}
	printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));
	return 0;
}