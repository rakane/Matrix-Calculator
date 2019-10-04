#include "header.h"

int main(int argc, char* argv[]) {
 	int loop = 1;
	
	while(loop) {

		printf("------Matrix Calculator------\n");
		printf("1.)\tAddition\n");
		printf("2.)\tSubtraction\n");
		printf("3.)\tMultiplication\n");	
		printf("4.)\tGaussian Elimination\n");
		printf("5.)\tRREF\n");
		printf("6.)\tTrace\n");
		printf("7.)\tTranspose\n");
		printf("8.)\tRank\n");
		printf("9.)\tDeterminant\n");
	
	
		int answer;		
		printf("Enter corresponding number to choose which operation: ");
		scanf("%i", &answer);
	
		switch(answer) {
			case 1:
				add_driver(); break;
			case 2:
				subtract_driver(); break;
			case 3:
				multiply_driver(); break;
			case 4:
				gaussian_elimination_driver();	break;
			case 5:
				rref_driver();	break;
			case 6:
				trace_driver();	break;
			case 7:
				transpose_driver();	break;
			case 8:
				rank_driver(); break;
			case 9:
				det_driver(); break;
			default:
				printf("No operation choosen");
			}

		// Ask user if they want to run again
		printf("Start another operation? (1 for yes, 0 for no): ");
		scanf("%i", &loop);
		while(loop != 1 && loop != 0) {
			printf("Start another operation? (1 for yes, 0 for no): ");
			scanf("%i", &loop);
		}
	}
}

