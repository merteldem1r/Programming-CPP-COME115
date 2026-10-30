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

int main(void)
{
    int guess, secret = 37, attempts = 0;

    while (1)
    {
        printf("Enter a number to guess: ");

        int rc = scanf("%d", &guess);
        if (rc == EOF)
        {
            // input ended (Ctrl+D), stop instead of looping forever
            printf("\nNo more input. Exiting...\n");
            break;
        }
        if (rc != 1)
        {
            // if not integer, discard characters until it reaches the newline
            printf("Invalid input! Please enter an integer.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            continue;
        }

        attempts++;

        if (guess == secret)
        {
            printf("Correct guess! Attempts: %d\n", attempts);
            break;
        }
        else if (guess < secret)
            printf("Go higher\n");
        else
            printf("Go lower\n");
    }

    return 0;
}
