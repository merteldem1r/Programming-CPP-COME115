# Midterm Preparation – Answer Key

> Solve [questions.md](questions.md) first. Every output below was verified by compiling and running the code.

---

## Part A – Predict the Output

### Question 1 – Scope, Pass-by-Value and `static`

```
3 8 3
6 3
15 20 3
11 21 31
```

| Line | Why |
|---|---|
| `3 8 3` | The local `x = 3` **hides** the global `x`. The inner `{ }` block creates a *new* `x = 7` → `8`, which disappears when the block ends, so the outer `x` is still `3`. |
| `6 3` | `change` receives a **copy** of `x` (pass-by-value). It prints `6`, but `main`'s `x` stays `3`. |
| `15 20 3` | `useGlobal` has no local `x`, so it changes the **global** `x`: `10 → 15 → 20`. But `main` prints its **local** `x`, which is still `3`. |
| `11 21 31` | `static int count` is initialised **once** and keeps its value between calls (1, 2, 3). `calls` is a normal local, so it is reset to 0 → 1 on every call. |

---

### Question 2 – Operator Traps

```
6 3 10 6
1.00 1.50 1.00
6.0 7.0
2 -2
C 67
B C 2 5
10
```

| Line | Why |
|---|---|
| `6 3 10 6` | `c = a++ * 2` uses the **old** `a` (5) → `c = 10`, then `a = 6`. `d = ++b * 2` increments **first** → `b = 3`, `d = 6`. |
| `1.00 1.50 1.00` | `a / 4` = `6 / 4` is **integer division** → `1`, then stored as `1.00`. `(double)a / 4` converts **before** dividing → `1.50`. `(double)(a / 4)` divides first (→ `1`) and converts after → `1.00`. |
| `6.0 7.0` | Evaluated left to right: `7 / 2` = `3` (int!) then `* 2.0` = `6.0`. In the second one `7 * 2.0` = `14.0` (double) then `/ 2` = `7.0`. |
| `2 -2` | In C the result of `%` has the **sign of the left operand**: `-17 % 5` = `-2`. |
| `C 67` | `'A'` is 65 → `65 + 2 = 67` = `'C'`. `%c` prints the character, `%d` prints the code. |
| `B C 2 5` | `x++ > 0` compares the old value `0 > 0` (false), then `x = 1`. Because `&&` already knows the result is false, `y++` is **never executed** (short-circuit) → `B`. Next: `x++ > 0` → `1 > 0` true, `x = 2`. `\|\|` already knows the result is true, so `y++` is skipped again → `C`. `y` stays `5`. |
| `10` | `x > y` → `2 > 5` is false, so the `?:` picks `y * 2` = `10`. |

---

### Question 3 – Bitwise and Logical Operators

```
8 14 6
48 5
0
0 2 0
1 0
1
```

| Line | Why |
|---|---|
| `8 14 6` | `1100 & 1010 = 1000` (8), `1100 \| 1010 = 1110` (14), `1100 ^ 1010 = 0110` (6). |
| `48 5` | `<< 2` multiplies by 4: `12 * 4 = 48`. `>> 1` divides by 2: `10 / 2 = 5`. |
| `0` | **Precedence trap:** `==` binds tighter than `&`, so it is `a & (b == 8)` = `12 & 0` = `0`. To get `1` you need `(a & b) == 8`. |
| `0 2 0` | `x = 2 > 3` → `0`. `y = !0 + (3 == 3)` → `1 + 1 = 2`. `z = x \|\| y && !z` → `&&` before `\|\|`: `0 \|\| (2 && !3)` = `0 \|\| (2 && 0)` = `0`. |
| `1 0` | `5 = 101`. `n & 1` is the last bit → `1` (this is how you test for odd numbers with bitwise). `(5 >> 1) = 10` → last bit `0`. |
| `1` | Arithmetic → relational → equality: `(3 + 4) > 6` → `1`, then `1 == 1` → `1`. |

