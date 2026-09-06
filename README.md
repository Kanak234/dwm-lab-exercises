# Data Warehousing & Mining — Lab Exercises

Coursework: a collection of standalone lab programs in mixed languages (Python,
C, C++, a Jupyter notebook, and an HTML page). Each file is an independent
exercise, not part of one build.

## Contents

- `1.py`, `1.ipynb` — data-mining exercises in Python
- `a1.cpp`, `111.c` — C/C++ lab programs
- plus an HTML page and additional exercise files

## Run

Each file runs on its own:

```bash
python3 1.py
jupyter notebook 1.ipynb
g++ a1.cpp -o a1 && ./a1
gcc 111.c -o prog && ./prog
```

## Known limitation

At least one C program (`111.c`) `#include`s `graphics.h`, the Turbo C / DOS
BGI header. That header does not exist on Linux or modern compilers, so it will
not compile as-is. It is preserved here as the original coursework; porting it
would mean replacing BGI graphics with a modern library such as SDL2.

## Status

An archive of lab coursework. The files are kept as submitted; they are not
maintained as a single runnable project.
