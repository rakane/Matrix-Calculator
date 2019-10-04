#include <check.h>
#include "../src/header.h"

int compare_matrix(float**, float**, int, int);
int compare_solutions(float*, float*, int);

START_TEST(add_test1) 
{
	float** arr1 = allocate_matrix(1, 1);
	float** arr2 = allocate_matrix(1, 1);
	float** correct_arr = allocate_matrix(1,1);
	arr1[0][0] = 1.00;
	arr2[0][0] = 3.00;
	correct_arr[0][0] = 4.00;
	float** new_arr = add(arr1, arr2, 1, 1);
	ck_assert(compare_matrix(new_arr, correct_arr, 1, 1));
}
END_TEST

START_TEST(add_test2) 
{
	float** arr1 = allocate_matrix(2, 2);
	float** arr2 = allocate_matrix(2, 2);
	float** correct_arr = allocate_matrix(1,1);
	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[1][0] = 3;
	arr1[1][1] = 4;
	arr2[0][0] = 1;
	arr2[0][1] = 2;
	arr2[1][0] = 3;
	arr2[1][1] = 4;
	correct_arr[0][0] = 2; 
	correct_arr[0][1] = 4;
	correct_arr[1][0] = 6;
	correct_arr[1][1] = 8;
	float** new_arr = add(arr1, arr2, 2, 2);
	ck_assert(compare_matrix(new_arr, correct_arr, 2, 2));
}
END_TEST

START_TEST(subtract_test1) 
{
	float** arr1 = allocate_matrix(1, 1);
	float** arr2 = allocate_matrix(1, 1);
	float** correct_arr = allocate_matrix(1,1);
	arr1[0][0] = 1.00;
	arr2[0][0] = 3.00;
	correct_arr[0][0] = -2.00;
	float** new_arr = subtract(arr1, arr2, 1, 1);
	ck_assert(compare_matrix(new_arr, correct_arr, 1, 1));
}
END_TEST

START_TEST(subtract_test2) 
{
	float** arr1 = allocate_matrix(2, 2);
	float** arr2 = allocate_matrix(2, 2);
	float** correct_arr = allocate_matrix(2,2);
	arr1[0][0] = 1;
	arr1[0][1] = 2;
	arr1[1][0] = 3;
	arr1[1][1] = 4;
	arr2[0][0] = 1;
	arr2[0][1] = 2;
	arr2[1][0] = 3;
	arr2[1][1] = 4;
	correct_arr[0][0] = 0; 
	correct_arr[0][1] = 0;
	correct_arr[1][0] = 0;
	correct_arr[1][1] = 0;
	float** new_arr = subtract(arr1, arr2, 2, 2);
	ck_assert(compare_matrix(new_arr, correct_arr, 2, 2));
}
END_TEST

START_TEST(multiply_test1)
{
	float** arr1 = allocate_matrix(1, 1);
	float** arr2 = allocate_matrix(1, 1);
	float** correct_arr = allocate_matrix(1, 1);
	arr1[0][0] = 5.0;
	arr2[0][0] = -10.0;
	correct_arr[0][0] = -50.0;
	float** new_arr = multiply(arr1, arr2, 1, 1, 1, 1);
	ck_assert(compare_matrix(new_arr, correct_arr, 1, 1));
} END_TEST

START_TEST(multiply_test2) 
{
	float** arr1 = allocate_matrix(2, 3);
	float** arr2 = allocate_matrix(3, 4);
	float** correct_arr = allocate_matrix(2, 4);
	arr1[0][0] = 5.0;
	arr1[0][1] = 10.0;
	arr1[0][2] = 4.0;
	arr1[1][0] = -2.0;
	arr1[1][1] = -9.0;
	arr1[1][2] = 1.0;
	arr2[0][0] = -5.0;
	arr2[0][1] = -20.0;
	arr2[0][2] = 30.0;
	arr2[0][3] = 2.0;
	arr2[1][0] = 8.0;
	arr2[1][1] = -1.0;
	arr2[1][2] = 3.0;
	arr2[1][3] = 7.0 ;
	arr2[2][0] = -4.0;
	arr2[2][1] = -9.0;
	arr2[2][2] = 10.0;
	arr2[2][3] = 0.0;
	correct_arr[0][0] = 39;
	correct_arr[0][1] = -146;
	correct_arr[0][2] = 220;
	correct_arr[0][3] = 80;
	correct_arr[1][0] = -66;
	correct_arr[1][1] = 40;
	correct_arr[1][2] = -77;
	correct_arr[1][3] = -67;

	float** new_arr = multiply(arr1, arr2, 2, 3, 3, 4);
	ck_assert(compare_matrix(new_arr, correct_arr, 2, 4));
} END_TEST

