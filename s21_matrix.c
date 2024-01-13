#include "s21_matrix.h"

// int main() {
//   matrix_t matrix;
//   s21_create_matrix(-1, 1, &matrix);
//   s21_fill_matrix(&matrix);
//   s21_print_matrix(&matrix);
//   s21_remove_matrix(&matrix);

//   return 0;
// }

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || result->matrix == NULL || rows < 1 || columns < 1)
    return INCORRECT_MATRIX;
  int res = OK;
  result->matrix = calloc(rows, sizeof(double *));
  if (result->matrix != NULL) {
    for (int count = 0; count < rows; count++) {
      result->matrix[count] = calloc(columns, sizeof(double));
      if (result->matrix[count] == NULL) res = INCORRECT_MATRIX;
    }
    result->rows = rows;
    result->columns = columns;
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if ((s21_this_is_null(A) || s21_row_or_col_err(A)) != INCORRECT_MATRIX) {
    for (int count = 0; count < A->rows; count++) {
      free(A->matrix[count]);
    }
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
  if (s21_this_is_null(A) || s21_row_or_col_err(A) || s21_this_is_null(B) ||
      s21_this_is_null(B))
    return FAILURE;
  int res = SUCCESS;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      if (A->matrix[row][column] != B->matrix[row][column]) res = FAILURE;
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_this_is_null(A) || s21_row_or_col_err(A) || s21_this_is_null(B) ||
      s21_row_or_col_err(B) || s21_this_is_null(result) ||
      s21_row_or_col_err(result))
    return INCORRECT_MATRIX;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    return CALCULATION_ERROR;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] + B->matrix[row][column];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_this_is_null(A) || s21_row_or_col_err(A) || s21_this_is_null(B) ||
      s21_row_or_col_err(B) || s21_this_is_null(result) ||
      s21_row_or_col_err(result))
    return INCORRECT_MATRIX;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    return CALCULATION_ERROR;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] - B->matrix[row][column];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_this_is_null(A) || s21_row_or_col_err(A) ||
      s21_this_is_null(result) || s21_row_or_col_err(result))
    return INCORRECT_MATRIX;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] = A->matrix[row][column] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_this_is_null(A) || s21_row_or_col_err(A) || s21_this_is_null(B) ||
      s21_row_or_col_err(B) || s21_this_is_null(result) ||
      s21_row_or_col_err(result))
    return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[A->rows][B->columns] +=
            A->matrix[row][k] * B->matrix[k][column];
      }
    }
  }
  return OK;
}

int s21_this_is_null(matrix_t *A) {
  int res = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    res = INCORRECT_MATRIX;
  } else {
    for (int row = 0; row < A->rows; row++) {
      if (A->matrix[row] == NULL) res = INCORRECT_MATRIX;
    }
  }
  return res;
}

int s21_row_or_col_err(matrix_t *A) {
  int res = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    res = INCORRECT_MATRIX;
  return res;
}