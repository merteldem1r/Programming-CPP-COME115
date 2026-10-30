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

double tempConversation(double temp, int op)
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

    default:
        break;
    }

    return ans;
}

int main(void)
{
    int temp = 0, op = 0;

    do
    {
        printf("Enter temperature: ");
        scanf("%d", &temp);
        printf("Pick conversation type \t 1. C -> F \t 2. F -> C \t 3. Exit \n");
        scanf("%d", &op);

        double ans = tempConversation(temp, op);

        if (op == 3)
        {
            printf("Exit...");
            break;
        }
        printf("Answer: %.2f\n", ans);

    } while (op != 3);

    return 0;
}