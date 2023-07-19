#include "comparators.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

static int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int r = n % 10;
        sum +=r;
        n /= 10;
    }
    return sum;
}

double randReal(double min, double max)
{
    return min + (double)rand() / RAND_MAX * (max - min);
}

int comparator1(const void* a, const void* b)
{
	if (fabs(*(double*)a - *(double*)b) < EPS)
	{
		return 0;
	}
	else if (*(double*)a - *(double*)b > 0)
	{
		return 1;
	}
	return -1;
}

int comparator2(const void* a, const void* b)
{
	if (fabs(*(double*)a - *(double*)b) < EPS)
	{
		return 0;
	}
	else if (*(double*)a - *(double*)b > 0)
	{
		return -1;
	}
	return 1;
}

int comparator3(const void* a, const void* b)
{
    int n1 = sumDigits((int)(*(double*)a));
    int n2 = sumDigits((int)(*(double*)b));
    return n1 - n2;
}

int comparator4(const void* a, const void* b)
{
	if (fabs(*(double*)a - *(double*)b) < EPS)
	{
		return 0;
	}
	else if (fabs(*(double*)a) - fabs(*(double*)b) > 0)
	{
		return 1;
	}
	return -1;
}
