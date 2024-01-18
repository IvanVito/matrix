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

Suite *create_matrix() {
  Suite *result;
  TCase *tc_s21_matrix_create;

  result = suite_create("s21_matrix_create");
  tc_s21_matrix_create = tcase_create("s21_matrix_create");

  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix);
  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix1);
  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix2);
  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix3);
  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix4);
  tcase_add_test(tc_s21_matrix_create, test_s21_create_matrix5);

  suite_add_tcase(result, tc_s21_matrix_create);

  return result;
}

START_TEST(test_s21_eq_matrix) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_2 = "1 2 3 4 5 6 7 8 9";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix1) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 0";
  char *src_2 = "1 2 3 4 5 6 7 8 9";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix2) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.132 2.6378 3.1214 4.24214";
  char *src_2 = "1.132 2.6378 3.1214 4.24214";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix3) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.132 2.6378 3.1214 4.24214";
  char *src_2 = "1.132 2.6379 3.1214 4.24214";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix4) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222222 3.3333333 4.4444444";
  char *src_2 = "1.1111111 2.2222222 3.3333333 4.4444444";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix5) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222222 3.3333333 4.4444444";
  char *src_2 = "1.1111111 2.2222225 3.3333333 4.4444444";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix6) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222222 3.3333333 4.4444444";
  char *src_2 = "1.1111111 2.2222222 3.3333333 4.4444444";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows - 1, columns - 1, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix7) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222222 3.3333333 4.4444444";
  char *src_2 = "1.1111111 2.2222222 3.3333333 4.4444444";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows + 1, columns + 1, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_eq_matrix8) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  int rows = 1, columns = 1;
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  matrix_test_1.matrix[0][0] = NAN;
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_test_1, &matrix_test_2), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

Suite *eq_matrix() {
  Suite *result;
  TCase *tc_s21_matrix_eq;

  result = suite_create("s21_matrix_eq");
  tc_s21_matrix_eq = tcase_create("s21_matrix_eq");

  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix1);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix2);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix3);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix4);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix5);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix6);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix7);
  tcase_add_test(tc_s21_matrix_eq, test_s21_eq_matrix8);

  suite_add_tcase(result, tc_s21_matrix_eq);

  return result;
}

START_TEST(test_s21_sum_matrix) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_2 = "9 8 7 6 5 4 3 2 1";
  char *src_res = "10 10 10 10 10 10 10 10 10";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix1) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222228 3.3 0.1234567";
  char *src_2 = "9.9999999 8.8888881 3.7 0.9876543";
  char *src_res = "11.1111110 11.1111109 7.0000000 1.1111110";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix2) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 1, columns = 2;
  char *src_1 = "1.1111111  2.2222228";
  char *src_2 = "9.9999999 8.8888881";
  char *src_res = "11.1111110 11.1111109";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix3) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_1 = "1.1111111";
  char *src_2 = "9.9999999 9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows + 1, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sum_matrix4) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222228 0.0000001 -0.0000001";
  char *src_2 = "9.9999999 8.8888881 0.0000001 -0.0000001";
  char *src_res = "11.1111110 11.1111109 0.0000002 -0.0000002";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix5) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_1 = "1.1111111 9.9999999";
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns + 1, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sum_matrix6) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  matrix_test_1.matrix[0][0] = INFINITY;
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sum_matrix7) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  matrix_test_1.matrix[0][0] = NAN;
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sum_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

Suite *sum_matrix() {
  Suite *result;
  TCase *tc_s21_matrix_sum;

  result = suite_create("s21_matrix_sum");
  tc_s21_matrix_sum = tcase_create("s21_matrix_sum");

  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix1);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix2);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix3);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix4);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix5);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix6);
  tcase_add_test(tc_s21_matrix_sum, test_s21_sum_matrix7);

  suite_add_tcase(result, tc_s21_matrix_sum);

  return result;
}

