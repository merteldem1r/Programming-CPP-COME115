/*
 * Lab 6 - Q2: Day of the Week
 * Topic: switch-case
 *
 * Read a number between 1 and 7 from the keyboard and print which day
 * of the week it corresponds to (1 = Monday ... 7 = Sunday).
 * Print an "invalid" message for any other number.
 *
 * Think about it: if you remove all the break statements and the user
 * enters 5, what is printed? Why isn't "case 6" checked again?
 */

#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter the character: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Not a day");
        break;
    }

    return 0;
}