/*
Напишете програма, която пресмята и изпечатва апроксимация на Неперовото число (2,7182818).
*/

#include <stdio.h>

double NapiersConstant(const unsigned n)
{
	double e = 1;
	double chlen = 1;
	for (int i = 1; i <= n; i++)
	{
		chlen = chlen/i;
		e += chlen;
	}
	return e;
}

int main(void)
{
	unsigned n = 0;
	int isScanned = 0;
	printf("Enter approximation number n:\n");
	isScanned = scanf("%d", &n);
	while (getchar() != '\n');
	while (!isScanned || n < 0)
	{
		printf("n must be positive int:\n");
		isScanned = scanf("%d", &n);
		while (getchar() != '\n');
	}
	printf("e(n = %d) = %.7lf\n", n, NapiersConstant(n));
	return 0;
}