Precedence to remember (high → low): `!` `++` `--` → `* / %` → `+ -` → `<< >>` → `< <= > >=` → `== !=` → `&` → `^` → `|` → `&&` → `||` → `?:` → `=`

---

### Question 4 – `switch` Fall-Through

```
Excellent Good | Good | Pass Weak | Unknown Pass Weak | Fail | Unknown Pass Weak | 
```

| Call | Why |
|---|---|
| `'A'` | Starts at `case 'A'`, no `break` → falls into `case 'B'` → `break`. |
| `'B'` | `Good`, then `break`. |
| `'C'` | `Pass`, falls into `case 'D'` → `Weak`, `break`. |
| `'X'` | No match → jumps to `default`. `default` is in the middle, so it falls through `case 'C'` and `case 'D'` until the `break`. |
| `'F'` | `Fail`. It is the last case, so it ends without a `break`. |
| `'a'` | `'a'` (97) is **not** `'A'` (65) → `default` again. |

Key idea: the **position** of `default` does not change *when* it is chosen (only if nothing matches), but it does change *where execution continues* after it.

---

### Question 5 – Loops

```
1 2 4 5 7 
total=19 i=8
10 k=6
(0,10) (3,8) i=6 j=6
n=6
```

| Part | Why |
|---|---|
| first loop | `3` and `6` are skipped by `continue`. At `i = 8`: `64 > 50` → `break`. `9` and `10` are never reached. `total = 1 + 2 + 4 + 5 + 7 = 19`. After `break` the `i++` does **not** run, so `i = 8`. |
| `do-while` | The body runs **once** before the condition is checked: prints `10`, `k = 6`, then `6 > 10` is false. |
| comma `for` | `(0,10)` → `i=3, j=8` → `(3,8)` → `i=6, j=6` → `6 < 6` is false. |
| `while` | `n`: `0 → 2 → 4 → 6`. The check happens before adding, so it overshoots to `6`. |

---

### Question 6 – Recursion

```
5 3 1 * 10 30 50 
11
5 15
```

**`f(5)`** – the code **before** the recursive call runs on the way *down*, the code **after** it runs on the way *back up* (in reverse order):
```
f(5): print 5  → f(3): print 3  → f(1): print 1  → f(-1): print *
                                    f(1): print 10
                  f(3): print 30
f(5): print 50
```

**`g(123)`** = `3 + 2 * g(12)` = `3 + 2 * (2 + 2 * g(1))` = `3 + 2 * (2 + 2 * 1)` = `3 + 2 * 4` = `11`.
(Each digit gets multiplied by a power of 2: `1·4 + 2·2 + 3·1`.)

**`fib(5)`** returns `5`, with **15** calls:
```
                         fib(5)
                /                     \
           fib(4)                      fib(3)
          /      \                    /      \
      fib(3)     fib(2)           fib(2)    fib(1)
      /    \     /    \           /    \
  fib(2) fib(1) fib(1) fib(0)  fib(1) fib(0)
  /    \
fib(1) fib(0)
```

**c)** `calls(n) = calls(n-1) + calls(n-2) + 1`, with `calls(0) = calls(1) = 1`:
`1, 1, 3, 5, 9, 15, 25` → **`fib(6)` makes 25 calls.**

> Why is `r` stored before the `printf`? In `printf("%d %d", fib(5), calls)` C does **not** guarantee which argument is evaluated first, so `calls` might be printed as `0`. Storing the result first avoids that.

---

## Part B – Count Line Executions

### Question 7

```
count = 7
steps = 7
```

