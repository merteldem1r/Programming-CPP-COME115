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
    // ...
}

int fibRec(int n)
{
    // ...
}

int fibIter(int n)
{
    // ...
}

int sumEvenFib(int limit)
{
    // ...
}

int isFibonacci(int x)
{
    // ...
}

int firstFibWithDigits(int d)
{
    // ...
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
    // fix the line below so it prints 1.618034
    printf("ratio F(20)/F(19) = %d\n", fibIter(20) / fibIter(19));
    return 0;
}

/*
 * 1. Why is fibRec(40) much slower than fibIter(40)?
 *
 *
 * 2. Why did fibIter(20) / fibIter(19) print 1, and how did you fix it?
 *
 */
