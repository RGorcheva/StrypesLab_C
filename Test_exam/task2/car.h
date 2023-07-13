#ifndef CAR_H
#define CAR_H

#include <inttypes.h>

typedef struct{
	char model[20];
	uint8_t maxSpeed;
	double price;
}Car;

typedef int(*comp)(const void*, const void*); 

int modelAcs(const void* a, const void* b);
int modelDecs(const void* a, const void* b);
int speedAcs(const void* a, const void* b);
int speedDecs(const void* a, const void* b);
int priceAcs(const void* a, const void* b);
int priceDecs(const void* a, const void* b);

comp getComparator(int n);

#endif //CAR_H