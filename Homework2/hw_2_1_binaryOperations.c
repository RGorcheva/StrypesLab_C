/*
Предварително са фиксирани 64 различни елемента. 
Всеки елемент е асоцииран с индекс от 0 до 63. Интересуваме се от множество, в което всеки елемент:
●	Или присъства само веднъж
●	Или отсъства

Наличието на елементи кодирайте в една променлива от тип uint64_t.
●	Ако елемент 5 присъства, то тогава 5ят бит е 1.
●	Ако елемент 5 отсъства, то тогава 5ят бит е 0.

Възможните двоични представяния за подобно множество с 3 елемента са:
●	000 - всички елементи отсъстват
●	001 - само 3 присъства
●	010 - само 2 присъства
●	011 - 3 и 2 присъстват
●	100 - 1 присъства
●	101 - 1 и 3 присъстват
●	110 - 1 и 2 присъстват
●	111 - всички елементи присъстват

Реализирайте следните функции:

#include <stdint.h>
#include <stdbool.h>

bool isEmpty(uint64_t set);
●	Връща 1 ако множеството е празно. Иначе - връща 0.

uint64_t add(uint64_t set, char index);
●	Добавя елемента с подадения индекс към множеството set и връща новото множество като резултат.

uint64_t remove(uint64_t set, char index);
●	Премахва елемента с подадения индекс от множеството set и връща новото множество като резултат.

bool isFull(uint64_t set);
●	Връща 1 ако всички възможни елементи принадлежат на множеството. Иначе - връща 0.

bool  isSubset(uint64_t setA, uint64_t setB);
●	Връща 1 ако setB е подмножество на setA.


uint64_t union(uint64_t setA, uint64_t setB);
●	Връща обединението на setA и setB.

uint64_t intersect(uint64_t, setA, uint64_t setB);
●	Връща сечението на setA и setB.

uint64_t difference(uint64_t setA, uint64_t setB);
●	Връща разликата на setA и setB.

char numElements(uint64_t set);
●	Връща броя на елементите в set.

Използвайте побитови операции за да реализирате функциите, където това е възможно.
*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

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

bool my_isEmpty(uint64_t set)
{
	return (set ^ 0ULL) ? 0 : 1;
}

uint64_t my_add(uint64_t set, char index)
{
	return set | (1ULL << index);
}

uint64_t my_remove(uint64_t set, char index)
{
	return set & ~(1ULL << index);
}

bool my_isFull(uint64_t set)
{
	return !(set^(-1ULL));
}

bool  my_isSubset(uint64_t setA, uint64_t setB)
{
	return !((setA & setB) ^ setB);
}

uint64_t my_union(uint64_t setA, uint64_t setB)
{
	return setA | setB;
}

uint64_t my_intersect(uint64_t setA, uint64_t setB)
{
	return setA & setB;
}

uint64_t my_difference(uint64_t setA, uint64_t setB)
{
	return (setA | setB) ^ setB;
}

char my_numElements(uint64_t set)
{
	uint64_t mask = 1ULL;
	char count = 0;
	for (int i = 0; i < 64; i++)
	{
		if (set & mask)
		{
			count++;
		}
    	mask <<= 1ULL;
	}
	return count;
}

int main(void)
{
	uint64_t setA = 0;
	uint64_t setB = 0;
	int index = 0;
	int isScanned = 0;

	printf("Enter setA:\n");
	isScanned = scanf("%lu", &setA);
	while(getchar()!='\n');
	while(!isScanned)
	{
		printf("Enter unsigned int number:\n");
		isScanned = scanf("%lu", &setA);
		while(getchar()!='\n');
	}

	printf("Enter setB:\n");
	isScanned = scanf("%lu", &setB);
	while(getchar()!='\n');
	while(!isScanned)
	{
		printf("Enter unsigned int number:\n");
		isScanned = scanf("%lu", &setB);
		while(getchar()!='\n');
	}

	printf("Enter index:\n");
	isScanned = scanf("%d", &index);
	while(getchar()!='\n');
	while(!isScanned)
	{
		printf("Enter number between 0 and 63:\n");
		isScanned = scanf("%d", &index);
		while(getchar()!='\n');
	}

	printf("\nSetA: %lu\n", setA);
	printBinary(setA);

	printf("\nSetB: %lu\n", setB);
	printBinary(setB);

	printf("\nIs the set empty: %d\n", my_isEmpty(setA));

	printf("\nAdd set on position %d: ", index);
	printBinary(my_add(setA, index));

	printf("\nIs the set full: %d\n", my_isFull(setA));

	printf("\nRemove set on position %d: ", index);
	printBinary(my_remove(setA, index));

	printf("\nIs setB subset to setA: %d\n", my_isSubset(setA, setB));

	printf("\nUnion of setA and setB: ");
	printBinary(my_union(setA, setB));

	printf("\nIntersect of setA and setB: ");
	printBinary(my_intersect(setA, setB));

	printf("\nDifference between setA and setB: ");
	printBinary(my_difference(setA, setB));

	printf("\nNumber of elements in setA: %d\n", my_numElements(setA));

	return 0;
}
