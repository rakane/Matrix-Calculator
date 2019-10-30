/* 
 * Matrix Calculator Library 
 * Author: Ryan Kane
 *	
 * Library includes function for each matrix operation, 
 * as well as helper functions for inputting and 
 * allocating the matrices
 */

#include "matrix.h"


/*
 *	Function: add
 *	------------------------------
 *	Gets two matrices as parameters, and adds them together
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows
 *	 Number of rows in both matrices
 *	@param columns
 *	 Number of columns in both matrices
 *
 *	@return new_matrix 
 *	 The sum of the 2 input matrices
 */
float** add(float** matrix1, float** matrix2, int rows, int columns) 
{
	float** new_matrix = allocate_matrix(rows, columns);	
	
	// Perform Add operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			new_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return new_matrix;
}


/*
 *	Function: subtract
 *	------------------------------
 *	Gets two matrices as parameters, and subtracts matrix 2 from matrix 1
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows
 *	 Number of rows in both matrices
 *	@param columns
 *	 Number of columns in both matrices
 *
 *	@return new_matrix 
 *	 The difference of the 2 input matrices
 */
float** subtract(float** matrix1, float** matrix2, int rows, int columns) 
{	
	float** new_matrix = allocate_matrix(rows, columns);
	
	// Perform SUB operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			new_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}	
	return new_matrix;
}


/*
 *	Function: multiply
 *	------------------------------
 *	Gets two matrices as parameters, then calculates the dot product
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows1
 *	 Number of rows in matrix 1
 *	@param columns1
 *	 Number of columns in matrix 1
 *	@param rows2
 *	 Number of rows in matrix 2
 *	@param columns2
 *	 Number of columns in matrix 2
 *
 *	@return new_matrix 
 *	 The product of the 2 input matrices
 */
float** multiply(float** matrix1, float** matrix2, int rows1, int columns1, int rows2, int columns2) 
{	
	// Check for valid dimensions for multiplication
	if(columns1 != rows2) {
		printf("Invalid matrix dimensions");
		exit(1);
	}

	// Allocate new array
	float** new_matrix = allocate_matrix(rows1, columns2);
	
	float sum = 0;
	
	for(int i = 0; i < rows1; i++) {
		for(int j = 0; j < columns2; j++) {
			sum = 0;
			for(int k = 0; k < columns1; k++) {
				sum = sum + (matrix1[i][k] * matrix2[k][j]);
			}
			new_matrix[i][j] = sum;
		}
	}
	return new_matrix;
}


/*
 *	Function: gaussian_elimination
 *	------------------------------
 *	Gets matrix as a parameter, then uses Gaussian Elimination to solve
 *
 *	@param matrix
 *	 Input matrix to be solved by gaussian elimation
 *	@param rows
 *	 Number of rows in the matrices
 *	@param columns
 *	 Number of columns in the matrices
 *
 *	@return X 
 *	 The solution vector for the matrix
 */
float* gaussian_elimination(float** matrix, int rows, int columns) 
{
	int zero_rows;

	zero_rows = check_zero_row(matrix, rows, columns);
	rows -= zero_rows;


	// Gauss Jordan Elimination
	int n = rows - 1;
	int i, j, k;	
	float c;
	float *X = malloc(sizeof(float) * rows);
	float sum = 0.0;
	
	// Create Upper Triangular matrix
	for(j = 0; j <= n; j++) {
		for(i = 0; i <= n; i++) {
			if(i > j) {
				c = matrix[i][j] / matrix[j][j];
				for(k = 0; k <= n + 1; k++) {
					matrix[i][k] -= (c * matrix[j][k]);
				}
			}
		}
	}
	
	// Print Upper Triangular matrix for debugging
	// printf("\n\n--------Upper Triangular Matrix--------\n");
	// print_matrix(matrix, rows + zero_rows, columns);
		
	// Back Substitution
	X[n] =  matrix[n][n + 1] / matrix[n][n];
	
	for(i = n - 1; i >= 0; i--) {
		sum = 0.0;
		for(j = i + 1; j <= n; j++) {
			sum = sum + matrix[i][j] * X[j];
		}
		X[i] = (matrix[i][n + 1] - sum) / matrix[i][i];
	}
	// End Gauss Elimination
	
	return X;
}


/*
 *	Function: rref
 *	------------------------------
 *	Gets matrix as a parameter, then reduces matrix to rref if possible
 *	
 *	@param matrix
 *	 Input matrix to be transformed to rref
 *	@param rows
 *	 Number of rows in the matrices
 *	@param columns
 *	 Number of columns in the matrices
 *	
 *	@return matrix
 *	 The matrix is returned in rref form
 */
