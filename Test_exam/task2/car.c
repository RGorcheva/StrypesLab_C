#include "car.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define EPS 0.0001

int modelAcs(const void* a, const void* b)
{
	return strcmp((*(Car*)a).model, (*(Car*)b).model);
}

int modelDecs(const void* a, const void* b)
{
	return -(strcmp((*(Car*)a).model, (*(Car*)b).model));
}
int speedAcs(const void* a, const void* b)
{
	return (*(Car*)a).maxSpeed - (*(Car*)b).maxSpeed;
}
int speedDecs(const void* a, const void* b)
{
	return -((*(Car*)a).maxSpeed - (*(Car*)b).maxSpeed);
}
int priceAcs(const void* a, const void* b)
{
	if (fabs((*(Car*)a).price - (*(Car*)b).price) < EPS)
	{
		return 0;
	}
	else if ((*(Car*)a).price - (*(Car*)b).price > 0)
	{
		return 1;
	}
	return -1;
}
int priceDecs(const void* a, const void* b)
{
	if (fabs((*(Car*)a).price - (*(Car*)b).price) < EPS)
	{
		return 0;
	}
	else if ((*(Car*)a).price - (*(Car*)b).price > 0)
	{
		return -1;
	}
	return 1;
}

comp getComparator(int n)
{
	switch (n)
	{
		case 1: return modelAcs; break;
		case 2: return modelDecs; break;
		case 3: return speedAcs; break;
		case 4: return speedDecs; break;
		case 5: return priceAcs; break;
		case 6: return priceDecs; break;
		default: return NULL;
	}
}
	