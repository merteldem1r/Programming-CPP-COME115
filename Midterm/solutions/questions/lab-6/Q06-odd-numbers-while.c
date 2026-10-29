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
    int num = 0, i = 1;
    printf("Enter a num: ");
    scanf("%d", &num);

    while (i <= num)
    {
        printf("%d ", i);
        i += 2;
    }

    return 0;
}