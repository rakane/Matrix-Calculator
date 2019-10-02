
/* 
 * Matrix Calculator Library 
 * Author: Ryan Kane
 *	
 * Library includes function for each matrix operation, 
 * as well as helper functions for inputting and 
 * allocating the matrices
 */

#include "header.h"

/*
 *	Function: add
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the sum
 */
float** add(float** arr1, float** arr2, int rows, int cols) 
{
	float** new_arr = allocate_matrix(rows, cols);	
	
	// Perform Add operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return new_arr;
}

/*
 *	Function: subtract
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the difference
 */
float** subtract(float** arr1, float** arr2, int rows, int cols) 
{	
	float** new_arr = allocate_matrix(rows, cols);
	
	// Perform SUB operation
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] - arr2[i][j];
		}
	}	
	return new_arr;
}

/*
 *	Function: multiply
 *	------------------------------
 *	Gets two matrices as input from user, then calculates and prints the dot product
 */
float** multiply(float** arr1, float** arr2, int rows1, int cols1, int rows2, int cols2) 
{	
	// Check for valid dimensions for multiplication
	if(cols1 != rows2) {
		printf("Invalid matrix dimensions");
		exit(1);
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
	return new_arr;
}

/*
 *	Function: gaussian_elimination
 *	------------------------------
 *	Gets matrix as input from user, then uses Gaussian Elimination to solve
 */
float* gaussian_elimination(float** arr, int rows, int cols) 
{
	int zero_rows;

	zero_rows = check_zero_row(arr, rows, cols);
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
				c = arr[i][j] / arr[j][j];
				for(k = 0; k <= n + 1; k++) {
					arr[i][k] -= (c * arr[j][k]);
				}
			}
		}
	}
	
	// Print Upper Triangular matrix for debugging
	printf("\n\n--------Upper Triangular Matrix--------\n");
	print_matrix(arr, rows + zero_rows, cols);
		
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
	
	return X;
}

/*
 *	Function: rref
 *	------------------------------
 *	Gets matrix as input from user, then reduces matrix to rref if possible
 */
float** rref(float** arr, int rows, int cols) 
{
	int zero_rows;
	zero_rows = check_zero_row(arr, rows, cols);
	rows -= zero_rows;

	// Begin RREF
	int lead = 0;
	
	while(lead < rows) {
		float d, m;

		for(int i = 0; i < rows; i++) {
			// Divisor
			d = arr[lead][lead];
			// Multiplier	
			m = arr[i][lead] / arr[lead][lead];
			
			for(int j = 0; j < cols; j++) {
				if(i == lead) {
					arr[i][j] = arr[i][j] / d;
				} else {
					arr[i][j] -= arr[lead][j] * m;
				}
			}
		}
		lead++;
	}
	// End RREF
	return arr;
}

/*
 *	Function: trace
 *	------------------------------
 *	Gets matrix as input from user, then calculates the trace
 */
int trace(float** arr, int rows, int cols)
{
	// Calculate trace by summing all arr[i][i] values
	float sum = 0.0;
	for(int i = 0; i < rows; i++) {
		sum += arr[i][i];
	}
	return sum;
}

/*
 *	Function: transpose
 *	------------------------------
 *	Gets matrix as input from user, then calculates its transpose
 */
float** transpose(float** arr, int rows) 
{
	float** new_arr = allocate_matrix(rows, rows);
	
	// Calculate transpose arr[i][j] = arr[j][i]
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			new_arr[i][j] = arr[j][i];
		}
	}
	return new_arr;
}

int rank(float** arr1, int rows, int cols) 
{    	
	float** arr = rref(arr1, rows, cols);
	int rank = 0;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(arr[i][j] != 0) {
				rank++;
				break;
			}	
		}
	}
	
	return rank;
}

int check_zero_row(float** arr, int rows, int columns) {
	
	int num = 0;
	int rows_shifted = 0;

	for(int i = 0; i < rows - rows_shifted; i++) {
		for(int j = 0; j < columns; j++) {
			if(arr[i][j] != 0) {
				break;
			}
			if(j == columns - 1) {
				num++;
				
				float temp;
				for(int k = 0; k <	columns; k++) {
					temp = arr[i][k];
					arr[i][k] = arr[rows - rows_shifted - 1][k];
					arr[rows - rows_shifted - 1][k] = temp;
				}	
				
				rows_shifted++;
			}	
		} 
	}

	return num;
}


