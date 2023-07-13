#include "car.h"
#include <stdio.h>
#include <stdlib.h>

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