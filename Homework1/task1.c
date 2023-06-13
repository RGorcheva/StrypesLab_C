/*
Напишете програма, която прочита 1 малка латинска буква от стандартния вход. 
Програмата изпечатва главната латинска буква, съответстваща на въведената малка латинска буква.
*/

#include <stdio.h>

int main(void)
{
    char ch = 0;
    int isScanned = 0;
	printf("Enter lowercase letter: ");
    isScanned = scanf("%c", &ch);
    while(getchar() != '\n');
    while(!isScanned || ch < 'a' || 'z' < ch)
	{
		printf("You must enter lowercase letter!\nEnter lowercase letter: ");
		isScanned = scanf("%c", &ch);
		while(getchar() != '\n');
	}
    printf("Uppecase letter: %c\n", ch + 'A' - 'a');
    return 0;
}
