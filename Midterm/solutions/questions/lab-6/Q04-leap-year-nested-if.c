/*
 * Lab 6 - Q4: Leap Year (nested if)
 * Topic: nested if, %
 *
 * Read a year and decide whether it is a leap year, using the
 * remainders of division by 4, 100 and 400.
 * Solve it with NESTED if statements (not one combined condition).
 *
 * Rules:
 *   - Years divisible by 4 are leap years (e.g. 2016, 2020, 2024).
 *   - But a multiple of 100 is a leap year only if it is also
 *     divisible by 400.
 *
 * Examples:
 *   1900 -> not a leap year (divisible by 4 and 100, but not by 400)
 *   2000 -> leap year (divisible by 100 and by 400)
 */

#include <stdio.h>

int main()
{
    int year = 0;
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 4 == 0)
    {
        if (year % 100 != 0)
        {
            printf("Leap"); // e.g. 2024
        }
        else
        {
            if (year % 400 == 0)
                printf("Leap"); // e.g. 2000
            else
                printf("Not Leap"); // e.g. 1900
        }
    }
    else
    {
        printf("Not Leap");
    }

    return 0;
}