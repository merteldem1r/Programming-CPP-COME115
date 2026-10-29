/*
 * Lab 5 - Q4: Age Check (Driver's License)
 * Topic: if-else
 *
 * Read the user's age. If the age is 18 or more, print that they meet
 * the age requirement for a driver's license; otherwise print that
 * they do not.
 *
 * Think about it: how would the behavior change if you wrote
 * age > 18 instead of age >= 18?
 */

#include <stdio.h>

int main(void)
{
    int age = 0;
    printf("Enter age: ");
    scanf("%d", &age);

    if (age <= 0)
    {
        printf("Wrong age");
        return 0;
    }

    if (age >= 18)
    {
        printf("Okay");
    }
    else
    {
        printf("Not okay mk");
    }

    return 0;
}