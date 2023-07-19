#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randReal(double min, double max)
{
    return min + (double)rand()/RAND_MAX*(max - min);
}

int main(int argc, char* argv[], char* env[])
{
    srand(time(NULL));

    if (argc < 4)
    {
        fprintf(stderr, "Not enough argument!\n");
        exit(EXIT_FAILURE);
    }
    int n = 0;
    int m = 0;
    int p = 0;
    int isScanned = 0;
    isScanned = sscanf(argv[1],"%d", &n);
    if(!isScanned)
    {
        fprintf(stderr, "Arguments must be integer numbers!\n");
        exit(EXIT_FAILURE);
    }
    isScanned = sscanf(argv[2],"%d", &m);
        if(!isScanned)
    {
        fprintf(stderr, "Arguments must be integer numbers!\n");
        exit(EXIT_FAILURE);
    }
    isScanned = sscanf(argv[3],"%d", &p);
        if(!isScanned)
    {
        fprintf(stderr, "Arguments must be integer numbers!\n");
        exit(EXIT_FAILURE);
    }
    double* arr1 = (double*)malloc(n*sizeof(double));
    if(!arr1)
    {
        fprintf(stderr, "Cannot alocate memory!\n");
        exit(EXIT_FAILURE);
    }
    for (double* it = arr1; it < arr1 + n; it++)
    {
        *it = randReal(0.0, 1.0);
    }
    double* arr2 = (double*)realloc(arr1, (n + m)*sizeof(double));
    if(!arr2)
    {
        printf("Cannot alocate memory!\n");
        free(arr1);
        exit(EXIT_FAILURE);
    }
    for (double* it = arr2 + n; it < arr2 + n + m; it++)
    {
        *it = randReal(1.0, 2.0);
    }
    double* arr3 = (double*)realloc(arr2, (n + m + p)*sizeof(double));
    if(!arr3)
    {
        fprintf(stderr, "Cannot alocate memory!\n");
        free(arr2);
        exit(EXIT_FAILURE);
    }
    for (double* it = arr3 + n + m; it < arr3 + n + m + p; it++)
    {
        *it = randReal(2.0, 3.0);
    }
    for (double* it = arr3; it < arr3 + n + m + p; it++)
    {
        printf("%.2lf\n", *it);
    }
    free(arr3);
    exit(EXIT_SUCCESS);
}