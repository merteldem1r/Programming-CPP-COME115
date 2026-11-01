/*
 * Midterm Prep - Q12: Fibonacci Algorithms
 * Topic: loops, recursion, algorithms
 *
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)  ->  0 1 1 2 3 5 8 13 21 34 ...
 *
 * Complete the functions. main is already written.
 *   void printFib(int n)            print the first n terms (loop)
 *   int fibRec(int n)               n-th term, RECURSIVE
 *   int fibIter(int n)              n-th term, LOOP
 *   int sumEvenFib(int limit)       sum of the even terms <= limit
 *   int isFibonacci(int x)          1 if x is a Fibonacci number, else 0
 *   int firstFibWithDigits(int d)   index of the first term with d digits
 *                                   (you may add your own helper functions)
 *
 * Expected output:
 *   printFib(10): 0 1 1 2 3 5 8 13 21 34
 *   fibRec(10)  = 55
 *   fibIter(30) = 832040
 *   sumEvenFib(100) = 44
 *   isFibonacci(21) = 1, isFibonacci(22) = 0, isFibonacci(0) = 1
 *   firstFibWithDigits(3) = 12 (F(12) = 144)
 *   ratio F(20)/F(19) = 1.618034
 *
 * After it works, answer in the comment at the bottom of the file.
 */

#include <stdio.h>

void printFib(int n)
{
    int prev = 0, next = 1, temp = 0;
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", prev);
        temp = next;
        next = prev + next;
        prev = temp;
    }
    printf("\n");
}

int fibRec(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibRec(n - 1) + fibRec(n - 2);
}

int fibIter(int n)
{
    int prev = 0, next = 1, temp = 0;

    // after i steps, prev holds F(i)
    for (int i = 0; i < n; ++i)
    {
        temp = next;
        next = prev + next;
        prev = temp;
    }

    return prev;
}

int sumEvenFib(int limit)
{
    int prev = 0, next = 1, temp = 0, sum = 0;

    while (prev <= limit)
    {
        if (prev % 2 == 0)
        {
            sum += prev;
        }

        temp = next;
        next = prev + next;
        prev = temp;
    }

    return sum;
}

int isFibonacci(int x)
{
    int prev = 0, next = 1, temp = 0;

    // walk the sequence until it reaches or passes x
    while (prev < x)
    {
        temp = next;
        next = prev + next;
        prev = temp;
    }

    return prev == x;
}

int digitCount(int n)
{
    int count = 1;

    while (n >= 10)
    {
        n /= 10;
        ++count;
    }

    return count;
}

int firstFibWithDigits(int d)
{
    int prev = 0, next = 1, temp = 0, i = 0;

    // walk the sequence once, counting the index
    while (digitCount(prev) < d)
    {
        temp = next;
        next = prev + next;
        prev = temp;
        ++i;
    }

    return i;
}

int main(void)
{
    printf("printFib(10): ");
    printFib(10);
    printf("fibRec(10)  = %d\n", fibRec(10));
    printf("fibIter(30) = %d\n", fibIter(30));
    printf("sumEvenFib(100) = %d\n", sumEvenFib(100));
    printf("isFibonacci(21) = %d, isFibonacci(22) = %d, isFibonacci(0) = %d\n",
           isFibonacci(21), isFibonacci(22), isFibonacci(0));
    int idx = firstFibWithDigits(3);
    printf("firstFibWithDigits(3) = %d (F(%d) = %d)\n", idx, idx, fibIter(idx));
    // cast BEFORE dividing, otherwise it is integer division (6765 / 4181 = 1)
    printf("ratio F(20)/F(19) = %f\n", (double)fibIter(20) / fibIter(19));
    return 0;
}

/*
 * 1. Why is fibRec(40) much slower than fibIter(40)?
 *    fibRec calls itself twice per step and recomputes the same values
 *    again and again (fibRec(38) is computed 2 times, fibRec(37) 3 times, ...).
 *    The number of calls is 2 * F(n+1) - 1, so fibRec(40) makes
 *    331,160,281 calls. fibIter(40) only runs its loop 40 times.
 *
 * 2. Why did fibIter(20) / fibIter(19) print 1, and how did you fix it?
 *    Both are int, so 6765 / 4181 is integer division -> 1 (the .618 is cut off).
 *    Fix: cast one side to double BEFORE dividing and print with %f:
 *    (double)fibIter(20) / fibIter(19) -> 1.618034
 */
