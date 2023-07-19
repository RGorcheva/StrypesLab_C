#include "car.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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