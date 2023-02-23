#include <malloc.h>
#include <stdio.h>


int main() {
    
    int cols=2, rows=5;

    // allocating 
    int **array = (int**)calloc(sizeof(int*));
    for (int i = 0; i < cols; i++) {
        array[i] = (int*)calloc(sizeof(int*)*rows);
    }

    /* some code */

    // deallocating 
    for (int i = 0; i < cols; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
