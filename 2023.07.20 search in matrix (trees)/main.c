#include <malloc.h>
#include <stdio.h>
#include <string.h>

char **createMatrix(int rows, int cols) {
  char **matrix = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++)
    matrix[i] = (char *)malloc(cols * sizeof(int));
  return matrix;
}

void deleteMatrix(char **matrix, int rows) {
  for (int i = 0; i < rows; i++)
    free(matrix[i]);
  free(matrix);
}

void fillTree(char **tree, int rows, int cols) {
  for (int i = 0; i < rows; i++)
    memset(tree[i], 0, sizeof(int) * cols);
  tree[0][1] = 1;
  tree[1][0] = 1;
  tree[0][2] = 1;
  tree[2][0] = 1;
  tree[2][3] = 1;
  tree[3][2] = 1;
}

void printMatrix(char **tree, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      printf("%3d", tree[i][j]);
    printf("\n");
  }
}

void printArray(char *ar, int size) {
  for (int i = 0; i < size; i++)
    printf("%4d", ar[i]);
  printf("\n");
}

int getCosts(char **tree, int rows, int cols, char prev, char cur, char depth,
             char maxdepth) {
  if (depth == maxdepth) {
    int k = 0;
    for (int i = 0; i < cols; i++)
      if (tree[cur][i] > 0)
        k++;
    return (k > 1) ? -1 : 1;
  }

  //    printf("%d %d\n", prev, cur);
  char *row = (char *)malloc(cols * sizeof(char));
  memset(row, 0, sizeof(char));
  for (int i = 0; i < cols; i++)
    if (tree[cur][i] > 0 && i != prev)
      row[i] = getCosts(tree, rows, cols, cur, i, depth = 1, maxdepth);
  int max = row[0];
  //    printf("%d\n", max);
  for (int i = 1; i < cols; i++) {
    if (row[i] == -1) {
      max = -1;
      break;
    } else if (row[i] > max)
      max = row[i];
  }
  //    printf("%d %d %d\n", prev, cur, max);
  if (prev > -1) {
    if (max != -1)
      max++;
    tree[cur][prev] = max;
    tree[prev][cur] = max;
  }
  //    printArray(row, cols);
  free(row);
  return max;
}

int longestWay(char **tree, int rows, int cols, char *way) {
  int cost;
  if ((cost = getCosts(tree, rows, cols, -1, 0, 0, 3)) == -1)
    return cost;
  //    printf("Matrix after transformation\n");
  //    printMatrix(tree, rows, cols);

  int i, k = cost;
  char cur = 0, index = 0;
  //    way = (char*)malloc((cost+1)*sizeof(char));
  way[index++] = 0;
  while (k > 0) {
    for (i = 0; i < cols && tree[cur][i] != k; i++)
      ;
    k--;
    way[index++] = i;
    cur = i;
  }
  return cost;
}

int main() {
  const int nodesCount = 4; // nodes count in the tree
  char **tree = createMatrix(nodesCount, nodesCount);
  char *way = (char *)malloc(nodesCount * sizeof(char));

  fillTree(tree, nodesCount, nodesCount);
  printMatrix(tree, nodesCount, nodesCount);
  printf("-------------------\n");
  int l;
  if ((l = longestWay(tree, nodesCount, nodesCount, way)) == -1) {
    printf("This is not a tree\n");
  } else {
    printf("Way length is %d\n", l);
    printf("Way is: ");
    printArray(way, l + 1);
  }

  deleteMatrix(tree, nodesCount);
  return 0;
}
