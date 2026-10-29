/*
 * Lab 6 - Q6: Odd Numbers from 1 to N (while loop)
 * Topic: while loop
 *
 * Read a number from the keyboard and print the odd numbers starting
 * from 1 up to that number, using a while loop.
 */

#include <stdio.h>

int main(void)
{
    int num = 0, count = 1;
    printf("Enter a num: ");
    scanf("%d", &num);

    while (count++ <= num)
    {
        if (count % 2 == 1)
        {
            printf("%d ", count);
        }
    }

    return 0;
}