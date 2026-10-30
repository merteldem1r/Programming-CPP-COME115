/*
 * Lab 7 - Q3: Temperature Conversion
 * Topic: menu, if-else / switch, do-while
 *
 * Ask the user for a temperature value and a conversion type:
 *   - Celsius -> Fahrenheit
 *   - Fahrenheit -> Celsius
 *   - (optional) Kelvin conversions as well
 * Print the converted temperature.
 *
 * Formula (from the PDF):
 *   (K - 273) / 100  =  (F - 32) / 180  =  C / 100
 *
 * Note: the PDF's answer uses a do-while menu that repeats until the
 * user chooses "Exit".
 */

#include <stdio.h>

double tempConversion(double temp, int op)
{
    double ans = 0;
    switch (op)
    {
    case 1:
        // C -> F
        ans = (temp / 100) * 180 + 32;
        break;
    case 2:
        // F -> C
        ans = (temp - 32) / 180 * 100;
        break;
    case 3:
        // C -> K
        ans = temp + 273;
        break;
    case 4:
        // K -> C
        ans = temp - 273;
        break;
    }

    return ans;
}

int main(void)
{
    double temp = 0;
    int op = 0;

    do
    {
        printf("\nPick conversion type\n");
        printf("1. C -> F\n2. F -> C\n3. C -> K\n4. K -> C\n5. Exit\n");
        if (scanf("%d", &op) != 1)
        {
            printf("Invalid input. Exiting...\n");
            return 0;
        }

        if (op == 5)
        {
            printf("Exit...\n");
        }
        else if (op < 1 || op > 5)
        {
            printf("Invalid choice!\n");
        }
        else
        {
            printf("Enter temperature: ");
            if (scanf("%lf", &temp) != 1)
            {
                printf("Invalid input. Exiting...\n");
                return 0;
            }
            printf("Answer: %.2f\n", tempConversion(temp, op));
        }

    } while (op != 5);

    return 0;
}
