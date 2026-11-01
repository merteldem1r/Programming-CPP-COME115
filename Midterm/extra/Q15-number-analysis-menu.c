/*
 * Midterm Prep - Q15: Number Analysis Menu
 * Topic: functions, recursion, do-while menu, switch, input validation
 *
 * Write a menu program that repeats with do-while until the user chooses 0:
 *   1. Digit count  -> RECURSIVE int digitCount(int n)   12345 -> 5
 *   2. Armstrong?   -> int isArmstrong(int n)            153 = 1^3 + 5^3 + 3^3 -> yes
 *   3. Perfect?     -> int isPerfect(int n)              28 = 1 + 2 + 4 + 7 + 14 -> yes
 *   4. Prime?       -> int isPrime(int n)                97 -> yes
 *   0. Exit
 *
 * Rules:
 *   - Each check is its own function.
 *   - Do NOT use pow(); write your own int power(int base, int exp).
 *   - An invalid menu choice prints an error and shows the menu again.
 *   - Negative numbers and 0 are rejected.
 *   - Typing a letter must not cause an infinite loop.
 */
