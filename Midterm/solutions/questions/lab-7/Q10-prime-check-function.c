/*
 * Lab 7 - Q10 (Practice): Prime Number Check
 * Topic: functions, loops
 *
 * Read an integer from the user and check whether it is prime.
 * Do the check in a function:
 *
 *   int asalMi(int sayi)   // "isPrime"
 *
 * It must return 1 if the number is prime, 0 otherwise.
 *
 * Examples: 2 -> prime, 17 -> prime, 1 -> not prime, 15 -> not prime
 */

#include <stdio.h>

int isPrime(int sayi) // isPrime
{
    if (sayi <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= sayi / i; ++i)
    {
        if (sayi % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int num = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    if (isPrime(num))
    {
        printf("Prime");
    }
    else
    {
        printf("Not prime");
    }

    return 0;
}