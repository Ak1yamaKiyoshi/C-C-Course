#include <stdio.h>
#include <malloc.h>


void fillSeq(int **array, int len){
    int i = 1; 
    for (int y = 0; y < len; y++)
        for (int x = 0; x < len; x++) {
            array[y][x] = i;
            i++; 
        }
}

void printTable(int **array, int len){
    for (int y = 0; y < len; y++) {
        for (int x = 0; x < len; x++) 
            printf("%4d", array[y][x]);
        printf("\n");
    }
}

void swap(int **arr, int aY, int aX, int bY, int bX) {
    int temp = arr[aY][aX];
    arr[aY][aX] = arr[bY][bX];
    arr[bY][bX] = temp;
}

// reverses each row of array
void transpose(int **array, int len) {
    int temp;
    for (int x = 0; x < len/2; x++)
        for (int y = 0; y < len; y++) {
            
            temp = array[y][x];
            array[y][x] = array[y][len-x-1];
            array[y][len-x-1] = temp;   
        }
}

void TRotate90AntiClockwise(int **array, int len) {
  transpose(array, len);
  for (int y = 0; y < len; y++) 
    for (int x = y; x < len; x++) 
      swap(array, x, y, y, x);
}

void MRotate90AntiClockwise(int **array, int len) {
    int arrayB[len][len];
    int i;
    for (int y = len-1, i = 0; y >= 0;i++, y--) 
        for (int x = len-1; x >= 0; x--) 
            arrayB[y][x] = array[x][i];
    for (int y = len-1; y >= 0; y--) 
        for (int x = len-1; x >= 0; x--) 
            array[y][x] = arrayB[y][x];
}

int rotate90Clockwise(int **array, int len) {
    for (int y = 0; y < len; y++) 
        for (int x = y; x < len; x++) 
            swap(array, x, y, y, x);
  transpose(array, len);
}

void rotate180Clockwise(int **array, int len) { 
    for (int y=0, y1=len-1; y < len/2; y++, y1--)
        for (int x=0, x1=len-1; x < len; x++, x1--) {
            swap(array, y1, x1, y, x);
        }
}

void calcTable(int **array, int len){
    int sumRow = 0;
    int sumColumn = 0;
    int x, y;
    for ( y = 0; y < len; y++) {
        sumRow = 0;
        sumColumn = 0;
        for (x = 0; x < len; x++) {
            sumRow += array[y][x];
            sumColumn += array[x][y];
        }
        printf("\n");
        printf("%d column sum: %d\n", y, sumRow);
        printf("%d row sum: %d", y,  sumColumn);
    }
}

void findMatrixMax(int **array, int len, int * max) {
    max[0] = 0, max[1] = 0;
    for (int y = 0; y < len; y++) 
        for (int x = 0; x < len; x++) 
            if (array[y][x] > array[max[0]][max[1]]) {
                max[0] = y; 
                max[1] = x;
            }
}

void swapFirstLastColumn(int **array, int len) {
    int temp;
    for (int y = 0; y < len; y++) {
            temp = array[y][0];
            array[y][0] = array[y][len-1];
            array[y][len-1] = temp;
    }
}


int main()
{

    int len = 4;
    int **array = (int**)calloc(sizeof(int*), len);
    for (int i = 0; i < len; i++) 
        array[i] = (int*)calloc(sizeof(int), len);

    fillSeq(array, len);
    printf("fillSeq \n");
    printTable(array, len);

    rotate90Clockwise(array, len);
    printf("rotate90Clockwise \n");
    printTable(array, len);
    
    MRotate90AntiClockwise(array, len);
    printf("MRotate90AntiClockwise \n");
    printTable(array, len);

    TRotate90AntiClockwise(array, len);
    printf("TRotate90AntiClockwise \n");
    printTable(array, len);

    transpose(array, len);
    printf("transpose \n");
    printTable(array, len);

    swapFirstLastColumn(array, len);
    printf("swapFirstLastColumn \n");
    printTable(array, len);

    rotate180Clockwise(array, len);
    printf("rotate180Clockwise \n");
    printTable(array, len);

    calcTable(array, len);

    int max[2];
    findMatrixMax(array, len, max);
    printf("\n max elem %d, y:%d x:%d", array[max[0]][max[1]], max[0], max[1]);

    for (int i = 0; i < len; i++) 
        free(array[i]);
    free(array);

    return 0;
}