START_TEST(elimination_test1)
{	
	float *X = malloc(sizeof(float) * 2);
	float *correct_solution = malloc(sizeof(float) * 2);
	float** arr = allocate_matrix(2, 3);
	arr[0][0] = 1.0;
	arr[0][1] = 1.0;
	arr[0][2] = 0.0;
	arr[1][0] = 4.0;
	arr[1][1] = 2.0;
	arr[1][2] = 10.0;
	correct_solution[0] = 5.0;
	correct_solution[1] = -5.0;
	X = gaussian_elimination(arr, 2, 3);
	ck_assert(compare_solutions(X, correct_solution, 2));
} END_TEST

START_TEST(elimination_test2)
{
	float *X = malloc(sizeof(float) * 3);
	float *correct_solution = malloc(sizeof(float) * 3);
	float** arr = allocate_matrix(3, 4);
	arr[0][0] = 1.0;
	arr[0][1] = -2.0;
	arr[0][2] = 9.0;
	arr[0][3] = 8.0;
	arr[1][0] = 3.0;
	arr[1][1] = 1.0;
	arr[1][2] = -1.0;
	arr[1][3] = 3.0;
	arr[2][0] = 2.0;
	arr[2][1] = -8.0;
	arr[2][2] = 1.0;
	arr[2][3] = -5.0;
	correct_solution[0] = 1.0;
	correct_solution[1] = 1.0;
	correct_solution[2] = 1.0;
	X = gaussian_elimination(arr, 3, 4);
	ck_assert(compare_solutions(X, correct_solution, 3));
} END_TEST

START_TEST(rref_test1)
{
	float** arr = allocate_matrix(2, 3);
	float** correct_arr = allocate_matrix(2, 3);
	arr[0][0] = 10.0;
	arr[0][1] = -4.0;
	arr[0][2] = 12.0;
	arr[1][0] = 5.0;
	arr[1][1] = 16.0;
	arr[1][2] = -3.0;
	correct_arr[0][0] = 1.0;
	correct_arr[0][1] = 0.0;
	correct_arr[0][2] = 1.0;
	correct_arr[1][0] = 0.0;
	correct_arr[1][1] = 1.0;
	correct_arr[1][2] = -0.5;
	float** new_arr = rref(arr, 2, 3);
	ck_assert(compare_matrix(new_arr, correct_arr, 2, 3));
} END_TEST

START_TEST(rref_test2)
{
	float** arr = allocate_matrix(4, 5);
	float** correct_arr = allocate_matrix(4, 5);
	arr[0][0] = 0.0;
	arr[0][1] = 0.0;
	arr[0][2] = 0.0;
	arr[0][3] = 0.0;
	arr[0][4] = 0.0;
   	arr[1][0] = -16.0;
	arr[1][1] = 4.0;
	arr[1][2] = 8.0;
	arr[1][3] = 12.0;
	arr[1][4] = 10.0;
	arr[2][0] = -1.0;
	arr[2][1] = 6.0;
	arr[2][2] = 12.0;
	arr[2][3] = -8.0;
	arr[2][4] = -12.0;
	arr[3][0] = 6.0;
	arr[3][1] = -3.0;
	arr[3][2] = -4.0;
	arr[3][3] = 10.0;
	arr[3][4] = 16.0;
	correct_arr[0][0] = 1.0;
	correct_arr[0][1] = 0.0;
	correct_arr[0][2] = 0.0;
	correct_arr[0][3] = -26.0 / 23.0;
	correct_arr[0][4] = -27.0 / 23.0;
	correct_arr[1][0] = 0.0;
	correct_arr[1][1] = 1.0;
	correct_arr[1][2] = 0.0;
	correct_arr[1][3] = -316.0 / 23.0;
	correct_arr[1][4] = -429.0 / 23.0;
	correct_arr[2][0] = 0.0;
	correct_arr[2][1] = 0.0;
	correct_arr[2][2] = 1.0;
	correct_arr[2][3] = 281.0 / 46.0;
	correct_arr[2][4] = 757.0 / 92.0;
	correct_arr[3][0] = 0.0;
	correct_arr[3][1] = 0.0;
	correct_arr[3][2] = 0.0;
	correct_arr[3][3] = 0.0;
	correct_arr[3][4] = 0.0;
	float** new_arr = rref(arr, 4, 5);
	ck_assert(compare_matrix(new_arr, correct_arr, 4, 5));
} END_TEST

START_TEST(trace_test1)
{
	float** arr = allocate_matrix(1, 1);
	int correct_answer = 4;
	arr[0][0] = 4;
	int	answer = trace(arr, 1, 1);
	ck_assert(answer == correct_answer);
} END_TEST

