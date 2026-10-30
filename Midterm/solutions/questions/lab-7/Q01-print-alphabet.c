/*
 * Lab 7 - Q1: Print the Alphabet
 * Topic: loops with char variables
 *
 * Write a program that prints only the uppercase letters (A ... Z).
 * Then print only the lowercase letters (a ... z).
 *
 * Expected output:
 *   Uppercase letters
 *   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 *   Lowercase letters
 *   a b c d e f g h i j k l m n o p q r s t u v w x y z
 */

#include <stdio.h>

int main(void)
{
    // uppercase
    for (char c = 'A'; c <= 'Z'; ++c)
    {
        printf("%c ", c);
    }
    printf("\n");

    // lowercase
    for (char c = 'a'; c <= 'z'; ++c)
    {
        printf("%c ", c);
    }
}