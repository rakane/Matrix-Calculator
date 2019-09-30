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
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols);
	
	int ** arr1 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr1[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr1 = input_matrix(rows, cols);
	
	
	printf("How many rows in matrix 2?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 2?: ");
	scanf("%i", &cols);

	int ** arr2 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr2[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr2 = input_matrix(rows, cols);
		
	// TODO #1: Implement Logic Here

}

void matrix_sub() {
	
	int rows, cols;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols);
	
	
	int ** arr1 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr1[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr1 = input_matrix(rows, cols);
	
	
	printf("How many rows in matrix 2?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 2?: ");
	scanf("%i", &cols);

	int ** arr2 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr2[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr2 = input_matrix(rows, cols);

	// TODO #2: Implement Logic Here


}

void matrix_multiply() {
	int rows, cols;
	printf("How many rows in matrix 1?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 1?: ");
	scanf("%i", &cols);
	
	
	int ** arr1 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr1[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr1 = input_matrix(rows, cols);
	
	
	printf("How many rows in matrix 2?: ");
	scanf("%i", &rows);
	printf("How many columns in matrix 2?: ");
	scanf("%i", &cols);

	int ** arr2 = (int **) malloc(rows * sizeof(int *));
	for(int i = 0; i < rows; i++) {
		arr2[i] = (int *) malloc(cols * sizeof(int));	
	}

	arr2 = input_matrix(rows, cols);

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