START_TEST(trace_test2)
{
	float** arr = allocate_matrix(3, 3);
	int correct_answer = 5;
	arr[0][0] = 1.0;
	arr[0][1] = 2.0;
	arr[0][2] = 3.0;
	arr[1][0] = 4.0;
	arr[1][1] = -5.0;
	arr[1][2] = 6.0;
	arr[2][0] = 7.0;
	arr[2][1] = 8.0;
	arr[2][2] = 9.0;
	int	answer = trace(arr, 3, 3);
	ck_assert(answer == correct_answer);
} END_TEST

START_TEST(transpose_test1)
{
	float** arr = allocate_matrix(1, 1);
	float** correct_arr = allocate_matrix(1 , 1);
	arr[0][0] = 1.0;
	correct_arr[0][0] = 1.0;
	float** new_arr = transpose(arr, 1);
	ck_assert(compare_matrix(new_arr, correct_arr, 1, 1));
} END_TEST

START_TEST(transpose_test2)
{
	float** arr = allocate_matrix(3, 3);
	float** correct_arr = allocate_matrix(3 , 3);
	arr[0][0] = 1.0;
	arr[0][1] = 2.0; 
	arr[0][2] = 3.0;
	arr[1][0] = 4.0;
	arr[1][1] = 5.0;
	arr[1][2] = 6.0;
	arr[2][0] = 7.0;
	arr[2][1] = 8.0;
	arr[2][2] = 9.0;
	correct_arr[0][0] = 1.0;
	correct_arr[0][1] =	4.0;
	correct_arr[0][2] = 7.0;
	correct_arr[1][0] = 2.0;
	correct_arr[1][1] = 5.0;
	correct_arr[1][2] = 8.0;
	correct_arr[2][0] = 3.0;
	correct_arr[2][1] = 6.0;
	correct_arr[2][2] = 9.0;
	float** new_arr = transpose(arr, 3);
	ck_assert(compare_matrix(new_arr, correct_arr, 3, 3));
} END_TEST

START_TEST(rank_test1)
{
	float** arr = allocate_matrix(2, 3);
	int correct_answer = 2;
	arr[0][0] = 10.0; 
	arr[0][1] = 6.0;
	arr[0][2] = 8.0;
	arr[1][0] = 4.0;
	arr[1][1] = -4.0;
	arr[1][2] = 3.0;
	int answer = rank(arr, 2, 3);
	ck_assert(answer == correct_answer);
} END_TEST

START_TEST(rank_test2)
{
	float** arr = allocate_matrix(4, 5);
	int correct_answer = 2;
	arr[0][0] = 0.0; 
	arr[0][1] = 0.0;
	arr[0][2] = 0.0;
	arr[0][3] = 0.0;
	arr[0][4] = 0.0;
	arr[1][0] = 4.0; 
	arr[1][1] = 2.0;
	arr[1][2] = 8.0;
	arr[1][3] = 10.0;
	arr[1][4] = 12.0;
	arr[2][0] = 0.0; 
	arr[2][1] = 0.0;
	arr[2][2] = 0.0;
	arr[2][3] = 0.0;
	arr[2][4] = 0.0;
	arr[3][0] = 14.0; 
	arr[3][1] = 18.0;
	arr[3][2] = 22.0;
	arr[3][3] = -14.0;
	arr[3][4] = 16.0;
	int answer = rank(arr, 4, 5);
	ck_assert(answer == correct_answer);
} END_TEST



Suite * test_suite(void)
{
	Suite *s;
	TCase *tc_core;
	s = suite_create("Basic");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, subtract_test1);
	tcase_add_test(tc_core, subtract_test2);
	tcase_add_test(tc_core, subtract_test1);
	tcase_add_test(tc_core, subtract_test2);
	tcase_add_test(tc_core, multiply_test1);
	tcase_add_test(tc_core, multiply_test2);
	tcase_add_test(tc_core, elimination_test1);
	tcase_add_test(tc_core, elimination_test2);
	tcase_add_test(tc_core, rref_test1);
	tcase_add_test(tc_core, rref_test2);
	tcase_add_test(tc_core, trace_test1);
	tcase_add_test(tc_core, trace_test2);
	tcase_add_test(tc_core, transpose_test1);
	tcase_add_test(tc_core, transpose_test2);
	tcase_add_test(tc_core, rank_test1);
	tcase_add_test(tc_core, rank_test2);

	suite_add_tcase(s, tc_core);
	return s;
}

int main(void)
{	
	int num_failed;
	Suite *s;
	SRunner *sr;
	
	s = test_suite();
	sr = srunner_create(s);
	
	srunner_run_all(sr, CK_NORMAL);
	num_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int compare_matrix(float** arr1, float** arr2, int rows, int columns)
{
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			if(abs(arr1[i][j] - arr2[i][j]) > .0099) {
				return 0;
			}
		}
	}
	return 1;
}

int compare_solutions(float* x1, float* x2, int rows) 
{
	for(int i = 0; i < rows; i++) {
		if(x1[i] != x2[i]) {
			return 0;
		}
	}
	return 1;
}

