/*
 * Lab 5 - Q9 (Practice): ATM Withdrawal
 * Topic: nested if
 *
 * An ATM account starts with a balance of 5000 TL. Let the user withdraw
 * the amount they enter. Rules:
 *   - The amount must be greater than zero.
 *   - The amount cannot be more than the current balance.
 *   - The amount must be a multiple of 100 TL.
 *   - After a successful withdrawal, display the remaining balance.
 *
 * Test cases:
 *   Amount     Expected result            Remaining balance
 *   1200 TL    Success                    3800 TL
 *   6000 TL    Insufficient balance       5000 TL
 *   250 TL     Not a multiple of 100      5000 TL
 *   -100 TL    Invalid amount             5000 TL
 */
