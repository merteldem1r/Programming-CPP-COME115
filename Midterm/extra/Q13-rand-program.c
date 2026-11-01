/*
 * Midterm Prep - Q13: rand() - Your Own Program
 * Topic: rand(), srand(), time(), loops, functions
 *
 * Design and write your own program that uses random numbers.
 * Requirements:
 *   1. srand(time(NULL)) is called ONCE (not inside a loop).
 *   2. At least one range that does not start at 0 or 1,
 *      using rand() % (max - min + 1) + min   (e.g. 20-50).
 *   3. Use a loop and at least one function.
 *   4. If you read input, validate it with the return value of scanf.
 *
 * Ideas: guessing game with limited attempts + "play again?",
 *        dice simulation counting each sum, math quiz with score,
 *        random password / PIN generator.
 *
 * Answer here:
 *   1. What happens if you do not call srand at all?
 *
 *   2. What happens if srand(time(NULL)) is called inside a loop
 *      that runs many times per second?
 *
 *   3. What range does rand() % 31 + 20 produce?
 *
 * My program:
 *
 */
