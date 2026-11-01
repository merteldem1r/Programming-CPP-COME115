# Midterm Preparation – Practice Questions

15 questions based on labs 3–7, last year's midterm and the topics mentioned in class
(recursion: palindrome, Fibonacci, digit count, star shapes, series; plus `rand()`).
They are deliberately **harder than last year's exam**.

| Part | Questions | How to solve |
|---|---|---|
| A – Predict the output | 1–6 | On paper, **without compiling**. Then check with [answers.md](answers.md). |
| B – Count line executions | 7 | On paper. |
| C – Find the bugs | 8 | Mark the bugs on paper first, then fix [Q08-find-the-bugs.c](Q08-find-the-bugs.c) and run it. |
| D – Complete the functions | 9–12 | Fill in the `.c` starter file and run it. Expected output is in the file. |
| E – Write the program | 13–15 | Write it in the `.c` file. |

> Tip: for Part A, write the output **exactly** as it is printed (spaces and line breaks matter).

---

## Part A – Predict the Output

### Question 1 – Scope, Pass-by-Value and `static`

```c
#include <stdio.h>

int x = 10;

void useGlobal(void)
{
    x += 5;
    printf("%d ", x);
}

void change(int x)
{
    x = x * 2;
    printf("%d ", x);
}

int counter(void)
{
    static int count = 0;
    int calls = 0;
    count++;
    calls++;
    return count * 10 + calls;
}

int main(void)
{
    int x = 3;
    printf("%d ", x);
    {
        int x = 7;
        x++;
        printf("%d ", x);
    }
    printf("%d\n", x);

    change(x);
    printf("%d\n", x);

    useGlobal();
    useGlobal();
    printf("%d\n", x);

    printf("%d ", counter());
    printf("%d ", counter());
    printf("%d\n", counter());
    return 0;
}
```

**Output:**

---

### Question 2 – Operator Traps

Pre/post increment, integer division, casting, `%` with negatives, `char` arithmetic, short-circuit evaluation, `?:`.

```c
#include <stdio.h>

int main(void)
{
    int a = 5, b = 2, c, d;
    double e;

    c = a++ * 2;
    d = ++b * 2;
    printf("%d %d %d %d\n", a, b, c, d);

    e = a / 4;
    printf("%.2f ", e);
    e = (double)a / 4;
    printf("%.2f ", e);
    e = (double)(a / 4);
    printf("%.2f\n", e);

    printf("%.1f %.1f\n", 7 / 2 * 2.0, 7 * 2.0 / 2);
    printf("%d %d\n", 17 % 5, -17 % 5);

    char ch = 'A' + 2;
    printf("%c %d\n", ch, ch);

    int x = 0, y = 5;
    if (x++ > 0 && y++ > 0)
        printf("A ");
    else
        printf("B ");
    if (x++ > 0 || y++ > 0)
        printf("C ");
    printf("%d %d\n", x, y);

    int m = (x > y) ? x : y * 2;
    printf("%d\n", m);
    return 0;
}
```

**Output:**

---

### Question 3 – Bitwise and Logical Operators

Hint: `12 = 1100` and `10 = 1010` in binary. Watch the **operator precedence** on the third `printf`.

```c
#include <stdio.h>

int main(void)
{
    int a = 12, b = 10;
    printf("%d %d %d\n", a & b, a | b, a ^ b);
    printf("%d %d\n", a << 2, b >> 1);
    printf("%d\n", a & b == 8);

    int x = 1, y = 2, z = 3;
    x = y > z;
    y = !x + (z == 3);
    z = x || y && !z;
    printf("%d %d %d\n", x, y, z);

    int n = 5;
    printf("%d %d\n", n & 1, (n >> 1) & 1);
    printf("%d\n", 3 + 4 > 6 == 1);
    return 0;
}
```

**Output:**

---

### Question 4 – `switch` Fall-Through

Note: `default` is **not** the last label, and some `break`s are missing.

```c
#include <stdio.h>

void grade(char c)
{
    switch (c)
    {
    case 'A':
        printf("Excellent ");
    case 'B':
        printf("Good ");
        break;
    default:
        printf("Unknown ");
    case 'C':
        printf("Pass ");
    case 'D':
        printf("Weak ");
        break;
    case 'F':
        printf("Fail ");
    }
    printf("| ");
}

int main(void)
{
    grade('A');
    grade('B');
    grade('C');
    grade('X');
    grade('F');
    grade('a');
    return 0;
}
```

