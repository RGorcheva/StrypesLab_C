/*
Да се направи програма, която изчислява лицето и периметъра на триъгълник по дадени три страни.
Да се създаде следната функция:
int triangle(double a, double b, double c, double* S, double *P)
При успех функцията да връща 0, а при неуспех -1.
Програмата да се направи така, че страните за триъгълника да се четат от стандартния вход (на един ред разделени с интервали).
Въвеждане да се приключи до въвеждане на EOF. 
При некоректни данни да се изведе съобщение за грешка в стандартния изход.
*/

#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double *P)
{
    if (a < 0 || b < 0 || c < 0 || a + b <= c || a + c <= b || b + c <= a)
    {
        printf("Invalid triangle sides!\n");
        return -1;
    }
    double p = (a + b + c)/2;
    if (P)
    {
        *P = 2 * p;
    }
    if (S)
    {
       *S = sqrt(p * (p - a) * (p - b) * (p - c));
    }
    return 0;
}


int main(void)
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double S = 0.0;
    double P = 0.0;
	int isScanned = 0;
	isScanned = scanf("%lf %lf %lf", &a, &b, &c);
	while(getchar() != '\n');
	while(isScanned != 3)
	{
		printf("You must enter three double numbers: ");
		isScanned = scanf("%lf %lf %lf", &a, &b, &c);
		while(getchar() != '\n');
	}
    if(!triangle(a, b, c, &S, &P))
    {
        printf("S = %.2lf\n", S);
        printf("P = %.2lf\n", P);
    }
    return 0;
}