#include "s21_matrix.h"

START_TEST(test_s21_create_matrix) {
  matrix_t matrix_test;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &matrix_test);
  ck_assert_int_eq(matrix_test.rows, rows);
  ck_assert_int_eq(matrix_test.columns, columns);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      ck_assert_int_eq(matrix_test.matrix[row][column], 0);
    }
  }
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix1) {
  matrix_t matrix_test;
  int rows = 10, columns = 10;
  s21_create_matrix(rows, columns, &matrix_test);
  ck_assert_int_eq(matrix_test.rows, rows);
  ck_assert_int_eq(matrix_test.columns, columns);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      ck_assert_int_eq(matrix_test.matrix[row][column], 0);
    }
  }
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix2) {
  matrix_t matrix_test;
  int rows = 1, columns = 4;
  s21_create_matrix(rows, columns, &matrix_test);
  ck_assert_int_eq(matrix_test.rows, rows);
  ck_assert_int_eq(matrix_test.columns, columns);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      ck_assert_int_eq(matrix_test.matrix[row][column], 0);
    }
  }
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix3) {
  matrix_t matrix_test;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &matrix_test);
  ck_assert_int_eq(matrix_test.rows, rows);
  ck_assert_int_eq(matrix_test.columns, columns);
  for (int row = 0; row < rows; row++) {
    for (int column = 0; column < columns; column++) {
      ck_assert_int_eq(matrix_test.matrix[row][column], 0);
    }
  }
  s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix4) {
  matrix_t matrix_test;
  int rows = 1, columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix_test),
                   INCORRECT_MATRIX);
  // s21_remove_matrix(&matrix_test);
}
END_TEST

START_TEST(test_s21_create_matrix5) {
  matrix_t matrix_test;
  int rows = -1, columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix_test),
                   INCORRECT_MATRIX);
  // s21_remove_matrix(&matrix_test);
}
END_TEST

Suite *s21_matrix() {
  Suite *result;
  TCase *tc_s21_matrix;

  result = suite_create("s21_matrix");
  tc_s21_matrix = tcase_create("s21_matrix");

  tcase_add_test(tc_s21_matrix, test_s21_create_matrix);
  tcase_add_test(tc_s21_matrix, test_s21_create_matrix1);
  tcase_add_test(tc_s21_matrix, test_s21_create_matrix2);
  tcase_add_test(tc_s21_matrix, test_s21_create_matrix3);
  tcase_add_test(tc_s21_matrix, test_s21_create_matrix4);
  tcase_add_test(tc_s21_matrix, test_s21_create_matrix5);

  suite_add_tcase(result, tc_s21_matrix);

  return result;
}

int main() {
  int failed = 0;
  Suite *result[] = {s21_matrix(), NULL};

  for (int i = 0; result[i] != NULL; i++) {
    SRunner *runner = srunner_create(result[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
