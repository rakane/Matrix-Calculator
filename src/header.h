#include <stdio.h>
#include <stdlib.h>

extern void matrix_rref();
extern void matrix_add();
extern void matrix_sub();
extern void matrix_multiply();
extern float** input_matrix(int, int, int);
extern float** allocate_matrix(int, int);
extern void print_matrix(float**, int, int);
