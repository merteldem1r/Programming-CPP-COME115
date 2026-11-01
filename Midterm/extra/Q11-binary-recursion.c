/*
 * Midterm Prep - Q11: Binary with Recursion
 * Topic: recursion, % 2 and / 2
 *
 * Complete the functions (all RECURSIVE, no loops, no arrays). main is already written.
 *   void printBinary(int n)      print n in binary in the correct order (13 -> 1101)
 *   int countOnes(int n)         number of 1 bits (13 -> 3)
 *   int binaryToDecimal(int b)   b is written with digits 0/1 (1101 -> 13)
 *
 * Expected output:
 *   13 -> 1101
 *   0  -> 0
 *   64 -> 1000000
 *   countOnes(13)  = 3
 *   countOnes(255) = 8
 *   binaryToDecimal(1101)   = 13
 *   binaryToDecimal(100000) = 32
 */

#include <stdio.h>

void printBinary(int n)
{
    // ...
}

int countOnes(int n)
{
    // ...
}

int binaryToDecimal(int b)
{
    // ...
}

int main(void)
{
    printf("13 -> "); printBinary(13); printf("\n");
    printf("0  -> "); printBinary(0); printf("\n");
    printf("64 -> "); printBinary(64); printf("\n");
    printf("countOnes(13)  = %d\n", countOnes(13));
    printf("countOnes(255) = %d\n", countOnes(255));
    printf("binaryToDecimal(1101)   = %d\n", binaryToDecimal(1101));
    printf("binaryToDecimal(100000) = %d\n", binaryToDecimal(100000));
    return 0;
}