**Output:**

---

### Question 5 – Loops: `break`, `continue`, `do-while`, Comma Operator

Also write the **final values** of the variables that are printed.

```c
#include <stdio.h>

int main(void)
{
    int i, j, total = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i % 3 == 0)
            continue;
        if (i * i > 50)
            break;
        total += i;
        printf("%d ", i);
    }
    printf("\ntotal=%d i=%d\n", total, i);

    int k = 10;
    do
    {
        printf("%d ", k);
        k -= 4;
    } while (k > 10);
    printf("k=%d\n", k);

    for (i = 0, j = 10; i < j; i += 3, j -= 2)
        printf("(%d,%d) ", i, j);
    printf("i=%d j=%d\n", i, j);

    int n = 0;
    while (n < 5)
        n += 2;
    printf("n=%d\n", n);
    return 0;
}
```

**Output:**

---

### Question 6 – Recursion

```c
#include <stdio.h>

void f(int n)
{
    if (n <= 0)
    {
        printf("* ");
        return;
    }
    printf("%d ", n);
    f(n - 2);
    printf("%d ", n * 10);
}

int g(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + 2 * g(n / 10);
}

int calls = 0;

int fib(int n)
{
    calls++;
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    f(5);
    printf("\n");

    printf("%d\n", g(123));

    int r = fib(5);
    printf("%d %d\n", r, calls);
    return 0;
}
```

a) Write the output of the program.
b) Draw the **call tree** of `fib(5)`.
c) Without running it: how many times is `fib` called in total for `fib(6)`?

**Output:**

---

## Part B – Count Line Executions

### Question 7

```c
#include <stdio.h>

int main(void)
{
    int i, j, count = 0;
    for (i = 1; i <= 4; i++)
    {
        for (j = i; j <= 4; j++)
        {
            if ((i + j) % 3 == 0)
                continue;
            count++;
        }
    }
    printf("count = %d\n", count);

    int n = 20, steps = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        steps++;
    }
    printf("steps = %d\n", steps);
    return 0;
}
```

Fill in how many times each expression/line is executed, and write the output.

| # | Expression / line | Executions |
|---|---|---|
| 1 | `i <= 4` | |
| 2 | `i++` | |
| 3 | `j <= 4` | |
| 4 | `j++` | |
| 5 | `if ((i + j) % 3 == 0)` | |
| 6 | `continue;` | |
| 7 | `count++;` | |
| 8 | `n != 1` | |
| 9 | `n /= 2;` | |
| 10 | `n = 3 * n + 1;` | |

**Output:**

---

## Part C – Find the Bugs

### Question 8 – [Q08-find-the-bugs.c](Q08-find-the-bugs.c)

The program reads `N` and should print:
- the sum of the series **S = 1 + 1/2 + 1/3 + … + 1/N**, with 4 decimal places,
- how many **palindrome numbers** are between 1 and N (e.g. 7, 11, 121).

The code contains **8 bugs** (compile errors, logic errors and runtime errors).
Find each one, write which line it is on, explain why it is wrong, and write the correct version.
Then fix the file and run it.

Expected output for `N = 20`:
```
Series sum: 3.5977
Palindromes: 10
```

---

## Part D – Complete the Functions

### Question 9 – Digit Functions – [Q09-digit-functions.c](Q09-digit-functions.c)

Complete the functions. `main` is already written.

| Function | Rule |
|---|---|
| `int digitSum(int n)` | **Recursive.** Sum of the digits: `9875 → 29` |
| `int countDigit(int n, int d)` | **Recursive.** How many times digit `d` appears in `n`: `(1020304, 0) → 3` |
| `int reverseNum(int n)` | **Loop.** Reverse the digits: `12340 → 4321` |
| `int isPalindrome(int n)` | Return 1 if `n` reads the same backwards, else 0. Use `reverseNum`. |

### Question 10 – Series – [Q10-series.c](Q10-series.c)

