/*
 * Lab 5 - Q10 (Practice, Hard): Menu-Based Calculator
 * Topic: switch-case, if
 *
 * Write a calculator that offers four operations. The user enters
 * two numbers and the operation code:
 *
 *   Code   Operation
 *   1      Addition
 *   2      Subtraction
 *   3      Multiplication
 *   4      Division
 *
 * Handle an invalid operation choice and division by zero.
 *
 * Try it: what happens if you remove the break under one of the cases?
 */

#include <stdio.h>

int main(void)
{
    double n1 = 0, n2 = 0;
    int op = 0;

    while (1)
    {
        printf("\nEnter num1: ");
        if (scanf("%lf", &n1) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return 0;
        }

        printf("Enter num2: ");
        if (scanf("%lf", &n2) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return 0;
        }

        printf("Enter operation (1-4): ");
        if (scanf("%d", &op) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return 0;
        }

        switch (op)
        {
        case 1:
            printf("Result: %.2f\n", n1 + n2);
            break;

        case 2:
            printf("Result: %.2f\n", n1 - n2);
            break;

        case 3:
            printf("Result: %.2f\n", n1 * n2);
            break;

        case 4:
            if (n2 != 0)
            {
                printf("Result: %.2f\n", n1 / n2);
            }
            else
            {
                printf("Cannot divide by zero!\n");
            }
            break;

        default:
            printf("Wrong operation!\n");
            return 0;
        }
    }

    return 0;
}