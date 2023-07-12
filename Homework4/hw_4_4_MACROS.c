/*
Препроцесорни макроси	
4.1 Направете макрос MAX(x, y, z) , който връща най-голямото от три числа.
4.2 Направете макрос MIN(x, y, z) , който връща най-малкото от три числа.
4.3 Направете побитов макрос SETBIT(mask, bit) , който установява определен бит в 1 в побитовата маска.
4.4 Направете побитов макрос CLEARBIT(mask, bit) , който установява определен бит в 0 в побитовата маска.
4.5 Направете побитов макрос INVERSEBIT(mask, bit) , който обръща определен в побитовата маска.
4.6 Направете побитов макрос CHECKBIT(mask, bit), който връща 0 или 1 в зависимост от състоянието на бита.
4.7 Направете побитов макрос SWAP(a, b) , който разменя стойностите на две променливи.
*/

#include <stdio.h>
#include <inttypes.h>

#define MAX(X,Y,Z) ((X)>(Y) && (X)>(Z))?(X):(((Z)>(Y) && (Z)>(X))?(Z):(Y)) 
#define MIN(X,Y,Z) ((X)<(Y) && (X)<(Z))?(X):(((Z)<(Y) && (Z)<(X))?(Z):(Y))
#define SETBIT(MASK,BIT) (MASK)|=(1ULL << (BIT))
#define CLEARBIT(MASK,BIT) (MASK)&=(~(1ULL << (BIT)))
#define INVERSEBIT(MASK,BIT)  (MASK)^=(1ULL << (BIT))
#define CHECKBIT(MASK,BIT)  !!((MASK)&(1ULL << (BIT)))
#define SWAP(A,B) (A)=(A)-(B); (B)=(B)+(A); (A)=(B)-(A);

void printBinary(uint64_t n)
{
   uint64_t mask = (1ULL << 63);
   for (uint64_t i = 0; i < 64; i++)
   {
       (n & mask) ? printf("1") : printf("0");
       mask >>= 1ULL;
   }
   printf("\n");
}

int main(void)
{
	int a = 5;
	int b = 6;
	int c = 7;

	printf("MAX(%d, %d, %d) = %d\n", a, b, c, MAX(a,b,c));
	printf("MIN(%d, %d, %d) = %d\n", a, b, c, MIN(a,b,c));
	uint64_t set = 1ULL;
	SETBIT(set,3);
	printBinary(set);
	CLEARBIT(set,3);
	printBinary(set);
	INVERSEBIT(set,3);
	printBinary(set);
	printf("Check bit on position %d: %d\n", 3, CHECKBIT(set,3));

	printf("Before swap: a=%d, b=%d\n", a, b);
	SWAP(a,b);
	printf("After swap: a=%d, b=%d\n", a, b);
	return 0;
}
