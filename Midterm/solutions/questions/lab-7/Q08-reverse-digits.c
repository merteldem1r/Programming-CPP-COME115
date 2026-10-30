/*
 * Lab 7 - Q8 (Practice): Reverse the Digits of a Number
 * Topic: while loop, % and /
 *
 * Read a positive integer from the user and print its digits in
 * reverse order, using a while loop.
 *   - Use % 10 to get the last digit.
 *   - Use / 10 to remove the last digit.
 *
 * Example: 12345 -> 54321
 */

#include <stdio.h>

int reverseInt(int num)
{
    int rev = 0;
    int sign = num < 0 ? -1 : 1;
    int absNum = num * sign;

    while (absNum > 0)
    {
        int digit = absNum % 10;
        rev = rev * 10 + digit;
        absNum /= 10;
    }

    return rev * sign;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Reversed: %d", reverseInt(num));
}