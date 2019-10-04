#include <check.h>
#include "../src/header.h"

int compare_matrix(float**, float**, int, int);

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
			if(arr1[i][j] != arr2[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}
