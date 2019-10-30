# Matrix Calculator
##### Ryan Kane

## A matrix calculator implemented in C for linux.

## Current Functionality
1. Addition
2. Subtraction
3. Multiplication
4. Gaussian Elimination
5. RREF
6. Trace
7. Transpose
8. Rank
9. Determinant

## TODO Functionality
1. Adjoint
2. Inverse

## Setup
1. Git clone or download this repo
2. Make sure you have Check (unit testing library) installed in order to run test suite. Use "sudo apt-get install check".


## To run calculator example:
1. cd into examples/calculator and run 'make'
2. run './calculator'

## To run Test Suite
1. In the root project directory run 'make test'
2. Run ./check

## To Integrate into your own project
1. Include the "{$PATH/TO/ROOT/PROJECT/DIR}/matrix.h"
2. Link the library to your project similarly to the Makefile in the calculator example