| # | Expression / line | Executions | Why |
|---|---|---|---|
| 1 | `i <= 4` | **5** | true for i = 1, 2, 3, 4, false once at i = 5 |
| 2 | `i++` | **4** | once after each outer iteration |
| 3 | `j <= 4` | **14** | for each `i` the inner check runs `(5 − i) + 1` times: 5 + 4 + 3 + 2 |
| 4 | `j++` | **10** | equal to the number of inner iterations: 4 + 3 + 2 + 1 |
| 5 | `if ((i + j) % 3 == 0)` | **10** | once per inner iteration |
| 6 | `continue;` | **3** | pairs with `i + j` divisible by 3: (1,2), (2,4), (3,3) |
| 7 | `count++;` | **7** | 10 − 3 |
| 8 | `n != 1` | **8** | true 7 times, false once |
| 9 | `n /= 2;` | **6** | even values: 20, 10, 16, 8, 4, 2 |
| 10 | `n = 3 * n + 1;` | **1** | odd value: 5 |

Sequence for `n`: `20 → 10 → 5 → 16 → 8 → 4 → 2 → 1` (7 steps).

Remember: `continue` in a `for` loop still runs the **increment** (`j++`), so `j++` is 10, not 7.

---

## Part C – Find the Bugs

### Question 8

| # | Line | Wrong | Correct | Type |
|---|---|---|---|---|
| 1 | 20 | `int rev;` | `int rev = 0;` | `rev` starts with a garbage value |
| 2 | 21 | `while (n > 0);` | `while (n > 0)` | the `;` is an empty loop body → **infinite loop** (n never changes) |
| 3 | 26 | no `return` | `return rev;` before `}` | an `int` function must return a value |
| 4 | 30 | `reverse(n) = n` | `reverse(n) == n` | `=` is assignment → **compile error** (cannot assign to a function result) |
| 5 | 38 | `i < n` | `i <= n` | the last term `1/N` is missing |
| 6 | 39 | `1 / i` | `1.0 / i` | integer division: `1 / 2 = 0`, so the sum is always `1` |
| 7 | 47 | `scanf("%d", N)` | `scanf("%d", &N)` | `scanf` needs the **address** → crash |
| 8 | 51 | `%d` | `%.4f` | `%d` with a `double` prints garbage |

Fixed program:

```c
#include <stdio.h>

int reverse(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

int isPalindrome(int n)
{
    if (reverse(n) == n)
        return 1;
    return 0;
}

double seriesSum(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += 1.0 / i;
    return sum;
}

int main(void)
{
    int N, count = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        if (isPalindrome(i))
            count++;
    printf("Series sum: %.4f\n", seriesSum(N));
    printf("Palindromes: %d\n", count);
    return 0;
}
```

For `N = 20`: palindromes are `1 … 9` and `11` → **10**.

---

## Part D – Complete the Functions

### Question 9 – Digit Functions

```c
int digitSum(int n)
{
    if (n < 10)
        return n;
    return n % 10 + digitSum(n / 10);
}

int countDigit(int n, int d)
{
    if (n == 0)
        return 0;
    return (n % 10 == d) + countDigit(n / 10, d);
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
```

Notes:
- `(n % 10 == d)` is `1` or `0`, so it can be added directly — no `if` needed.
- `reverseNum(12340)` = `4321`: the leading zero of `04321` is lost, so `1230` is never a palindrome.
- Edge case: `countDigit(0, 0)` returns `0` with this solution, even though `0` contains one zero digit.

---

### Question 10 – Series

```c
double alternatingSeries(int n)
{
    double sum = 0;
    int sign = 1;
    for (int i = 1; i <= n; i++)
    {
        sum += sign * 1.0 / i;
        sign = -sign;
    }
    return sum;
}

double alternatingSeriesRec(int n)
{
    if (n == 0)
        return 0;
    double term = 1.0 / n;
    if (n % 2 == 0)
        term = -term;
    return term + alternatingSeriesRec(n - 1);
}

double eSeries(int n)
{
    double sum = 1, fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;          // i! built from (i-1)!, no second loop needed
        sum += 1.0 / fact;
    }
    return sum;
}

double squareSeries(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (double)i / (i * i + 1);
    return sum;
}
```

Notes:
- `1 / i` would be integer division → use `1.0 / i` or `(double)i / ...`.
- Using `int` for the factorial overflows after `12!`; using `double fact` avoids that.
- The alternating series approaches `ln 2 ≈ 0.693`, and `eSeries` approaches `e ≈ 2.718282`.

