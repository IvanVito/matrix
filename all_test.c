#include "s21_matrix.h"

START_TEST(test_s21_sub) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  num_1.bits[0] = 7777777;
  num_2.bits[0] = 7777776;
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+1,";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub1) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 31);
  s21_set_bit(&num_1, 32);
  s21_set_bit(&num_2, 60);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "-1152921498164396032,";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub2) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 31);
  s21_set_bit(&num_1, 32);
  s21_set_bit(&num_2, 60);
  s21_set_bit(&num_2, 127);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+1152921511049297920,";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub3) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 94);
  s21_set_bit(&num_2, 93);
  s21_set_bit(&num_2, 127);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+29710560942849126597578981376,";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub4) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 93);
  s21_set_bit(&num_2, 93);
  s21_set_bit(&num_2, 116);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+8913168282854737979273694412,8";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub5) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 70);
  s21_set_bit(&num_1, 117);
  s21_set_bit(&num_2, 27);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+11805916207039895306,24";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub6) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 12);
  s21_set_bit(&num_1, 119);
  s21_set_bit(&num_2, 12);
  s21_set_bit(&num_2, 119);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "+,00000000";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

START_TEST(test_s21_sub7) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 95);
  s21_set_bit(&num_1, 94);
  s21_set_bit(&num_1, 93);
  s21_set_bit(&num_2, 95);
  s21_set_bit(&num_1, 127);
  ck_assert_int_eq(s21_sub(num_1, num_2, &bcd), 1);
}
END_TEST

START_TEST(test_s21_sub8) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 95);
  s21_set_bit(&num_1, 94);
  s21_set_bit(&num_1, 93);
  s21_set_bit(&num_1, 116);
  s21_set_bit(&num_2, 95);
  ck_assert_int_eq(s21_sub(num_1, num_2, &bcd), 0);
}
END_TEST

START_TEST(test_s21_sub9) {
  s21_decimal num_1 = {0}, num_2 = {0}, bcd = {0};
  s21_set_bit(&num_1, 0);
  s21_set_bit(&num_1, 121);
  s21_set_bit(&num_1, 119);
  s21_set_bit(&num_1, 127);
  s21_set_bit(&num_2, 0);
  s21_set_bit(&num_2, 121);
  s21_set_bit(&num_2, 119);
  s21_sub(num_1, num_2, &bcd);
  char *answer = "-,0000000000000000000000000002";
  ck_assert_str_eq(s21_res_number_str(&bcd), answer);
}
END_TEST

Suite *s21_decimal_s21_sub() {
  Suite *result;
  TCase *tc_s21_sub;

  result = suite_create("s21_sub");
  tc_s21_sub = tcase_create("s21_sub");

  tcase_add_test(tc_s21_sub, test_s21_sub);
  tcase_add_test(tc_s21_sub, test_s21_sub1);
  tcase_add_test(tc_s21_sub, test_s21_sub2);
  tcase_add_test(tc_s21_sub, test_s21_sub3);
  tcase_add_test(tc_s21_sub, test_s21_sub4);
  tcase_add_test(tc_s21_sub, test_s21_sub5);
  tcase_add_test(tc_s21_sub, test_s21_sub6);
  tcase_add_test(tc_s21_sub, test_s21_sub7);
  tcase_add_test(tc_s21_sub, test_s21_sub8);
  tcase_add_test(tc_s21_sub, test_s21_sub9);

  suite_add_tcase(result, tc_s21_sub);

  return result;
}

int main() {
  int failed = 0;
  Suite *result[] = {s21_decimal_s21_sub(), NULL};

  for (int i = 0; result[i] != NULL; i++) {
    SRunner *runner = srunner_create(result[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
