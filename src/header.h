#include <stdio.h>
#include <stdlib.h>

extern float** add(float**, float**, int, int);
extern float** subtract(float**, float**, int, int);
extern float** multiply(float**, float**, int, int, int, int);
extern float* gaussian_elimination(float**, int, int);
extern float** rref(float**, int, int);
extern int trace(float**, int, int);
extern float** transpose(float**, int);
extern int rank(float**, int, int);


extern int get_rows();
extern int get_columns();
extern int check_zero_row(float**, int, int);
extern void swap_row(float**, int, int, int);
extern float** input_matrix(int, int, int);
extern float** allocate_matrix(int, int);
extern void print_matrix(float**, int, int);