START_TEST(test_s21_sub_matrix) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_2 = "9 8 7 6 5 4 3 2 1";
  char *src_res = "-8 -6 -4 -2 0 2 4 6 8";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix1) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222228 3.3 0.1234567";
  char *src_2 = "9.9999999 8.8888881 3.7 0.9876543";
  char *src_res = "-8.8888888 -6.6666653 -0.4 -0.8641976";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix2) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 1, columns = 2;
  char *src_1 = "1.1111111  2.2222228";
  char *src_2 = "9.9999999 8.8888881";
  char *src_res = "-8.8888888 -6.6666653";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix3) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_1 = "1.1111111";
  char *src_2 = "9.9999999 9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows + 1, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sub_matrix4) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 2.2222228 0.0000001 -0.0000001";
  char *src_2 = "9.9999999 8.8888881 0.0000001 -0.0000001";
  char *src_res = "-8.8888888 -6.6666653 0.0000000 -0.0000000";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix5) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_1 = "1.1111111 9.9999999";
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns + 1, &matrix_test_1);
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sub_matrix6) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  matrix_test_1.matrix[0][0] = NAN;
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

START_TEST(test_s21_sub_matrix7) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t result;
  int rows = 1, columns = 1;
  char *src_2 = "9.9999999";
  s21_create_matrix(rows, columns, &matrix_test_1);
  matrix_test_1.matrix[0][0] = -INFINITY;
  s21_create_matrix(rows, columns, &matrix_test_2);
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_sub_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
}
END_TEST

Suite *sub_matrix() {
  Suite *result;
  TCase *tc_s21_matrix_sub;

  result = suite_create("s21_matrix_sub");
  tc_s21_matrix_sub = tcase_create("s21_matrix_sub");

  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix1);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix2);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix3);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix4);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix5);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix6);
  tcase_add_test(tc_s21_matrix_sub, test_s21_sub_matrix7);

  suite_add_tcase(result, tc_s21_matrix_sub);

  return result;
}

START_TEST(test_s21_mult_number) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = 7;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_res = "7 14 21 28 35 42 49 56 63";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number1) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = 7;
  int rows = 2, columns = 2;
  char *src_1 = "1.1111111 0.5555555 0.1 0";
  char *src_res = "7.7777777 3.8888885 0.7000000 0.0000000";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number2) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = 7;
  int rows = 1, columns = 2;
  char *src_1 = "1.1111111 0.5555555";
  char *src_res = "7.7777777 3.8888885";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number3) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = 0.0001;
  int rows = 1, columns = 1;
  char *src_1 = "0.001";
  char *src_res = "0.0000001";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number4) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = NAN;
  int rows = 1, columns = 1;
  char *src_1 = "0.001";
  char *src_res = "0.0000001";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
}
END_TEST

START_TEST(test_s21_mult_number5) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  double number = INFINITY;
  int rows = 1, columns = 1;
  char *src_1 = "0.001";
  char *src_res = "0.0000001";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(rows, columns, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_number(&matrix_test_1, number, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
}
END_TEST

Suite *mult_number() {
  Suite *result;
  TCase *tc_s21_mult_number;

  result = suite_create("s21_mult_number");
  tc_s21_mult_number = tcase_create("s21_mult_number");

  tcase_add_test(tc_s21_mult_number, test_s21_mult_number);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number1);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number2);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number3);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number4);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number5);
  suite_add_tcase(result, tc_s21_mult_number);

  return result;
}

