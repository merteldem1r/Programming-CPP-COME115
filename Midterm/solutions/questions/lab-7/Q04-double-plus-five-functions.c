/*
 * Lab 7 - Q4: "2 Times Plus 5" with Functions
 * Topic: functions without parameters (void / returning a value)
 *
 * Calculate 2 * x + 5 for a number x entered from the keyboard, by writing:
 *   a) a function that takes NO parameters and returns NO value (void)
 *      -> it reads the number, calculates and prints the result itself.
 *   b) a function that takes NO parameters and RETURNS a value
 *      -> it reads the number and returns the result; main prints it.
 *
 * Example: input 10 -> 25
 */

#include <stdio.h>

void calculate(void)
{
    int x, res;

    printf("Enter a number: ");
    scanf("%d", &x);

    res = 2 * x + 5;

    printf("Result from 1: %d\n", res);
}

int calculate2(void)
{
    int x, res;

    printf("Enter a number: ");
    scanf("%d", &x);

    res = 2 * x + 5;

    return res;
}

int main()
{
    calculate();
    int res = calculate2();
    printf("Result from 2: %d\n", res);

    return 0;
}