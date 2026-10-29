/*
 * Lab 6 - Q5: Count from 0 to N (for loop)
 * Topic: for loop
 *
 * Read a number from the keyboard and print the numbers starting
 * from 0 up to that number, using a for loop.
 */

#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter a num: ");
    scanf("%d", &num);

    for (int i = 0; i <= num; ++i)
    {
        printf("%d ", i);
    }

    return 0;
}