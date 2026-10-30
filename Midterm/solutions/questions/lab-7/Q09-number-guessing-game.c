/*
 * Lab 7 - Q9 (Practice, Medium): Number Guessing Game
 * Topic: while loop, if-else
 *
 * The program has a secret number, set to 37. Ask the user to guess it
 * and keep running until the guess is correct.
 *   - If the guess is smaller than the secret: "Daha buyuk bir sayi giriniz."
 *   - If the guess is larger than the secret:  "Daha kucuk bir sayi giriniz."
 *   - When the guess is correct, show how many attempts it took.
 */

#include <stdio.h>

int main()
{
    int num, guess = 37, attempts = 0;

    while (1)
    {
        printf("Enter a number to guess: ");

        if (scanf("%d", &num) != 1)
        {
            // if not integer want that and discard characters until it reaches the newline
            printf("Invalid input! Please enter an integer.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        attempts++;

        if (num == guess)
        {
            printf("Correct guess! Attempts: %d\n", attempts);
            break;
        }
        else if (num < guess)
            printf("Go higher\n");
        else
            printf("Go lower\n");
    }

    return 0;
}