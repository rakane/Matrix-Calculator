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

	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns each matrix?: ");
	scanf("%i", &cols);

	int** arr1 = input_matrix(rows, cols);
	int** arr2 = input_matrix(rows, cols);
	int** new_arr = allocate_matrix(rows, cols);	
		
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

	print_matrix(new_arr, rows, cols);
}

void matrix_sub() {
	
	int rows, cols;
	printf("How many rows in each matrix?: ");
	scanf("%i", &rows);
	printf("How many columns in each matrix?: ");
	scanf("%i", &cols);

	int** arr1 = input_matrix(rows, cols);
	int** arr2 = input_matrix(rows, cols);
	int** new_arr = allocate_matrix(rows, cols);

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			new_arr[i][j] = arr1[i][j] - arr2[i][j];
		}
	}

	print_matrix(new_arr, rows, cols);
	
}

void matrix_multiply() {
	int rows1, cols1, rows2, cols2;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows1);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols1);

	int** arr1 = input_matrix(rows1, cols1);
	
	printf("How many rows in matrix 2?: ");
	scanf("%i", &rows2);
	printf("How many columns in matrix 2?: ");
	scanf("%i", &cols2);

	int** arr2 = input_matrix(rows2, cols2);
	
	if(cols1 != rows2) {
		printf("Invalid matrix dimensions");
		return;
	}


	int** new_arr = allocate_matrix(rows1, cols2);

	// TODO #3: Implement Logic Here


}

int** input_matrix(int rows, int columns) {
	int ** arr = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr[i] = (int *) malloc(columns * sizeof(int));	
	}
	
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
int** allocate_matrix(int rows, int columns) {
	int ** arr = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr[i] = (int *) malloc(columns * sizeof(int));	
	}
	return arr;
}

void print_matrix(int** arr, int rows, int columns) {
	
	printf("------New Matrix------\n");
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%i ", arr[i][j]); 
		}
		printf("\n");
	}

}





