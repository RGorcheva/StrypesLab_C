#include <stdio.h>
#include "Book.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNT 15

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