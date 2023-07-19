# include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 10
#define MIN -100
#define MAX 100
#define EPS 0.0001

typedef struct {
    double x;
    double y;
}point_t;

typedef struct 
{
    point_t A;
    point_t B;
}rectangle_t;

double randReal(const double max, const double min)
{
    return min + (double)rand()/RAND_MAX*(max- min);
}

double distE(point_t a, point_t b)
{
    return sqrt(pow((a.x - b.x), 2.0) + pow((a.y - b.y), 2.0));
}

int main(void)
{
    point_t arr[COUNT] = { 0.0 , 0.0 };
    for (int i = 0; i < COUNT; i++)
    {
        arr[i].x = randReal(MIN, MAX);
        arr[i].y = randReal(MIN, MAX);
    }
    for (int i = 0; i < COUNT; i++)
    {
        printf("Point %d(%5.2lf, %5.2lf)\n", i, arr[i].x, arr[i].y);
    }
    double maxDist = 0.0;
    double d = 0.0;
    for (int i = 0; i < COUNT - 1; i++)
    {
        for (int j = i + 1; j < COUNT; j++)
        {
            if ((d = distE(arr[i], arr[j])) > maxDist)
            {
                maxDist = d;
            }
        }
    }
    printf("Max dist between points is %.2lf.\n", maxDist);
    return 0;
}