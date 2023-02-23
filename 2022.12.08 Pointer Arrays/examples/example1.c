#include <stdio.h>
#include <malloc.h> 


int main() {
    
    int cols = 5; 
    int rows = 5;

    int *array = (int*)calloc(sizeof(int*), cols*rows);

    int c = 1;
    for (int *ptr = array; ptr < array+((rows-1)*(cols-1));  ptr++) {
        *ptr = c++;
    }
    
    for (int *ptr = array, i=1; ptr < array+(rows-1)*(cols-1);i++,  ptr++) {
        printf(" %2d ", *ptr);
        if (i % (rows-1) == 0) 
            printf("\n");
    }

    free(array);

    return 0;
}