START_TEST(test_s21_mult_matrix) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 3, columns_1 = 2, rows_2 = 2, columns_2 = 3;
  char *src_1 = "1 4 2 5 3 6";
  char *src_2 = "1 -1 1 2 3 4";
  char *src_res = "9 11 17 12 13 22 15 15 27";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix1) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 3, columns_1 = 2, rows_2 = 2, columns_2 = 3;
  char *src_1 = "1.0000001 4.004 0 -3.3 33 6";
  char *src_2 = "-1.1 -1.01 0 0 1 0.0000001";
  char *src_res =
      "-1.10000011 2.993999899 0.0000004004 0 -3.3 -0.00000033 -36.3 -27.33 "
      "0.0000006";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix2) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 3, columns_1 = 2, rows_2 = 3, columns_2 = 3;
  char *src_1 = "1.0000001 4.004 0 -3.3 33 6";
  char *src_2 = "-1.1 -1.01 0 0 1 0.0000001";
  char *src_res =
      "-1.10000011 2.993999899 0.0000004004 0 -3.3 -0.00000033 -36.3 -27.33 "
      "0.0000006";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
}
END_TEST

START_TEST(test_s21_mult_matrix3) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 2, columns_1 = 1, rows_2 = 1, columns_2 = 2;
  char *src_1 = "0 1";
  char *src_2 = "1 1";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  matrix_test_1.matrix[0][0] = NAN;
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
}
END_TEST

START_TEST(test_s21_mult_matrix4) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 2, columns_1 = 1, rows_2 = 1, columns_2 = 2;
  char *src_1 = "0 1";
  char *src_2 = "1 1";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  matrix_test_1.matrix[0][0] = INFINITY;
  s21_fill_matrix(&matrix_test_2, src_2);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
}
END_TEST

START_TEST(test_s21_mult_matrix5) {
  matrix_t matrix_test_1;
  matrix_t matrix_test_2;
  matrix_t expect_result;
  matrix_t result;
  int rows_1 = 3, columns_1 = 3, rows_2 = 2, columns_2 = 3;
  char *src_1 = "1.0000001 4.004 0 -3.3 33 6";
  char *src_2 = "-1.1 -1.01 0 0 1 0.0000001";
  char *src_res =
      "-1.10000011 2.993999899 0.0000004004 0 -3.3 -0.00000033 -36.3 -27.33 "
      "0.0000006";
  s21_create_matrix(rows_1, columns_1, &matrix_test_1);
  s21_create_matrix(rows_2, columns_2, &matrix_test_2);
  s21_create_matrix(rows_1, columns_2, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&matrix_test_2, src_2);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_mult_matrix(&matrix_test_1, &matrix_test_2, &result),
                   CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&matrix_test_2);
  s21_remove_matrix(&expect_result);
}
END_TEST

Suite *mult_matrix() {
  Suite *result;
  TCase *tc_s21_mult_matrix;

  result = suite_create("s21_mult_matrix");
  tc_s21_mult_matrix = tcase_create("s21_mult_matrix");

  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix1);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix2);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix3);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix4);
  tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix5);
  suite_add_tcase(result, tc_s21_mult_matrix);

  return result;
}