---

### Question 11 – Binary with Recursion

```c
void printBinary(int n)
{
    if (n > 1)
        printBinary(n / 2);
    printf("%d", n % 2);
}

int countOnes(int n)
{
    if (n == 0)
        return 0;
    return n % 2 + countOnes(n / 2);
}

int binaryToDecimal(int b)
{
    if (b == 0)
        return 0;
    return b % 10 + 2 * binaryToDecimal(b / 10);
}
```

Why `printBinary` prints in the right order: dividing by 2 gives the bits **from last to first** (`13 → 1, 0, 1, 1`).
By making the recursive call **before** `printf`, the deepest call (the first bit) prints first — the same "print on the way back" idea as `f` in Question 6.

`binaryToDecimal` is the same idea as `g` in Question 6: `1101` → `1·8 + 1·4 + 0·2 + 1·1 = 13`.

---

### Question 12 – Fibonacci Algorithms

```c
void printFib(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int fibRec(int n)
{
    if (n <= 1)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

int fibIter(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        int next = a + b;
        a = b;
        b = next;
    }
    return a;
}

int sumEvenFib(int limit)
{
    int a = 0, b = 1, sum = 0;
    while (a <= limit)
    {
        if (a % 2 == 0)
            sum += a;
        int next = a + b;
        a = b;
        b = next;
    }
    return sum;
}

int isFibonacci(int x)
{
    int a = 0, b = 1;
    while (a < x)
    {
        int next = a + b;
        a = b;
        b = next;
    }
    return a == x;
}

int digitCount(int n)
{
    int count = 1;
    while (n >= 10)
    {
        n /= 10;
        count++;
    }
    return count;
}

int firstFibWithDigits(int d)
{
    int i = 0;
    while (digitCount(fibIter(i)) < d)
        i++;
    return i;
}
```

Fixed ratio line:
```c
printf("ratio F(20)/F(19) = %f\n", (double)fibIter(20) / fibIter(19));
```

Answers:
1. `fibRec` recomputes the same values again and again (see the call tree in Question 6). The number of calls is `2·F(n+1) − 1`, so `fibRec(40)` makes **331,160,281 calls**. `fibIter(40)` runs its loop just **40 times**.
2. `6765 / 4181` with two `int`s is **integer division** → `1`. Cast one side to `double` **before** dividing and print it with `%f`.

Notes:
- `sumEvenFib(100)` = `0 + 2 + 8 + 34` = `44`.
- `isFibonacci` stops as soon as the sequence reaches or passes `x`, so it never loops forever.
- `firstFibWithDigits` could be faster by walking the sequence once instead of calling `fibIter(i)` each time — try it.
- An `int` overflows after `F(46)`.

---

## Part E – Write the Program

### Question 13 – `rand()`

1. **No `srand`:** the generator uses a default seed (1), so the program produces the **same "random" numbers on every run**.
2. **`srand(time(NULL))` inside a fast loop:** `time(NULL)` changes only once per second, so the generator is reset to the **same seed** many times → you get the **same number repeatedly**. Call `srand` once at the start of `main`.
3. `rand() % 31` gives `0 … 30`, `+ 20` → **`20 … 50`** (31 possible values). General formula: `rand() % (max - min + 1) + min`.

Includes needed: `#include <stdlib.h>` (`rand`, `srand`) and `#include <time.h>` (`time`).

