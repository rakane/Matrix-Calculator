#include "header.h"

int main(int argc, char* argv[]) {
	
	printf("------Matrix Calculator------\n");

	printf("1.)\tAddition\n");
	printf("2.)\tSubtraction\n");
	printf("3.)\tMultiplication\n");	
	printf("4.)\tGaussian Elimination\n");
	printf("5.)\tRREF\n");
	printf("6.)\tTrace\n");
	printf("7.)\tTranspose\n");
	printf("8.)\tRank\n");

	
	float** arr1, **arr2, **new_arr;
	float* X;
	int answer, rows1, columns1, rows2, columns2, num;
	printf("Enter corresponding number to choose which operation: ");
	scanf("%i", &answer);
	
	switch(answer) {
		case 1:
			rows1 = get_rows();
			columns1 = get_columns();
			arr1 = input_matrix(rows1, columns1, 1);
			arr2 = input_matrix(rows1, columns1, 2);
			new_arr = add(arr1, arr2, rows1, columns1);
			printf("-------------Solution-----------\n");
			print_matrix(new_arr, rows1, columns1);
			break;
		case 2:
			rows1 = get_rows();
			columns1 = get_columns();
			arr1 = input_matrix(rows1, columns1, 1);
			arr2 = input_matrix(rows1, columns1, 2);
			new_arr = subtract(arr1, arr2, rows1, columns1);
			printf("-------------Solution-----------\n");
			print_matrix(new_arr, rows1, columns1);
			break;
		case 3:
			rows1 = get_rows();
			columns1 = get_columns();
			arr1 = input_matrix(rows1, columns1, 1);
			rows2 = get_rows();
			columns2 = get_columns();
			arr2 = input_matrix(rows2, columns2, 2);
			new_arr = multiply(arr1, arr2, rows1, columns1, rows2, columns2);
			printf("-------------Solution-----------\n");
			print_matrix(new_arr, rows1, columns2);
			break;
		case 4:
			rows1 = get_rows();
			columns1 = rows1 + 1;
			X = malloc(sizeof(float) * rows1);
			arr1 = input_matrix(rows1, columns1, 1);
			X = gaussian_elimination(arr1, rows1, columns1);
			// Print solutions
			printf("\n\n----------------Solution----------------\n");
			for(int i = 0; i < rows1; i++) {
				printf("X[%i]: %.2f\n", i, X[i]);
			}
			break;
		case 5:
			rows1 = get_rows();
			columns1 = rows1 + 1;
			arr1 = input_matrix(rows1, columns1, 1);
			new_arr = rref(arr1, rows1, columns1);
			// Print RREF matrix
			printf("\n\n--------------RREF Matrix-------------\n");
			print_matrix(new_arr, rows1, columns1);
			break;
		case 6:
			rows1 = get_rows();
			columns1 = rows1;
			arr1 = input_matrix(rows1, columns1, 1);
			num = trace(arr1, rows1, columns1);
		   	printf("\n\nTrace: %i\n", num);	
			break;
		case 7:
			rows1 = get_rows();
			columns1 = rows1;
			arr1 = input_matrix(rows1, columns1, 1);
			new_arr = transpose(arr1, rows1);
			printf("\n\n-----------Transposed Matrix---------\n");
			print_matrix(new_arr, rows1, rows1);
			break;
		case 8:
			rows1 = get_rows();
			columns1 = rows1 + 1;
			arr1 = input_matrix(rows1, columns1, 1);
			num = rank(arr1, rows1, columns1);
			printf("\n\nRank: %i\n\n", num);
			break;
		default:
			printf("No operation choosen");
		}
}

int get_rows() {
	int num_rows;	
	printf("Enter number of rows in matrix: ");
	scanf("%i", &num_rows);
	return num_rows;
}

int get_columns() {
	int num_cols;	
	printf("Enter number of columns in matrix: ");
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


