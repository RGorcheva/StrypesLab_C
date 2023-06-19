/*
Въвежда се число в осмична бройна система с 3 цифри, което представя правата за достъп до определен файл. 
Изпечатайте правата за достъп в подходящ текстови формат.
*/

#include <stdio.h>

void printPermissions(int n)
{
    int x = 1;
    int w = 1 << 1;
    int r = 1 << 2;
    int user = (n/0100) % 010;
    int group = (n/010) % 010;
    int others = n % 010;
    printf("user:\t");
    (user & r) ? printf("R") : printf("-");
    (user & w) ? printf("W") : printf("-");
    (user & x) ? printf("X") : printf("-");
    printf("\ngroup:\t");
    (group & r) ? printf("R") : printf("-");
    (group & w) ? printf("W") : printf("-");
    (group & x) ? printf("X") : printf("-");
    printf("\nothers:\t");
    (others & r) ? printf("R") : printf("-");
    (others & w) ? printf("W") : printf("-");
    (others & x) ? printf("X") : printf("-");
    printf("\n");
}

int main(void)
{
    int access = 0;
    int isScanned = 0;
	printf("Enter octal number presenting permittions: ");
    isScanned = scanf("%o", &access);
    while(getchar() != '\n');
    while(!isScanned)
	{
		printf("The entrance must be octal number!\nEnter octal number: ");
		isScanned = scanf("%o", &access);
        while(getchar() != '\n');
	}
    printPermissions(access);
    return 0;
}