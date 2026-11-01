/*
 * Midterm Prep - Q10: Series
 * Topic: loops, recursion, double, integer division traps
 *
 * Complete the functions. main is already written.
 *   double alternatingSeries(int n)     LOOP:      1 - 1/2 + 1/3 - 1/4 + ... +- 1/n
 *   double alternatingSeriesRec(int n)  RECURSIVE: the same series, no loop
 *   double eSeries(int n)               1 + 1/1! + 1/2! + ... + 1/n!
 *                                       (one loop, no separate factorial function)
 *   double squareSeries(int n)          1/2 + 2/5 + 3/10 + ... + n/(n*n + 1)
 *
 * Expected output:
 *   alternatingSeries(10)    = 0.645635
 *   alternatingSeriesRec(10) = 0.645635
 *   eSeries(10)              = 2.718282
 *   squareSeries(5)          = 1.627602
 */

#include <stdio.h>

double alternatingSeries(int n)
{
    int sign = -1;
    double res = 1;

    for (int i = 2; i <= n; ++i)
    {
        res += (double)sign * (1.0 / i);
        sign *= -1;
    }

    return res;
}

double alternatingSeriesRec(int n)
{
    if (n == 0)
    {
        return 0;
    }

    // odd terms are +, even terms are -
    double term = 1.0 / n;
    if (n % 2 == 0)
    {
        term = -term;
    }

    return term + alternatingSeriesRec(n - 1);
}

double eSeries(int n)
{
    double res = 1;
    double fact = 1;

    for (int i = 1; i <= n; ++i)
    {
        fact *= i; // i! = (i-1)! * i, built from the previous step
        res += 1.0 / fact;
    }

    return res;
}

double squareSeries(int n)
{
    double res = 0;

    for (int i = 1; i <= n; ++i)
    {
        res += (double)i / (i * i + 1);
    }

    return res;
}

int main(void)
{
    printf("alternatingSeries(10)    = %.6f\n", alternatingSeries(10));
    printf("alternatingSeriesRec(10) = %.6f\n", alternatingSeriesRec(10));
    printf("eSeries(10)              = %.6f\n", eSeries(10));
    printf("squareSeries(5)          = %.6f\n", squareSeries(5));
    return 0;
}
