#ifndef BOOK_H
#define BOOK_H

#include <inttypes.h>

#define EPS 0.0001


typedef struct 
{
    char title[101];
    char author[101];
    uint16_t pages;
    double price;
}Book;

typedef int(*comparator_t)(const void*, const void*); 

int randInt(int min, int max);
double randReal(double min, double max);
char randSym(int isUpper);
char* randString(char* str, int min, int max);

int titleAcs(const void* a, const void* b);
int titleDecs(const void* a, const void* b);
int pagesAcs(const void* a, const void* b);
int pagesDecs(const void* a, const void* b);
int priceAcs(const void* a, const void* b);
int priceDecs(const void* a, const void* b);
comparator_t getComparator(int n);

#endif //BOOK_H