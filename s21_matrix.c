#include "s21_matrix.h"

int main() {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  s21_fill_matrix(&matrix);
  s21_print_matrix(&matrix);
  s21_remove_matrix(&matrix);

  return 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || (rows < 1 || columns < 1)) return INCORRECT_MATRIX;
  int res = OK;
  result->matrix = calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    for (int count = 0; count < rows; count++) {
      result->matrix[count] = calloc(columns, sizeof(double));
      if (result->matrix[count] == NULL) res = INCORRECT_MATRIX;
    }
    result->rows = rows;
    result->columns = rows;
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if ((s21_this_is_null(A) || s21_row_or_col_err(A)) == 0) {
    for (int count = 0; count < A->rows; count++) free(A->matrix[count]);
    free(A->matrix);
  }
}

void s21_fill_matrix(matrix_t *A) {
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      scanf("%lf", &(A->matrix[row][column]));
    }
  }
}

void s21_print_matrix(matrix_t *A) {
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      printf("%7lf ", A->matrix[row][column]);
    }
    printf("\n");
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_this_is_null(A) || s21_row_or_col_err(A)) return FAILURE;
  int res = SUCCESS;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      if (A->matrix[row][column] != B->matrix[row][column]) res = FAILURE;
    }
  }
  return res;
}

int s21_this_is_null(matrix_t *A) {
  int res = 0;
  if (A == NULL) res = 1;
  for (int row = 0; row < A->rows; row++) {
    if (A->matrix[row] == NULL) res = 1;
  }
  return res;
}

int s21_row_or_col_err(matrix_t *A) {
  int res = 0;
  if (A->rows < 1 || A->columns < 1) res = 1;
  return res;
}