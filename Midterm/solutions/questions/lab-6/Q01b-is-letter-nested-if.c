/*
 * Lab 6 - Q1b: Is the Character a Letter? (nested if)
 * Topic: nested if
 *
 * Same task as Q1a: read a single character from the keyboard and
 * check whether it is a letter.
 *
 * This time use nested if-else, and print one of:
 *   - uppercase letter (A-Z)
 *   - lowercase letter (a-z)
 *   - not a letter
 *
 * Hint: in ASCII, 'A' = 65 and 'Z' = 90.
 */

#include <stdio.h>

int main(void)
{
    char c = 'a';
    printf("Enter the character: ");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z')
    {
        printf("uppercase");
    }
    else if (c >= 'a' && c <= 'z')
    {
        printf("lowecase");
    }
    else
    {
        printf("not letter");
    }

    return 0;
}
