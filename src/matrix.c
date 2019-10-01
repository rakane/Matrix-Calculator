#include "header.h"

/*
 *	Function: matrix_rref
 *	------------------------------
 *	Gets matrix as input from user, then calculates and prints RREF(matrix)
 */
void matrix_rref() {

	int rows, cols;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows);
	cols = rows + 1;

	float** arr = input_matrix(rows, cols, 1);

	// Gauss Jordan Elimination
	int n = rows - 1;
	int i, j, k;	
	float c;
	float X[n];
	float sum = 0.0;
	
	// Create Upper Triangular matrix
	for(j = 0; j <= n; j++) {
		for(i = 0; i <= n; i++) {
			if(i > j) {
				c = arr[i][j] / arr[j][j];
				for(k = 0; k <= n + 1; k++) {
					arr[i][k] -= (c * arr[j][k]);
				}
			}
		}
	}
	
	// Print Upper Triangular matrix for debugging
	printf("\n\n--------Upper Triangular Matrix--------\n");
	print_matrix(arr, rows, cols);
	
	
	// Back Substitution
	X[n] =  arr[n][n + 1] / arr[n][n];
	
	for(i = n - 1; i >= 0; i--) {
		sum = 0.0;
		for(j = i + 1; j <= n; j++) {
			sum = sum + arr[i][j] * X[j];
		}
		X[i] = (arr[i][n + 1] - sum) / arr[i][i];
	}
	// End Gauss Elimination	
	
	// Print solutions
	printf("\n\n----------------Solution----------------\n");
	for(i = 0; i <= n; i++) {
		printf("X[%i]: %.2f\n", i, X[i]);
	}
	
	return;
}


/*
 *	Function: matrix_add
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the sum
 */
void matrix_add() {
	
	// Get number of rows and columns from user
	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns each matrix?: ");
	scanf("%i", &cols);
	
	// Allocate and read in matricies
	float** arr1 = input_matrix(rows, cols, 1);
	float** arr2 = input_matrix(rows, cols, 2);
	float** new_arr = allocate_matrix(rows, cols);	
	
	// Perform Add operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	
	// Print new matrix
	printf("------New Matrix------\n");
	print_matrix(new_arr, rows, cols);
}


/*
 *	Function: matrix_sub
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the difference
 */
void matrix_sub() {
	
	// Get number of rows and columns from user
	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns in each matrix?: ");
	scanf("%i", &cols);
	
	// Allocate and read in matrices
	float** arr1 = input_matrix(rows, cols, 1);
	float** arr2 = input_matrix(rows, cols, 2);
	float** new_arr = allocate_matrix(rows, cols);
	
	// Perform SUB operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
	
	// Prints new matrix
	printf("------New Matrix------\n");
	print_matrix(new_arr, rows, cols);
	
}


/*
 *	Function: matrix_multiply
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the dot product
 */
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
	float** arr1 = input_matrix(rows1, cols1, 1);
	float** arr2 = input_matrix(rows2, cols2, 2);
	
	// Check for valid dimensions for multiplication
	if(cols1 != rows2) {
		printf("Invalid matrix dimensions");
		return;
	}

	// Allocate new array
	float** new_arr = allocate_matrix(rows1, cols2);
	
	float sum = 0;
	
	for(int i = 0; i < rows1; i++) {
		for(int j = 0; j < cols2; j++) {
			sum = 0;
			for(int k = 0; k < cols1; k++) {
				sum = sum + (arr1[i][k] * arr2[k][j]);
			}
			new_arr[i][j] = sum;
		}
	}

	printf("------New Matrix------\n");
	print_matrix(new_arr, rows1, cols2);

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
 *	------------------------------
 *	Print the matrix
 *	
 *	arr: The matrix to be printed
 *	rows: number of rows in arr
 *	columns: number of columns in arr
 *
 *	returns: A 2D int array of size [rows][columns] which values created by user
 */
void print_matrix(float** arr, int rows, int columns) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%.2f   ", arr[i][j]);	
		}
		printf("\n");
	}

}





