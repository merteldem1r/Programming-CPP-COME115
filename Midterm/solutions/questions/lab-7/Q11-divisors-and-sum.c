/*
 * Lab 7 - Q11 (Practice): Divisors and Their Sum
 * Topic: functions (void and returning), loops
 *
 * Read a positive integer from the user, print its positive divisors
 * and calculate the sum of those divisors. Use these two functions:
 *
 *   void bolenleriYazdir(int n)   // "printDivisors": prints the divisors
 *   int  bolenToplami(int n)      // "sumOfDivisors": returns their sum
 *
 * Example: 12 -> divisors: 1 2 3 4 6 12, sum: 28
 */

#include <stdio.h>

void printDivisors(int n) // printDivisors
{
    printf("Divisors: ");
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }
}

int sumOfDivisors(int n) // sumOfDivisors
{
    int sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main(void)
{
    int num = 0;
    printf("Enter the number: ");

    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input, enter the integer");
        return 0;
    }

    if (num <= 0)
    {
        printf("Enter positive number");
        return 0;
    }

    printDivisors(num);
    printf("\nSum Divisors: %d", sumOfDivisors(num));

    return 0;
}