One possible solution (guessing game):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char again = 'y';
    srand(time(NULL));

    do
    {
        int secret = rand() % 100 + 1;
        int guess = 0, attempts = 0, found = 0;

        printf("\nI picked a number between 1 and 100. You have 7 attempts.\n");
        while (attempts < 7 && !found)
        {
            printf("Guess #%d: ", attempts + 1);
            if (scanf("%d", &guess) != 1)
                return 0;
            attempts++;

            if (guess == secret)
                found = 1;
            else if (guess < secret)
                printf("Higher\n");
            else
                printf("Lower\n");
        }

        if (found)
            printf("Correct! Found in %d attempts.\n", attempts);
        else
            printf("Out of attempts. The number was %d.\n", secret);

        printf("Play again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}
```

Why 7 attempts: halving 1–100 each time (50, 25, …) always finds the number in at most 7 guesses, because 2⁷ = 128 ≥ 100.
Note the space in `" %c"` — it skips the Enter left over from the previous `scanf`.

---

### Question 14 – Star Shapes

```c
#include <stdio.h>

void pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s < n - i; s++)
            printf(" ");
        for (int k = 0; k < 2 * i - 1; k++)
            printf("*");
        printf("\n");
    }
}

void diamond(int n)
{
    pyramid(n);
    for (int i = n - 1; i >= 1; i--)
    {
        for (int s = 0; s < n - i; s++)
            printf(" ");
        for (int k = 0; k < 2 * i - 1; k++)
            printf("*");
        printf("\n");
    }
}

void hollowSquare(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void numberTriangle(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", k++);
        printf("\n");
    }
}

int main(void)
{
    int n = 4;
    printf("pyramid(%d):\n", n);
    pyramid(n);
    printf("\ndiamond(%d):\n", n);
    diamond(n);
    printf("\nhollowSquare(%d):\n", n);
    hollowSquare(n);
    printf("\nnumberTriangle(%d):\n", n);
    numberTriangle(n);
    return 0;
}
```

The pattern to remember: for row `i`, write down **how many spaces** and **how many stars** it has as a formula in `i` and `n`:

| Row `i` (n = 4) | Spaces `n − i` | Stars `2i − 1` |
|---|---|---|
| 1 | 3 | 1 |
| 2 | 2 | 3 |
| 3 | 1 | 5 |
| 4 | 0 | 7 |

The diamond is the pyramid followed by the same rows in reverse (without repeating the middle row).

---

### Question 15 – Number Analysis Menu

```c
#include <stdio.h>

int digitCount(int n)
{
    if (n < 10)
        return 1;
    return 1 + digitCount(n / 10);
}

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int isArmstrong(int n)
{
    int digits = digitCount(n), sum = 0, temp = n;
    while (temp > 0)
    {
        sum += power(temp % 10, digits);
        temp /= 10;
    }
    return sum == n;
}

int isPerfect(int n)
{
    if (n < 2)
        return 0;
    int sum = 1;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            sum += i;
    return sum == n;
}

int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main(void)
{
    int choice = 0, n = 0;

    do
    {
        printf("\n1. Digit count\n2. Armstrong?\n3. Perfect?\n4. Prime?\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            return 0;

        if (choice == 0)
        {
            printf("Bye\n");
            break;
        }
        if (choice < 0 || choice > 4)
        {
            printf("Invalid choice!\n");
            continue;
        }

        printf("Number (positive): ");
        if (scanf("%d", &n) != 1)
            return 0;
        if (n <= 0)
        {
            printf("Enter a positive number!\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("%d has %d digits\n", n, digitCount(n));
            break;
        case 2:
            printf("%d is %sArmstrong\n", n, isArmstrong(n) ? "" : "not ");
            break;
        case 3:
            printf("%d is %sperfect\n", n, isPerfect(n) ? "" : "not ");
            break;
        case 4:
            printf("%d is %sprime\n", n, isPrime(n) ? "" : "not ");
            break;
        }
    } while (1);

    return 0;
}
```

Notes:
- `continue` inside a `do-while` jumps to the **condition** check (`while (1)`), so the menu is shown again.
- `isArmstrong` must use the **number of digits** as the exponent: `153 → 3` digits → `1³ + 5³ + 3³ = 153`. `9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴` is a 4-digit example.
- `isPerfect` only needs to check divisors up to `n / 2` — no divisor except `n` itself is bigger.
- Test values: perfect `6, 28, 496`; Armstrong `153, 370, 371, 407`; prime `2, 97`; not prime `1, 49`.
