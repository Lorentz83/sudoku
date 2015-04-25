sudoku
======

This is a simple CLI sudoku solver.

I wrote it some years ago, during the summer when sudoku became popular
in Europe (I think it was 2008).
I simply got bored on solving sudoku by myself and decided that it was
easier to write a simple program to do it for me.

How does it work?
-----------------

The solver implements a simple depth first search with backtracking.
It is written in pure c++ and does not require any additional
library.

I tested it only on Linux, but it should work on any operating system
with a c++ compiler.

The I/O is very basic and can be improved, but it is good enough to
work.

Compile and execute the project
-------------------------------

Simply type `make` to get the sudoku executable.
No setup is required, just execute it, write the sudoku and wait for
the solutions.

Future work (that maybe I'll never do)
--------------------------------------

In no particular order, this is a list of interesting extensions:
* better I/O;
* add a GUI;
* add a sudoku generator;
* experiment with the C++14 features

