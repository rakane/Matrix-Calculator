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

		
	int answer;
	printf("Enter corresponding number to choose which operation: ");
	scanf("%i", &answer);
	
	switch(answer) {
		case 1:
			add(); break;
		case 2:
			subtract(); break;
		case 3:
			multiply(); break;
		case 4:
			gaussian_elimination(); break;
		case 5:
			rref(); break;
		case 6:
			trace(); break;
		case 7:
			transpose(); break;
		default:
			printf("No operation choosen");
		}
}
