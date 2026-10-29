/*
 * Lab 5 - Q1: Variable Types
 *
 * Declare variables of type char, int, float and double,
 * then print each of them to the screen with printf.
 */

#include <stdio.h>

int main(void)
{
    int a = 5;
    float b = 3.14;
    double c = 4.51245;

    char d = 'a';
    char str[] = "string";

    // Format Specifiers
    printf("int: %d\n", a);
    printf("float: %f\n", b);
    printf("double: %lf\n", c);
    printf("char: %c\n", d);
    printf("string: %s\n", str);

    return 0;
}
