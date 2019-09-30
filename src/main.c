#include "header.h"

int main(int argc, char* argv[]) {
	
	printf("------Matrix Calculator------\n");
	
		
	printf("1.)\tRREF\n");
	printf("2.)\tAddition\n");
	printf("3.)\tSubtraction\n");
	printf("4.)\tMultiplication\n");
	
	int answer;
	printf("Enter corresponding number to choose which operation: ");
	scanf("%i", &answer);
	
	switch(answer) {
		case 1:
			matrix_rref(); break;
		case 2:
			matrix_add(); break;
		case 3:
			matrix_sub(); break;
		case 4:
			matrix_multiply(); break;
		default:
			printf("No operation choosen");
		}
}
