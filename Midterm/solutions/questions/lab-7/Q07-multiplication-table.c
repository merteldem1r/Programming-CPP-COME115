/*
 * Lab 7 - Q7 (Practice): Multiplication Table
 * Topic: for loop, input validation
 *
 * Read an integer between 1 and 10 from the user and print its
 * multiplication table from 1 to 10.
 * If the number is outside 1-10, print an error message.
 *
 * Example (input 3):
 *   3 x 1 = 3
 *   3 x 2 = 6
 *   ...
 *   3 x 10 = 30
 */

#include <stdio.h>

void printMultiplication(int num)
{
    for (int i = 1; i <= 10; ++i)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int main()
{
    int num;

    printf("Enter a number 1-10: ");
    scanf("%d", &num);

    if (num < 1 || num > 10)
    {
        printf("Wrong number range, enter 1-10");
        return 0;
    }

    printMultiplication(num);

    return 0;
}
