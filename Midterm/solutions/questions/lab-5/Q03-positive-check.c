/*
 * Lab 5 - Q3: Positive Number Check
 * Topic: if
 *
 * Read an integer from the user. If the number is greater than zero,
 * print "Pozitif sayi girdiniz."
 *
 * Example:
 *   Input:  12
 *   Output: Pozitif sayi girdiniz.
 *
 * Think about it: why is nothing printed when a negative number is entered?
 */

#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter the number: ");
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
