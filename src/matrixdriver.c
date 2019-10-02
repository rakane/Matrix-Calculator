#include "header.h"

float** arr1, **arr2, **new_arr;
float* X;
int rows1, columns1, rows2, columns2, num;



void add_driver()
{
	rows1 = get_rows(1);
	columns1 = get_columns(1);
	arr1 = input_matrix(rows1, columns1, 1);
	arr2 = input_matrix(rows1, columns1, 2);
	new_arr = add(arr1, arr2, rows1, columns1);
	printf("-------------Solution-----------\n");
	print_matrix(new_arr, rows1, columns1);
}

void subtract_driver()
{
	rows1 = get_rows(1);
	columns1 = get_columns(1);
	arr1 = input_matrix(rows1, columns1, 1);
	arr2 = input_matrix(rows1, columns1, 2);
	new_arr = subtract(arr1, arr2, rows1, columns1);
	printf("-------------Solution-----------\n");
	print_matrix(new_arr, rows1, columns1);
}

void multiply_driver() 
{
	rows1 = get_rows(1);
	columns1 = get_columns(1);
	arr1 = input_matrix(rows1, columns1, 1);
	rows2 = get_rows(2);
	columns2 = get_columns(2);
	arr2 = input_matrix(rows2, columns2, 2);
	new_arr = multiply(arr1, arr2, rows1, columns1, rows2, columns2);
	printf("-------------Solution-----------\n");
	print_matrix(new_arr, rows1, columns2);

}

void gaussian_elimination_driver() 
{
	rows1 = get_rows(1);
	columns1 = rows1 + 1;
	X = malloc(sizeof(float) * rows1);
	arr1 = input_matrix(rows1, columns1, 1);
	X = gaussian_elimination(arr1, rows1, columns1);
	
	// Print solutions
	printf("\n\n----------------Solution----------------\n");
	for(int i = 0; i < rows1; i++) {
		printf("X[%i]: %.2f\n", i, X[i]);
	}
}

void rref_driver()
{
	rows1 = get_rows(1);
	columns1 = rows1 + 1;
	arr1 = input_matrix(rows1, columns1, 1);
	new_arr = rref(arr1, rows1, columns1);
	
	// Print RREF matrix
	printf("\n\n--------------RREF Matrix-------------\n");
	print_matrix(new_arr, rows1, columns1);
}

void trace_driver() {
	rows1 = get_rows(1);
	columns1 = rows1;
	arr1 = input_matrix(rows1, columns1, 1);
	num = trace(arr1, rows1, columns1);
	printf("\n\nTrace: %i\n", num);	
}

void transpose_driver() {
		rows1 = get_rows(1);
		columns1 = rows1;
		arr1 = input_matrix(rows1, columns1, 1);
		new_arr = transpose(arr1, rows1);
		printf("\n\n-----------Transposed Matrix---------\n");
		print_matrix(new_arr, rows1, rows1);
}

void rank_driver() {
	rows1 = get_rows(1);
	columns1 = rows1 + 1;
	arr1 = input_matrix(rows1, columns1, 1);
	num = rank(arr1, rows1, columns1);
	printf("\n\nRank: %i\n\n", num);
}


int get_rows(int num) {
	int num_rows;	
	printf("Enter number of rows in matrix %i: ", num);
	scanf("%i", &num_rows);
	return num_rows;
}

int get_columns(int num) {
	int num_cols;	
	printf("Enter number of columns in matrix %i: ", num);
	scanf("%i", &num_cols);
	return num_cols;
}


/*
 *	Function: input_matrix
 *	------------------------------
 *	Return an int** pointing to the inputted matrix from the user
 *	
 *	rows: number of rows desired for the matrix
 *	columns: number of columns desired for the matrix
 *	num: number of matrix, used for help with user instructions
 *
 *	returns: A 2D int array of size [rows][columns] which values created by user
 */
float** input_matrix(int rows, int columns, int num) {
	
	float** arr = allocate_matrix(rows, columns);
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("Enter value for matrix %i (%i, %i): ", num, i, j);
			scanf("%f", &arr[i][j]); 
		}
	}
	
	printf("\n-------------Input Matrix-------------\n");
	print_matrix(arr, rows, columns);

	return arr;
}

/*
 *	Function: allocate_matrix
 *	------------------------------
 *	Return an int** pointing to a correctly allocated matrix based on rows/columns
 *	
 *	rows: number of rows desired for the matrix
 *	columns: number of columns desired for the matrix
 *
 *	returns: An int** of size [rows][columns]
 */
float** allocate_matrix(int rows, int columns) {
	float ** arr = (float **) malloc(rows * sizeof(float *));
	for(int i = 0; i < rows; i++) {
		arr[i] = (float *) malloc(columns * sizeof(float));	
	}
	return arr;
}


/*
 *	Function: print_matrix
 *	----------------------------
 *	Print the matrix
 *
 *	arr: The matrix to be printed
 *	rows: number of rows in arr
 *	columns: number of columns in arr
 *
 */
void print_matrix(float** arr, int rows, int columns) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(arr[i][j] == 0 || arr[i][j] == -0) {
				printf("%.2f  ", 0.0);
			} else {
				printf("%.2f  ", arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

