/*
 * Midterm Prep - Q9: Digit Functions
 * Topic: recursion, % and /
 *
 * Complete the functions. main is already written.
 *   int digitSum(int n)          RECURSIVE  - sum of the digits
 *   int countDigit(int n, int d) RECURSIVE  - how many times digit d appears in n
 *   int reverseNum(int n)        LOOP       - reverse the digits
 *   int isPalindrome(int n)      uses reverseNum, returns 1 or 0
 *
 * Expected output:
 *   digitSum(9875)         = 29
 *   countDigit(1020304, 0) = 3
 *   countDigit(777, 7)     = 3
 *   reverseNum(12340)      = 4321
 *   isPalindrome(12321)    = 1
 *   isPalindrome(1230)     = 0
 */

#include <stdio.h>

int digitSum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + digitSum(n / 10);
}

int countDigit(int n, int d)
{
    if (n == 0)
        return 0;

    int isAppears = n % 10 == d;
    return isAppears + countDigit(n / 10, d);
}

int reverseNum(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev;
}

int isPalindrome(int n)
{
    return reverseNum(n) == n;
}

int main(void)
{
    printf("digitSum(9875)         = %d\n", digitSum(9875));
    printf("countDigit(1020304, 0) = %d\n", countDigit(1020304, 0));
    printf("countDigit(777, 7)     = %d\n", countDigit(777, 7));
    printf("reverseNum(12340)      = %d\n", reverseNum(12340));
    printf("isPalindrome(12321)    = %d\n", isPalindrome(12321));
    printf("isPalindrome(1230)     = %d\n", isPalindrome(1230));
    return 0;
}
