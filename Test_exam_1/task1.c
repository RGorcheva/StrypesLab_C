#include <stdio.h>
#include <inttypes.h>//stdint.h
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define EPS 0.0001
#define COUNT 10

typedef struct{
	char model[21];
	uint8_t maxSpeed;
	double price;
}Car;

//rand int
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

char* randModel(char* str)
{
	str[0] = randSym(1);
	int numberOfLetters = randInt(5, 11);
	for (int i = 1; i < numberOfLetters; i++)
	{
		str[i] = randSym(0);
	}
	str[numberOfLetters] = '\0';
	return str;
}

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
typedef int(*comp)(const void*, const void*); 
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
	
int main(void)
{
	srand(time(NULL));
	Car carArr[COUNT];
	for (int i  = 0; i < COUNT; i ++)
	{
		randModel(carArr[i].model);
		carArr[i].maxSpeed = randInt(100, 255);
		carArr[i].price = randReal(1000.0, 100000.0);
	} 
	int userChoice = 0;
    int isScanned = 0;
    isScanned = scanf("%d", &userChoice);
    while(getchar()!='\n');
    while(!isScanned)
    {
        printf("You can choose between 1 and 6!\nYour choice: ");
        isScanned = scanf("%d", &userChoice);
        while(getchar()!='\n');
    }
	qsort(carArr, COUNT, sizeof(Car), getComparator(userChoice));
	for (int i = 0; i < 10; i++)
	{
		printf("%11s", carArr[i].model);
		printf("%5d ", carArr[i].maxSpeed);
		printf("%7.2lf\n", carArr[i].price);
	}
	return 0;
}