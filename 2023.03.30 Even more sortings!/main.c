#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>


void swap(int *array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void shuffle(int *array, int len) {
    for (int i = len-1; i > 0; i--) 
        swap(array, rand() % i, i);
}

int max(int *array, int len) {
    int max = array[0];
    for (int i = 0; i < len; i++) 
        if (array[i] > max) 
            max = array[i];
    return max;
}

/* count digits of number */
int digits(int num) {
    int d = 0;
    while (num > 0) {
        num /= 10; 
        d++;
    }
    return d; 
}

void fill(int *array, int len, int limit) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % limit;
}

void print(int *array, int len) {
    srand(time(NULL));
    for (int i = 0;i < len; i++) printf("%d ", array[i]);
}

int verifyArray(int *array, int len) {
    for (int i = 1; i < len; i++) 
        if (array[i-1] > array[i]) return -1;
    return 0;
}

int partition(int *array, int begin, int end) {
    int pivot = array[end];
    int i = begin - 1;
    for (int j = begin; j < end; j++)  
        if (array[j] <= pivot) 
            swap(array, j, ++i);
    
    swap(array, end, ++i);
    return i;
}

void quick_sort(int *array, int begin, int end) {
    if (begin < end) {
        int i = partition(array, begin, end);
        quick_sort(array, begin, i-1);
        quick_sort(array, i+1, end);
    }
}

void countingSort(int *array, int len) {
    int counters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < len; i++) counters[array[i]]++;
    int k = 0; 
    for (int i = 0; i < 10; i++) 
        for (int j = 0; j < counters[i]; j++) 
            array[k++] = i;
}

void bogoSort(int *array, int len) {
    while (verifyArray(array, len)) 
        shuffle(array, len);
}

void countingSortMod(int *array, int len, int slice) {
    int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int *out = (int*)calloc(len, sizeof(int));
    for (int i = 0; i < len; i++) count[array[i] / slice % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i-1];
    for (int i = len-1; i > -1; i--) out[--count[array[i] / slice % 10]] = array[i];
    for (int i = 0; i < len; i++ ) array[i] = out[i];
    free(out);
}

void radixSort(int *array, int len) {
    int slice = 1;
    for (int m = max(array, len); m/slice >= 1; slice *= 10)
        countingSortMod(array, len, slice);
} 

int main() {
    srand(time(NULL));
    int len = 20;
    int *array = (int*)calloc(sizeof(int), len);
    
    printf("\n filled : \n");
    fill(array, len, 320);
    print(array, len);

    printf("\n sorted : \n");
    //bogoSort(array, len);
    //quick_sort(array, 0, len-1);
    //countingSort(array, len);
    //radixSort(array, len);
    //countingSortMod(array, len, 1);

    radixSort(array, len);
    print(array, len);

    free(array);

    return 0; 
}

