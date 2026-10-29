/*
 * Lab 6 - Q7: Star Right Triangle
 * Topic: nested for loops
 *
 * Read the number of rows from the user and print a right triangle
 * of stars with that many rows.
 *
 * Example (rows = 3):
 *   *
 *   **
 *   ***
 */

#include <stdio.h>

int main(void)
{
    int r = 0;
    printf("Enter a row count: ");
    scanf("%d", &r);

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
