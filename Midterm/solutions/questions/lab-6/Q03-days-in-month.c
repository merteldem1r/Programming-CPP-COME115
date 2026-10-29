/*
 * Lab 6 - Q3: Days in a Month
 * Topic: switch-case
 *
 * Read a number between 1 and 12 from the keyboard and print how many
 * days the corresponding month has (February: 28/29).
 * Print an "invalid" message for any other number.
 */

#include <stdio.h>

int main(void)
{
    int month = 0;
    printf("Enter a month (1-12): ");
    scanf("%d", &month);

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("31 days");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("30 days");
        break;
    case 2:
        printf("28/29 days");
        break;
    default:
        printf("Invalid month");
        break;
    }

    return 0;
}
