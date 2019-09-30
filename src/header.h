#include <stdio.h>
#include <stdlib.h>

extern void matrix_rref();
extern void matrix_add();
extern void matrix_sub();
extern void matrix_multiply();
extern int** input_matrix(int, int);
extern int** allocate_matrix(int, int);
extern void print_matrix(int**, int, int);
