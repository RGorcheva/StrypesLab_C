#ifndef COMPARATORS_H
#define COMPARATORS_H

// #define COUNT 10
// #define MIN -10.0
// #define MAX 20.0
#define COUNT_FUNC 4
#define EPS 0.0001

typedef int (*comp)(const void*,const void*);

double randReal(double min, double max);
int comparator1(const void* a, const void* b);
int comparator2(const void* a, const void* b);
int comparator3(const void* a, const void* b);
int comparator4(const void* a, const void* b);

#endif // COMPARATORS_H