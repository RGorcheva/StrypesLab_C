#include "Book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int randInt(int min, int max)
{
	return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
	return min + (double)rand() / RAND_MAX * (max - min);
}

char randSym(int isUpper)
{
	if (isUpper)
	{
		return 'A' + rand() % ('Z' - 'A' + 1);
	}
	else
	{
		return 'a' + rand() % ('Z' - 'A' + 1);
	}
}

char* randString(char* str, int min, int max)
{
	str[0] = randSym(1);
	int numberOfLetters = randInt(min + 1, max + 1);
	for (int i = 1; i < numberOfLetters; i++)
	{
		str[i] = randSym(0);
	}
	str[numberOfLetters] = '\0';
	return str;
}

int titleAcs(const void* a, const void* b)//string+
{
	return strcmp((*(Book*)a).title, (*(Book*)b).title);
}

int titleDecs(const void* a, const void* b)
{
	return -(strcmp((*(Book*)a).title, (*(Book*)b).title));
}

int pagesAcs(const void* a, const void* b)
{
	return (*(Book*)a).pages - (*(Book*)b).pages;
}

int pagesDecs(const void* a, const void* b)
{
	return -((*(Book*)a).pages - (*(Book*)b).pages);
}

int priceAcs(const void* a, const void* b)
{
	if (fabs((*(Book*)a).price - (*(Book*)b).price) < EPS)
	{
		return 0;
	}
	else if ((*(Book*)a).price - (*(Book*)b).price > 0)
	{
		return 1;
	}
	return -1;
}

int priceDecs(const void* a, const void* b)
{
	if (fabs((*(Book*)a).price - (*(Book*)b).price) < EPS)
	{
		return 0;
	}
	else if ((*(Book*)a).price - (*(Book*)b).price > 0)
	{
		return -1;
	}
	return 1;
}

comparator_t getComparator(int n)
{
	switch (n)
	{
		case 1: return titleAcs; break;
		case 2: return titleDecs; break;
		case 3: return pagesAcs; break;
		case 4: return pagesDecs; break;
		case 5: return priceAcs; break;
		case 6: return priceDecs; break;
		default: return NULL;
	}
}