START_TEST(test_s21_transpose) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_res = "1 4 7 2 5 8 3 6 9";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(columns, rows, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_transpose(&matrix_test_1, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose1) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  char *src_res = "1 4 7 2 5 8 3 6 91";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(columns, rows, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_transpose(&matrix_test_1, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), FAILURE);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose2) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  int rows = 2, columns = 3;
  char *src_1 = "1.2222221 2.1111112 0 0.1111112 1234567 1234567.1234567";
  char *src_res = "1.2222221 0.1111112 2.1111112 1234567 0 1234567.1234567";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(columns, rows, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_transpose(&matrix_test_1, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose3) {
  matrix_t matrix_test_1;
  matrix_t expect_result;
  matrix_t result;
  int rows = 3, columns = 2;
  char *src_1 = "1.2222221 2.1111112 0 0.1111112 1234567 1234567.1234567";
  char *src_res = "1.2222221 0 1234567 2.1111112 0.1111112 1234567.1234567";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_create_matrix(columns, rows, &expect_result);
  s21_fill_matrix(&matrix_test_1, src_1);
  s21_fill_matrix(&expect_result, src_res);
  ck_assert_int_eq(s21_transpose(&matrix_test_1, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expect_result), SUCCESS);
  s21_remove_matrix(&matrix_test_1);
  s21_remove_matrix(&expect_result);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_transpose() {
  Suite *result;
  TCase *tc_s21_transpose;

  result = suite_create("s21_transpose");
  tc_s21_transpose = tcase_create("s21_transpose");

  tcase_add_test(tc_s21_transpose, test_s21_transpose);
  tcase_add_test(tc_s21_transpose, test_s21_transpose1);
  tcase_add_test(tc_s21_transpose, test_s21_transpose2);
  tcase_add_test(tc_s21_transpose, test_s21_transpose3);
  suite_add_tcase(result, tc_s21_transpose);

  return result;
}

START_TEST(test_s21_determinant) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant1) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 3, columns = 3;
  char *src_1 = "1.22 9.12 4.71 2.01 0.001 5.1 3.5 7.1 6.8";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 61.171861, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant2) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 3, columns = 3;
  char *src_1 = "0 0 0 2.01 0.001 5.1 3.5 7.1 6.8";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant3) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 3, columns = 3;
  char *src_1 = "0 9.12 4.71 0 0.001 5.1 0 7.1 6.8";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 0, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant4) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 2, columns = 2;
  char *src_1 = "2 4 6 9";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, -6, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant5) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 2, columns = 2;
  char *src_1 = "2.325 4.1356 6.6864 6.6864";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, -12.1063958, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant6) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 4, columns = 4;
  char *src_1 = "4 7 8 8 2 4 0 -1 1 7 -4 1 3 4 1 8";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 789, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant7) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 4, columns = 4;
  char *src_1 =
      "4.6432156 7.1355790 8.2668075 8.7422688 2.1790467 4.08956326 0 "
      "-1.2477996 1.46895357 7.1895326 -4.2565775 1.3674785 3.7446284 "
      "4.2642367 1.0936941 8.0149754";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), OK);
  ck_assert_double_eq_tol(result, 935.8920714, 1e-7);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

START_TEST(test_s21_determinant8) {
  matrix_t matrix_test_1;
  double result = 0;
  int rows = 3, columns = 4;
  char *src_1 =
      "4.6432156 7.1355790 8.2668075 8.7422688 2.1790467 4.08956326 0 "
      "-1.2477996 1.46895357 7.1895326 -4.2565775 1.3674785 0";
  s21_create_matrix(rows, columns, &matrix_test_1);
  s21_fill_matrix(&matrix_test_1, src_1);
  ck_assert_int_eq(s21_determinant(&matrix_test_1, &result), CALCULATION_ERROR);
  s21_remove_matrix(&matrix_test_1);
}
END_TEST

Suite *determinant() {
  Suite *result;
  TCase *tc_s21_determinant;

  result = suite_create("s21_determinant");
  tc_s21_determinant = tcase_create("s21_determinant");

  tcase_add_test(tc_s21_determinant, test_s21_determinant);
  tcase_add_test(tc_s21_determinant, test_s21_determinant1);
  tcase_add_test(tc_s21_determinant, test_s21_determinant2);
  tcase_add_test(tc_s21_determinant, test_s21_determinant3);
  tcase_add_test(tc_s21_determinant, test_s21_determinant4);
  tcase_add_test(tc_s21_determinant, test_s21_determinant5);
  tcase_add_test(tc_s21_determinant, test_s21_determinant6);
  tcase_add_test(tc_s21_determinant, test_s21_determinant7);
  tcase_add_test(tc_s21_determinant, test_s21_determinant8);
  suite_add_tcase(result, tc_s21_determinant);

  return result;
}

int main() {
  int failed = 0;
  Suite *result[] = {create_matrix(),  eq_matrix(),   sum_matrix(),
                     sub_matrix(),     mult_number(), mult_matrix(),
                     mult_transpose(), determinant(), NULL};

  for (int i = 0; result[i] != NULL; i++) {
    SRunner *runner = srunner_create(result[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
