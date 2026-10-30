/*
 * Lab 7 - Q2: Letter Right Triangle
 * Topic: nested loops, char arithmetic
 *
 * Print a right triangle made of consecutive letters, where each row
 * has one more letter than the previous row.
 *
 * Expected output (4 rows):
 *   A
 *   B C
 *   D E F
 *   G H I J
 */

#include <stdio.h>

int main(void)
{
    int rowCount = 0;
    printf("Enter the row count: ");
    scanf("%d", &rowCount);

    char c = 'A';
    // uppercase
    for (int i = 1; i <= rowCount; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (c <= 'Z')
                printf("%c ", c++);
        }
        printf("\n");

        if (c > 'Z')
        {
            printf("No more uppercase letters...");
            break;
        }
    }

    return 0;
}