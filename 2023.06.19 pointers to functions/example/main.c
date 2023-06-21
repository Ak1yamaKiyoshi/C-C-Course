#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

typedef int* ( *sortFunc )(int *arr, int len); 

int* bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    return arr;
}

int* insertionSort(int *arr, int len) {
    for (int j = 0, min, minIndex, num; j < len; j++) {
        for (int i = j; i < len; i++) 
            if (i == j || min > arr[i]) {
                min = arr[i];
                minIndex = i; 
            }
        num = arr[minIndex];
        arr[minIndex] = arr[j];
        arr[j] = num;
    }
    return arr;
}

int* sorter(int *arr, int len, sortFunc func) {
    return func(arr, len); 
}

int* fill(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % len;
    return array;
}

void print(int *array, int len) {
    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf(" %d", *ptr);
    }
}


int main() {
    sortFunc f = bubbleSort;
    
    int len = 4;
    int *array = (int*)malloc(sizeof(int*)*len);

    printf(" > Filled: ");
    print( fill(array, len), len );
    printf("\n > Sorted With bubbleSort: ");
    print( sorter(array, len, bubbleSort), len);
    printf("\n\n > Filled: ");
    print( fill(array, len), len );
    printf("\n > Sorted With insertionSort: ");
    print( sorter(array, len, insertionSort), len);
    printf("\n\n > Filled: ");
    print( fill(array, len), len );
    printf("\n > Sorted With f: ");
    print( sorter(array, len, f), len);

    free(array);

    return 0;
}