float** rref(float** matrix, int rows, int columns) 
{
	int zero_rows;
	zero_rows = check_zero_row(matrix, rows, columns);
	rows -= zero_rows;

	// Begin RREF
	int lead = 0;
	
	while(lead < rows) {
		float d, m;

		for(int i = 0; i < rows; i++) {
			// Divisor
			d = matrix[lead][lead];
			// Multiplier	
			m = matrix[i][lead] / matrix[lead][lead];
			
			for(int j = 0; j < columns; j++) {
				if(i == lead) {
					matrix[i][j] = matrix[i][j] / d;
				} else {
					matrix[i][j] -= matrix[lead][j] * m;
				}
			}
		}
		lead++;
	}
	// End RREF
	return matrix;
}


/*
 *	Function: trace
 *	------------------------------
 *	Gets matrix as a parameter, then calculates the trace
 *
 *	@param matrix
 *	 Input matrix that the trace is calculated for
 *	@param rows
 *	 Number of rows in the matrix
 *	@param columns
 *	 Number of columns in the matrix
 *
 * 	@return sum
 * 	 Trace value
 */
int trace(float** matrix, int rows, int columns)
{
	// Calculate trace by summing all arr[i][i] values
	float sum = 0.0;
	for(int i = 0; i < rows; i++) {
		sum += matrix[i][i];
	}
	return sum;
}


/*
 *	Function: transpose
 *	------------------------------
 *	Gets matrix as a parameter, then calculates its transpose
 *
 *	@param matrix
 *	 Input matrix that the transpose is calculated from
 *	@param rows
 *	 Number of rows in the matrix
 *
 *	@return new_matrix
 *	 The transposed matrix of the input matrix
 */
float** transpose(float** matrix, int rows) 
{
	float** new_matrix = allocate_matrix(rows, rows);
	
	// Calculate transpose
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			new_matrix[i][j] = matrix[j][i];
		}
	}
	return new_matrix;
}


/*
 *	Function: rank
 *	------------------------------
 *	Gets matrix as input from parameter, then calculates its rank
 *
 *	@param matrix
 *	 Input matrix for which the rank is calculated
 *	@param rows
 *	 Number of rows in the matrix
 *	@param columns
 *	 Number of columns in the matrix
 *
 *  @return rank
 *   Rank of the input matrix
 */
int rank(float** matrix, int rows, int columns) 
{    	

	float** new_matrix = rref(matrix, rows, columns);
	
	// Print RREF matrix
	//printf("\n\n--------------RREF Matrix-------------\n");
	//print_matrix(new_matrix, rows, cols);
	int rank = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(matrix[i][j] != 0) {
				rank++;
				break;
			}	
		}
	}
	
	return rank;
}


/*
 *	Function: determinant
 *	------------------------------
 *	Gets matrix as a parameter, then calculates its determinant
 *
 *	@param matrix
 *	 Input matrix that the determinant is calculated for
 *	@param rows
 *	 Number of rows in the matrix
 *	@param columns
 *	 Number of columns in the matrix
 *
 *	@return determinant
 *	 The determinant of the input matrix
 */
float det(float** matrix, int rows, int columns)
{
	float** minor = allocate_matrix(rows, columns);
	float determinant = 0;
	int c1, c2;
	int sign = 1;

	if(rows == 2) {
		determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);	
		return determinant;
	} else {
		for(int i = 0; i < rows; i++) {
				c1 = 0;
				c2 = 0;
			for(int j = 0; j < columns; j++) {
				for(int k = 0; k < rows; k++) {
					if(j != 0 && k != i) {
						minor[c1][c2] = matrix[j][k];
						c2++;
						if(c2 > rows - 2) {
							c1++;
							c2 = 0;
						}
					}
				}
			}
			determinant += (sign * (matrix[0][i] * det(minor, rows - 1, rows - 1)));
			sign = -1 * sign;
		}
	}
	return determinant;
}


/*
 *	Function: check_zero_row
 *	------------------------------
 *	Gets matrix, number of rows, and number of columns as parameters.
 *	Checks for any completely zero rows, and swaps them to the bottom of the matrix
 *
 *	@param matrix
 *	 Input matrix to be checked for zero rows
 *	@param rows
 *	 Number of rows in the matrix
 *	@param columns
 *	 Number of columns in the matrix
 *
 *	@return num
 *	 Number of zero rows in matrix
 */
int check_zero_row(float** matrix, int rows, int columns) {
	
	int num = 0;
	int rows_shifted = 0;

	for(int i = 0; i < rows - rows_shifted; i++) {
		for(int j = 0; j < columns; j++) {
			if(matrix[i][j] != 0) {
				break;
			}
			if(j == columns - 1) {
				num++;
				
				float temp;
				for(int k = 0; k <	columns; k++) {
					temp = matrix[i][k];
					matrix[i][k] = matrix[rows - rows_shifted - 1][k];
					matrix[rows - rows_shifted - 1][k] = temp;
				}	
				
				rows_shifted++;
			}	
		} 
	}

	return num;
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
