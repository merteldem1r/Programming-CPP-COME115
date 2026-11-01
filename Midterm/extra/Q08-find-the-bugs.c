/*
 * Midterm Prep - Q8: Find the Bugs
 *
 * The program reads N and should print:
 *   - the sum of the series S = 1 + 1/2 + 1/3 + ... + 1/N (4 decimal places)
 *   - how many palindrome numbers are between 1 and N
 *
 * There are 8 bugs. First find them on paper (line + reason + fix),
 * then fix the code and run it.
 *
 * Expected output for N = 20:
 *   Series sum: 3.5977
 *   Palindromes: 10
 */

#include <stdio.h>

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    return rev;
}

int isPalindrome(int n)
{
    if (reverse(n) == n)
        return 1;
    return 0;
}

double seriesSum(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (double)1 / i;
    return sum;
}

int main(void)
{
    int N = 0, count = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        if (isPalindrome(i))
            count++;
    printf("Series sum: %.4f\n", seriesSum(N));
    printf("Palindromes: %d\n", count);
    return 0;
}
