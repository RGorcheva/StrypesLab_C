#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define EPS 0.0001

typedef struct{
	char model[20];
	uint8_t maxSpeed;
	double price;
}Car;

Car carArr[10] =
{
	{
		.model = "Mazda2",
		.maxSpeed = 150,
		.price = 35000.0
	},
	{
		.model = "Mazda6",
		.maxSpeed = 200,
		.price = 65000.0
	},
	{
		.model = "Opel corsa",
		.maxSpeed = 145,
		.price = 15000.0
	},	
		{
		.model = "Toyota Yaris",
		.maxSpeed = 180,
		.price = 12000.0
	},
	{
		.model = "Renault Laguna",
		.maxSpeed = 185,
		.price = 75000.0
	},
	{
		.model = "Mercedes Benz",
		.maxSpeed = 215,
		.price = 100000.0
	},
	{
		.model = "BMW 3",
		.maxSpeed = 200,
		.price = 17000.0
	},
	{
		.model = "Ferrari",
		.maxSpeed = 220,
		.price = 99000.0
	},
	{
		.model = "Citroen C3",
		.maxSpeed = 145,
		.price = 35000.0
	},
	{
		.model = "Hunday",
		.maxSpeed = 150,
		.price = 60000.0
	}
};

int modelAcs(const void* a, const void* b);
int modelDecs(const void* a, const void* b);
int speedAcs(const void* a, const void* b);
int speedDecs(const void* a, const void* b);
int priceAcs(const void* a, const void* b);
int priceDecs(const void* a, const void* b);

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
	qsort(carArr, 10, sizeof(Car), getComparator(userChoice));
	for (int i = 0; i < 10; i++)
	{
		printf("Automobile %d:\n", i+1);
		printf("Model: %s,\n", carArr[i].model);
		printf("Max speed: %d,\n", carArr[i].maxSpeed);
		printf("price: %.2lf.\n\n", carArr[i].price);
	}
	return 0;
}