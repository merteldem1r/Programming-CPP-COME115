/*
 * Lab 5 - Q2: Star Triangles
 *
 * Print the following two shapes to the screen, in this order.
 *
 * Shape 1 (left-aligned, decreasing):
 *   ******
 *   *****
 *   ****
 *   ***
 *   **
 *   *
 *
 * Shape 2 (right-aligned, increasing):
 *        *
 *       **
 *      ***
 *     ****
 *    *****
 *   ******
 */

#include <stdio.h>

int main(void)
{
    // shape 1
    for (int r = 0; r < 6; ++r)
    {
        for (int c = 6 - r; c > 0; --c)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    // shape 2
    for (int r = 0; r < 6; ++r)
    {
        for (int s = 0; s < 5 - r; ++s)
        {
            printf(" ");
        }

        for (int c = 0; c <= r; ++c)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
