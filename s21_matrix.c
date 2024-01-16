#include "s21_matrix.h"

int main() {
  matrix_t A;
  double result = 0;
  s21_determinant(&A, &result);
  int rows = 3, columns = 3;
  char *src_1 = "1 2 3 4 5 6 7 8 9";
  s21_create_matrix(rows, columns, &A);
  s21_fill_matrix(&A, src_1);
  s21_determinant(&A, &result);
  printf("%f", result);
  s21_remove_matrix(&A);
  return 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows < 1 || columns < 1) return INCORRECT_MATRIX;
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

void s21_fill_matrix(matrix_t *A, char *src) {
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      sscanf(src, "%lf ", &(A->matrix[row][column]));
      src += strcspn(src, " ") + 1;
    }
  }
}

void s21_print_matrix(matrix_t *A) {
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      printf("%0.7lf ", A->matrix[row][column]);
    }
    printf("\n");
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (s21_not_same_size(A, B) || s21_is_inf_or_nan(A) || s21_is_inf_or_nan(B))
    return FAILURE;
  int res = SUCCESS;
  for (int row = 0; row < A->rows && res != FAILURE; row++) {
    for (int column = 0; column < A->columns && res != FAILURE; column++) {
      if (fabsl(A->matrix[row][column] - B->matrix[row][column]) >= ACCURACY)
        res = FAILURE;
    }
  }
  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_not_same_size(A, B) || s21_is_inf_or_nan(A) || s21_is_inf_or_nan(B))
    return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] + B->matrix[row][column];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_not_same_size(A, B) || s21_is_inf_or_nan(A) || s21_is_inf_or_nan(B))
    return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] =
          A->matrix[row][column] - B->matrix[row][column];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_is_inf_or_nan(A) || number != number || number == INFINITY ||
      number == -INFINITY)
    return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[row][column] = A->matrix[row][column] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_is_inf_or_nan(A) || s21_is_inf_or_nan(B)) return CALCULATION_ERROR;
  if (A->columns != B->rows) return INCORRECT_MATRIX;
  s21_create_matrix(A->rows, B->columns, result);
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < B->columns; column++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[row][column] += A->matrix[row][k] * B->matrix[k][column];
      }
    }
  }
  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  s21_create_matrix(A->columns, A->rows, result);
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      result->matrix[column][row] = A->matrix[row][column];
    }
  }
  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  matrix_t B;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  int count = A->rows, sum = 0;
  while (count != 3) {
    count--;
    for (int size = 0; size < count; size++) {
      s21_create_matrix(count, count, &B);
      s21_determinant_copy(A, &B);
      *result +=
          pow(-1, size + 2) * A->matrix[0][size] * s21_determinant(&B, result);
    }
  }
  *result += s21_determinant_3(A);
  return OK;
}

void s21_determinant_copy(matrix_t *A, matrix_t *B) {
  for (int row = 1; row < A->rows; row++) {
    for (int column = 1; column < A->columns; column++) {
      B->matrix[row][column] = A->matrix[row][column];
    }
  }
}

int s21_determinant_3(matrix_t *A) {
  int determinant = 0;
  s21_print_matrix(A);
  for (int size = 0; size < 3; size++) {
    determinant +=
        pow(-1, size + 2) * A->matrix[0][size] *
        (A->matrix[1][1 - (size / 2)] * A->matrix[2][2 - (size / 2)] -
         A->matrix[2][1 - (size / 2)] * A->matrix[1][2 - (size / 2)]);
  }
  return determinant;
}

// int s21_calc_complements(matrix_t *A, matrix_t *result) {
//    return;
// }

int s21_this_is_null(matrix_t *A) {
  int res = OK;
  if ((A == NULL) || (A->matrix == NULL)) {
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
  if ((A != NULL) || (A->matrix != NULL)) {
    if (A->rows < 1 || A->columns < 1) res = INCORRECT_MATRIX;
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}

int s21_not_same_size(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) return INCORRECT_MATRIX;
  return OK;
}

int s21_is_inf_or_nan(matrix_t *A) {
  int res = OK;
  for (int row = 0; row < A->rows && res != CALCULATION_ERROR; row++) {
    for (int column = 0; column < A->columns && res != CALCULATION_ERROR;
         column++) {
      if (A->matrix[row][column] != A->matrix[row][column] ||
          A->matrix[row][column] == INFINITY ||
          A->matrix[row][column] == -INFINITY)
        res = CALCULATION_ERROR;
    }
  }
  return res;
}