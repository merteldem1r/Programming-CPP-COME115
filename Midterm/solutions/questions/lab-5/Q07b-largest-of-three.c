/*
 * Lab 5 - Q7b (Bonus): Largest of Three Numbers
 * Topic: multiple conditions
 *
 * Extension of Q7: read three integers and print the largest one.
 */

#include <stdio.h>

int main()
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    printf("Enter num: ");
    scanf("%d", &n1);

    printf("Enter num: ");
    scanf("%d", &n2);

    printf("Enter num: ");
    scanf("%d", &n3);

    if (n1 >= n2 && n1 >= n3)
    {
        printf("Largest %d", n1);
    }
    else if (n2 >= n1 && n2 >= n3)
    {
        printf("Largest %d", n2);
    }
    else
    {
        printf("Largest: %d", n3);
    }

    return 0;
}