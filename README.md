# COME115 – Introduction to Programming

My study repository for the COME115 Introduction to Programming course (Computer Engineering).
It collects the lab materials, the flowchart and algorithm solutions, and the C programs I write while preparing for the exams.

**Author:** Mert Eldemir
</br>
**Student Number**: 25120205086

## Project Structure

```
.
├── README.md
├── Midterm/
│   ├── Midterm.md
│   ├── materials/                    # Lab PDFs from class (Weeks 3–7)
│   │   ├── flow-diagrams.pdf
│   │   ├── lab-3.pdf
│   │   ├── lab-3-ekstra.pdf
│   │   ├── lab-4.pdf
│   │   ├── lab-5.pdf
│   │   ├── lab-6.pdf
│   │   └── lab-7.pdf
│   ├── solutions/
│   │   ├── 01-flowchart-symbols.md   # Flowchart / algorithm solutions (Week 3)
│   │   └── questions/                # C programs, one file per lab question
│   │       ├── lab-5/                # Q01 … Q11 (+ Q07b bonus)
│   │       ├── lab-6/                # Q01a/Q01b … Q07
│   │       └── lab-7/                # Q01 … Q11
│   └── summary/                      # (empty for now)
└── Final/
    └── Final.md
```

Each C file starts with a comment block describing the question (topic, task, test cases from the PDF), followed by my solution.
Files are named `QNN-short-description.c` so they sort in question order.

## Compiling and Running

```sh
cd Midterm/solutions/questions/lab-5
gcc -Wall Q03-positive-check.c -o Q03 && ./Q03
```

On macOS `gcc` is Apple Clang.
Compiled executables are ignored by `.gitignore`.

## Midterm

### Materials

| File                                                     | Content                                                                                       |
| -------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| [flow-diagrams.pdf](Midterm/materials/flow-diagrams.pdf) | Flowchart symbols reference sheet                                                             |
| [lab-3.pdf](Midterm/materials/lab-3.pdf)                 | Week 3 – Algorithms and flowcharts                                                            |
| [lab-3-ekstra.pdf](Midterm/materials/lab-3-ekstra.pdf)   | Week 3 – Extra study questions 7–31                                                           |
| [lab-4.pdf](Midterm/materials/lab-4.pdf)                 | Week 4 – Flowcharts with loops, questions 1–9                                                 |
| [lab-5.pdf](Midterm/materials/lab-5.pdf)                 | Week 5 – First C programs: data types, `printf`/`scanf`, `if`/`else`, `switch`, examples 1–11 |
| [lab-6.pdf](Midterm/materials/lab-6.pdf)                 | Week 6 – Nested `if`, `switch-case`, `while` and `for` loops, questions 1–7                   |
| [lab-7.pdf](Midterm/materials/lab-7.pdf)                 | Week 7 – `do-while`, nested loops, `break`/`continue`, functions, questions 1–11              |

### Solutions

#### Flowcharts

| Solution                                                             | Covers                                              | Source material                                                                                                  |
| -------------------------------------------------------------------- | --------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| [01-flowchart-symbols.md](Midterm/solutions/01-flowchart-symbols.md) | Week 3 extra questions 7–31 (algorithm + flowchart) | [lab-3-ekstra.pdf](Midterm/materials/lab-3-ekstra.pdf), [flow-diagrams.pdf](Midterm/materials/flow-diagrams.pdf) |

#### C Programs ([questions/](Midterm/solutions/questions))

| Lab                                             | Questions                   | Topics covered                                                                                                                                                                                                      |
| ----------------------------------------------- | --------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [Lab&nbsp;5](Midterm/solutions/questions/lab-5) | 11&nbsp;+&nbsp;1&nbsp;bonus | Data types and format specifiers, `printf`/`scanf`, `if` / `if-else` / `else if` chains, nested `if`, logical operators (`&&`, `\|\|`), modulus `%`, `switch-case`, input validation                                |
| [Lab&nbsp;6](Midterm/solutions/questions/lab-6) | 7                           | Character checks with ASCII ranges, nested `if`, `switch-case` (and fall-through without `break`), `for` and `while` loops, nested loops for star patterns                                                          |
| [Lab&nbsp;7](Midterm/solutions/questions/lab-7) | 11                          | `do-while` menus, char loops (alphabet, letter triangle), functions: `void` vs returning, with/without parameters, `#define` constants, digit tricks with `%` and `/`, prime check, `scanf` return-value validation |

## Final

[Final.md](Final/Final.md)
