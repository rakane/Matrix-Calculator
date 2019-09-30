#include "header.h"

void matrix_rref() {
	int rows, cols;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols);

	int ** arr = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr = input_matrix(rows, cols);
	
	// TODO #4: Implement Logic Here
}

void matrix_add() {
	
	// Get number of rows and columns from user
	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns each matrix?: ");
	scanf("%i", &cols);
	
	// Allocate and read in matricies
	int** arr1 = input_matrix(rows, cols);
	int** arr2 = input_matrix(rows, cols);
	int** new_arr = allocate_matrix(rows, cols);	
	
	// Perform Add operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	
	// Print new matrix
	print_matrix(new_arr, rows, cols);
}

void matrix_sub() {
	
	// Get number of rows and columns from user
	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns in each matrix?: ");
	scanf("%i", &cols);
	
	// Allocate and read in matrices
	int** arr1 = input_matrix(rows, cols);
	int** arr2 = input_matrix(rows, cols);
	int** new_arr = allocate_matrix(rows, cols);
	
	// Perform SUB operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
	
	// Prints new matrix
	print_matrix(new_arr, rows, cols);
	
}

void matrix_multiply() {

	// Get number of rows and columns from user
	int rows1, cols1, rows2, cols2;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows1);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols1);
	
	printf("How many rows in matrix 2?: ");
	scanf("%i", &rows2);
	printf("How many columns in matrix 2?: ");
	scanf("%i", &cols2);

	// Allocate and read in matrices
	int** arr1 = input_matrix(rows1, cols1);
	int** arr2 = input_matrix(rows2, cols2);
	
	// Check for valid dimensions for multiplication
	if(cols1 != rows2) {
		printf("Invalid matrix dimensions");
		return;
	}

	// Allocate new array
	int** new_arr = allocate_matrix(rows1, cols2);
	
	int sum = 0;
	
	for(int i = 0; i < rows1; i++) {
		for(int j = 0; j < cols2; j++) {
			sum = 0;
			for(int k = 0; k < cols1; k++) {
				sum = sum + (arr1[i][k] * arr2[k][j]);
			}
			new_arr[i][j] = sum;
		}
	}

	print_matrix(new_arr, rows1, cols2);

}

/*
 *	Function: input_matrix
 *	------------------------------
 *	Return an int** pointing to the inputted matrix from the user
 *	
 *	rows: number of rows desired for the matrix
 *	columns: number of columns desired for the matrix
 *
 *	returns: A 2D int array of size [rows][columns] which values created by user
 */
int** input_matrix(int rows, int columns) {
	
	int** arr = allocate_matrix(rows, columns);
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("Enter value for (%i, %i): ", i, j);
			scanf("%i", &arr[i][j]); 
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%i ", arr[i][j]); 
		}
		printf("\n");
	}

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
int** allocate_matrix(int rows, int columns) {
	int ** arr = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr[i] = (int *) malloc(columns * sizeof(int));	
	}
	return arr;
}


/*
 *	Function: print_matrix
 *	------------------------------
 *	Print the matrix
 *	
 *	arr: The matrix to be printed
 *	rows: number of rows in arr
 *	columns: number of columns in arr
 *
 *	returns: A 2D int array of size [rows][columns] which values created by user
 */
void print_matrix(int** arr, int rows, int columns) {
	
	printf("------New Matrix------\n");
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%i ", arr[i][j]); 
		}
		printf("\n");
	}

}





