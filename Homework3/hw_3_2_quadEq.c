/*
Да се направи програма, която решава квадратно уравнение по подадени коефициенти a, b и c.
int quadEq(double a, double b, double c, double* x1, double* x2)
При успех функцията да връща 0, а при неуспех -1.
Програмата да се направи така, че коефициентите a, b и c да се четат като аргументи от командния ред
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quadEq(double a, double b, double c, double* x1, double* x2)
{
	double determinant = b*b - 4*a*c;
	//I will not calculate imaginary roots, they cannot be returned with the specified function prototype
	if ( determinant < 0)
	{
		printf("No real roots!\n");
		return -1;
	}
	if (determinant > 0)
	{
		*x1 = (-b + sqrt(determinant))/(2*a);
		*x2 = (-b - sqrt(determinant))/(2*a);
	}
	else
	{
		*x1 = *x2 = -b/(2*a);
	}
	return 0;
}

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		printf("Not enough arguments!\n");
	}
	
    double x1 = 0.0;
    double x2 = 0.0;
    double a = 0.0;
    double b = 0.0;
	double c = 0.0;
	
	a = atol(argv[1]);
	b = atol(argv[2]);
	c = atol(argv[3]);
	
    if(!quadEq(a, b, c, &x1, &x2))
    {
		printf("The roots of equasion (%.2lf)*x^2 + (%.2lf)*x + (%.2lf) = 0 are:\n", a, b, c);
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }
    return 0;
}