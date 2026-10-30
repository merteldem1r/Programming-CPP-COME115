/*
 * Lab 7 - Q6: Temperature Conversion with Functions
 * Topic: functions with parameters and return values
 *
 * Redo Q3 (temperature conversion) using functions, e.g. one function
 * per conversion that takes a temperature and returns the converted value:
 *   celsiusToFahrenheit(c), fahrenheitToCelsius(f), ...
 *
 * Formulas:
 *   F = C * 9 / 5 + 32
 *   C = (F - 32) * 5 / 9
 *   K = C + 273
 */

#include <stdio.h>

double celsiusToFahrenheit(double c)
{
    return (c / 100) * 180 + 32;
}

double fahrenheitToCelsius(double f)
{
    return (f - 32) / 180 * 100;
}

int main(void)
{
    double temp = 0;
    int op = 0;

    printf("1. C -> F\n2. F -> C\nPick conversion type: ");
    scanf("%d", &op);

    printf("Enter a temperature: ");
    scanf("%lf", &temp);

    if (op == 1)
    {
        printf("Fahrenheit: %.2f\n", celsiusToFahrenheit(temp));
    }
    else if (op == 2)
    {
        printf("Celsius: %.2f\n", fahrenheitToCelsius(temp));
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
