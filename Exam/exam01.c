#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define EPS 0.0001
#define COUNT 15

typedef struct 
{
    char title[101];
    char author[101];
    uint16_t pages;
    double price;
}Book;

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

typedef int(*comparator_t)(const void*, const void*); 

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


int main(void)
{
	srand(time(NULL));

	Book bookArr[COUNT];
	for (int i  = 0; i < COUNT; i ++)
	{
		randString(bookArr[i].title, 10, 20);
        char space[2] = { ' ' };
        char lastName[12];
        randString(bookArr[i].author, 3, 10);
        randString(lastName, 3, 10);
        strcat(bookArr[i].author, space);
        strcat(bookArr[i].author, lastName);
		bookArr[i].pages = randInt(10, 1000);
		bookArr[i].price = randReal(2.0, 100.0);
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
	qsort(bookArr, COUNT, sizeof(Book), getComparator(userChoice));
	for (int i = 0; i < 10; i++)
	{
		printf("Title: %25s\t", bookArr[i].title);
		printf("Author: %25s\t", bookArr[i].author);
        printf("Numbr of pages: %5d\t", bookArr[i].pages);
		printf("Price: %10.2lf\n", bookArr[i].price);
	}
	return 0;
}