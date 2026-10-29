/*
 * Lab 6 - Q1a: Is the Character a Letter? (normal if)
 * Topic: if-else, logical operators (&&, ||), char comparison
 *
 * Read a single character from the keyboard and check whether it is
 * a letter (A-Z or a-z). Print whether it is a letter or not.
 *
 * Solve it with a single (non-nested) if-else, combining the
 * conditions with && and ||.
 */

#include <stdio.h>

int main(void)
{
    char c = 'a';
    printf("Enter the character: ");
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        printf("Character");
    }
    else
    {
        printf("Not Character");
    }

    return 0;
}