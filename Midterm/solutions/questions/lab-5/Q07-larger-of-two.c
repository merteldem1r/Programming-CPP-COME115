/*
 * Lab 5 - Q7: Larger of Two Numbers
 * Topic: multiple conditions
 *
 * Read two integers and print the larger one.
 * If the two numbers are equal, print that they are equal.
 */

#include <stdio.h>

int main(void)
{
    int n1 = 0, n2 = 0;
    printf("Enter num1: ");
    scanf("%d", &n1);

    printf("Enter num2: ");
    scanf("%d", &n2);

    if (n1 > n2)
    {
        printf("Larger: %d", n1);
    }
    else if (n2 > n1)
    {
        printf("Larger: %d", n2);
    }
    else
    {
        printf("Equal");
    }

    return 0;
}
