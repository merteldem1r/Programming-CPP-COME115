/*
 * Lab 7 - Q5: Circle Area with Functions
 * Topic: functions with one parameter (void / returning a value)
 *
 * Read the radius of a circle from the keyboard and print its area
 * (area = pi * r * r), by writing:
 *   a) a function with ONE parameter (the radius) that returns NO value
 *      -> it calculates and prints the area itself.
 *   b) a function with ONE parameter (the radius) that RETURNS the area
 *      -> main prints the returned value.
 */

#include <stdio.h>

#define PI 3.14159

// a) one parameter, no return value
void printCircleArea(double r)
{
    printf("Area from a: %.2f\n", PI * r * r);
}

// b) one parameter, returns the area
double circleArea(double r)
{
    return PI * r * r;
}

int main(void)
{
    double r = 0;
    printf("Enter the radius: ");
    scanf("%lf", &r);

    printCircleArea(r);
    printf("Area from b: %.2f\n", circleArea(r));

    return 0;
}
