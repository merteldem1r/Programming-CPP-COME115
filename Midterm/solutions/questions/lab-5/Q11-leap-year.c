/*
 * Lab 5 - Q11 (Extra Challenge): Leap Year
 * Topic: &&, ||, %
 *
 * Read a year from the user and decide whether it is a leap year.
 * A year is a leap year if it is divisible by 400,
 * OR divisible by 4 but not divisible by 100.
 *
 * Test cases:
 *   2024 -> leap year
 *   2025 -> not a leap year
 *   1900 -> not a leap year
 *   2000 -> leap year
 */

#include <stdio.h>

int main()
{
    int year = 0;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        printf("Leap");
    }
    else
    {
        printf("Not Leap");
    }

    return 0;
}