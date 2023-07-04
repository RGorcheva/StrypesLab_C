/*
Въвежда се число с плаваща запетая от стандартния вход. 
Изпечатайте “YES” на стандартния изход, ако числото е достатъчно добра апроксимация на PI. В противен случай изпечатайте “NO”. 
Считаме едно число за добра апроксимация на PI, ако първите 6 цифри на въведеното число съвпадат с цифрите на PI.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.141593
#define EPS 0.000001

int isEqualToPI(double a)
{
	return fabs(a - PI) <= EPS;
}

int main(void)
{
    	double pi = 0;
    	int isScanned = 0;
	printf("Enter approximation of PI: ");
    	isScanned = scanf("%lf", &pi);
   	while(getchar() != '\n');
   	while(!isScanned)
	{
		printf("The entrance must be number!\nEnter number: ");
		isScanned = scanf("%lf", &pi);
        	while(getchar() != '\n');
	}
    	isEqualToPI(pi) ? printf("Yes\n") : printf("No\n");
    	return 0;
}
