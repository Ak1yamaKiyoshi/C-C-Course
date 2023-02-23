#include <malloc.h>
#include <stdio.h>


void fill(int **array, int rows, int cols){
    int i = 1; 
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            array[y][x] = i;
            i++; 
        }
    }
}

void print(int **array, int rows, int cols){
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            printf("%4d", array[y][x]);
        }
        printf("\n");
    }
}

void transform(int **array, int rows, int cols) {
    for (int y=0, y1=rows-1; y < rows/2; y++, y1--)
        for (int x=0, x1=cols-1; x < cols; x++, x1--) {
            int temp = *(*(array+y)+x);
            *(*(array+y)+x) = *(*(array+y1)+x1);
            *(*(array+y1)+x1) = temp;
        }
}



int main() {
    
    int cols=2, rows=5;

    // allocating 
    int **array = (int**)calloc(sizeof(int**), rows);
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)calloc(sizeof(int), cols);
    }

    fill(array, rows, cols);
    print(array, rows, cols);

    // deallocating 
    for (int i = 0; i < cols; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
