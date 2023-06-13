/*
Въвежда се цяло число от стандартния вход в интервала [-100000, 100000]. 
Изберете подходящ тип, в който да запазите въведеното число с възможно най-малко използвана памет. 
Използвайте побитови оператори за да проверите дали числото е положително или отрицателно. 
Ако числото е положително - изпечатайте “YES” на стандартния изход. В противен случай - изпечатайте “NO”.
*/

#include <stdio.h>

int main(void)
{
    int n = 0;
    int isScanned = 0;
    printf("Enter an integer number in the interval [-100000; 1000000]: ");
    isScanned = scanf("%d", &n);
    while(getchar() != '\n');
    while(!isScanned)
    {
        printf("You must enter an integer number in the interval [-100000; 1000000].\nPlease, enter a number: ");
        isScanned = scanf("%d", &n);
        while(getchar() != '\n');
    }
    unsigned mask = 1;
    (n & mask) ? printf("NO\n") : printf("YES\n");
    return 0;
}
