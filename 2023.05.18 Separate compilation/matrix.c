#include <stdio.h>
#include "matrix.h"

int canMultiplyMatrices(int col1, int row2) { return col1 == row2; }

void matrixMultiply(int a[][10], int b[][10], int c[][10], int row1, int col1, int row2, int col2) {

  int i, j, k;

  // Обчислення добутку матриць
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      c[i][j] = 0;
      for (k = 0; k < col1; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}


void readMatrix(int matrix[][10], int row, int col) {
  int i, j;

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}