| Function | Series |
|---|---|
| `double alternatingSeries(int n)` | **Loop:** 1 − 1/2 + 1/3 − 1/4 + … ± 1/n |
| `double alternatingSeriesRec(int n)` | The same series, **recursively** (no loop) |
| `double eSeries(int n)` | 1 + 1/1! + 1/2! + … + 1/n! — **without** a separate factorial function, using a single loop |
| `double squareSeries(int n)` | 1/2 + 2/5 + 3/10 + … + n/(n² + 1) |

Watch out for integer division.

### Question 11 – Binary with Recursion – [Q11-binary-recursion.c](Q11-binary-recursion.c)

A harder version of last year's "number of 1s in binary" question.

| Function | Rule |
|---|---|
| `void printBinary(int n)` | **Recursive.** Print `n` in binary in the **correct order** (`13 → 1101`). No loops, no arrays. |
| `int countOnes(int n)` | **Recursive.** Number of 1 bits: `13 → 3` |
| `int binaryToDecimal(int b)` | **Recursive.** `b` is written with the digits 0/1 as a decimal number: `1101 → 13` |

### Question 12 – Fibonacci Algorithms – [Q12-fibonacci-algorithms.c](Q12-fibonacci-algorithms.c)

Fibonacci: F(0) = 0, F(1) = 1, F(n) = F(n−1) + F(n−2) → `0 1 1 2 3 5 8 13 21 34 …`

| Function | Task |
|---|---|
| `void printFib(int n)` | Print the first `n` terms using a loop |
| `int fibRec(int n)` | n-th term, **recursive** |
| `int fibIter(int n)` | n-th term, **loop** (no recursion) |
| `int sumEvenFib(int limit)` | Sum of the **even** terms that are `<= limit` |
| `int isFibonacci(int x)` | 1 if `x` is a Fibonacci number, else 0 |
| `int firstFibWithDigits(int d)` | Index of the first term that has `d` digits |

Then answer in a comment at the bottom of the file:
1. Why is `fibRec(40)` much slower than `fibIter(40)`? (Think about Question 6c.)
2. The ratio `F(20) / F(19)` should print `1.618034` (the golden ratio). Why does `fibIter(20) / fibIter(19)` print `1`, and how do you fix it?

---

## Part E – Write the Program

### Question 13 – `rand()` – [Q13-rand-program.c](Q13-rand-program.c)

Design and write **your own** program that uses random numbers. The file is empty on purpose.
Your program must:

1. Use `srand(time(NULL))` correctly — call it **once**, not inside a loop.
2. Generate numbers in a **specific range** using `rand() % (max - min + 1) + min` — at least one range that does **not** start at 0 or 1 (e.g. 20–50).
3. Use a loop and at least one function.
4. Validate user input with the return value of `scanf` (if your program reads input).

Ideas (pick one or invent your own): a guessing game with limited attempts and "play again?",
a dice simulation that counts how often each sum appears, a math quiz with random questions and a score,
a random password/PIN generator.

Answer in a comment at the top of the file:
1. What happens if you do not call `srand` at all?
2. What happens if you call `srand(time(NULL))` inside a loop that runs many times per second?
3. What range does `rand() % 31 + 20` produce?

### Question 14 – Star Shapes – [Q14-star-shapes.c](Q14-star-shapes.c)

Write one function per shape; each takes the size `n`. Expected output for `n = 4`:

```
pyramid(4):        diamond(4):        hollowSquare(4):   numberTriangle(4):
   *                  *               ****               1
  ***                ***              *  *               2 3
 *****              *****             *  *               4 5 6
*******            *******            ****               7 8 9 10
                    *****
                     ***
                      *
```

### Question 15 – Number Analysis Menu – [Q15-number-analysis-menu.c](Q15-number-analysis-menu.c)

Write a menu program that repeats with a `do-while` until the user chooses `0`:

```
1. Digit count      -> recursive int digitCount(int n)       12345 -> 5
2. Armstrong?       -> int isArmstrong(int n)                153 = 1³ + 5³ + 3³ -> yes
3. Perfect?         -> int isPerfect(int n)                  28 = 1 + 2 + 4 + 7 + 14 -> yes
4. Prime?           -> int isPrime(int n)                    97 -> yes
0. Exit
```

Rules:
- Each check is its own function. Do **not** use `pow()` — write your own `int power(int base, int exp)`.
- An invalid menu choice prints an error and shows the menu again.
- Negative numbers and 0 are rejected.
- Typing a letter must not cause an infinite loop.
