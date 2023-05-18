#include <stdio.h>
#include "matrix.h"


int main() {
  int a[10][10], b[10][10], c[10][10];
  int row1, col1, row2, col2, i, j;

  // Введення даних для першої матриці
  printf("Введіть розмірність першої матриці: ");
  scanf("%d%d", &row1, &col1);

  printf("Введіть елементи матриці:\n");
  readMatrix(a, row1, col1);

  // Введення даних для другої матриці
  printf("Введіть розмірність другої матриці: ");
  scanf("%d%d", &row2, &col2);

  printf("Введіть елементи матриці:\n");
  readMatrix(b, row2, col2);

  // Перевірка, чи можливе множення матриць
  if (!canMultiplyMatrices(col1, row2)) {
    printf("Помилка: неможливо помножити матриці з такими розмірами.\n");
  } else {
    // Множення матриць
    matrixMultiply(a, b, c, row1, col1, row2, col2);

    // Виведення результату
    printf("Результат множення матриць:\n");
    for (i = 0; i < row1; i++) {
      for (j = 0; j < col2; j++) {
        printf("%d ", c[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}