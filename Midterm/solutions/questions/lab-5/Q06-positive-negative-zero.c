/*
 * Lab 5 - Q6: Positive, Negative or Zero
 * Topic: if - else if - else
 *
 * Read an integer from the user and print whether it is positive,
 * negative or zero.
 */

#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter num: ");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("Positive");
    }
    else if (num < 0)
    {
        printf("Negative");
    }
    else
    {
        printf("Zero");
    }

    return 0;
}
