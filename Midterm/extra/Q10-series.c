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
    // ...
}

double alternatingSeriesRec(int n)
{
    // ...
}

double eSeries(int n)
{
    // ...
}

double squareSeries(int n)
{
    // ...
}

int main(void)
{
    printf("alternatingSeries(10)    = %.6f\n", alternatingSeries(10));
    printf("alternatingSeriesRec(10) = %.6f\n", alternatingSeriesRec(10));
    printf("eSeries(10)              = %.6f\n", eSeries(10));
    printf("squareSeries(5)          = %.6f\n", squareSeries(5));
    return 0;
}
