/*
 * Lab 5 - Q8: Letter Grade
 * Topic: condition ranges, ||
 *
 * Read a grade between 0 and 100 from the user and print the letter grade
 * using the table below. For any value outside 0-100, print "Gecersiz not!"
 *
 *   Grade range   Letter
 *   90 - 100      AA
 *   80 - 89       BA
 *   70 - 79       BB
 *   60 - 69       CB
 *   50 - 59       CC
 *   0  - 49       FF
 *
 * Think about it: in "else if (grade >= 80)", why don't we also need
 * to check grade < 90?
 */

#include <stdio.h>

int main(void)
{
    int g = 0;
    printf("Enter grade: ");
    scanf("%d", &g);

    if (g < 0 || g > 100)
    {
        printf("Wrong grade");
        return 0;
    }

    if (g >= 90)
    {
        printf("AA");
    }
    else if (g >= 80)
    {
        printf("BA");
    }
    else if (g >= 70)
    {
        printf("BB");
    }
    else if (g >= 60)
    {
        printf("CB");
    }
    else if (g >= 50)
    {
        printf("CC");
    }
    else
    {
        printf("FF");
    }

    return 0;
}
