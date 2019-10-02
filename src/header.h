#include <stdio.h>
#include <stdlib.h>

extern void add();
extern void subtract();
extern void multiply();
extern void gaussian_elimination();
extern void rref();
extern void trace();
extern void transpose();
extern void rank();

extern int check_zero_row(float**, int, int);
extern void swap_row(float**, int, int, int);
extern float** input_matrix(int, int, int);
extern float** allocate_matrix(int, int);
extern void print_matrix(float**, int, int);
