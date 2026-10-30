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

int main()
{
    int temp;

    printf("Enter a temperature: ");
    scanf("%d", &temp);

    printf("celsius To Fahrenheit: %.2f\n", celsiusToFahrenheit(temp));
    printf("fahrenheit To Celsius: %.2f", fahrenheitToCelsius(temp));
}
