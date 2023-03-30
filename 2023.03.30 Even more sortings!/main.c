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

void countingSortModified(int *array, int len, int slice) {
    int counters[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int ouput[] =    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < len; i++) counters[array[i]%slice]++;
    int k = 0; 
    
    for (int i = 0; i < len; i++) {
        int index = array[i] / slice % 10;
        counters[index]++;
    }
    for (int i = 1; i < 10; i++) 
            counters[i] += counters[i-1];

    for (int i = len-1; i >= 0; i--) {
        int index = array[i] / slice % 10;
        ouput[counters[index]-1] = array[i];
        counters[index]--;
    }
    for (int i = 0; i < len; i++) {
        array[i] = ouput[i];
    }
}

void bogoSort(int *array, int len) {
    while (verifyArray(array, len)) 
        shuffle(array, len);
}

void radixSort(int *array, int len) {
    int maximum = max(array, len);
    int slice = 1; /* slice array to a buckets */
    while (verifyArray(array, len)) {
        countingSortModified(array, len, slice);
        slice *= 10;
    }
}

/*
def radix_sort(array):
    slce = 1  # slice
    maxNum = max(array)
    while maxNum // slce >= 1:
        counting_sort(array, slce)
        slce *= 10
    return array
*/


int main() {
    srand(time(NULL));
    int len = 20;
    int *array = (int*)calloc(sizeof(int), len);
    
    printf("\n filled : \n");
    fill(array, len, len+1);
    print(array, len);

    printf("\n sorted : \n");
    //bogoSort(array, len);
    //quick_sort(array, 0, len-1);
    //countingSort(array, len);
    //radixSort(array, len);
    countingSortModified(array, len, 10);
    print(array, len);


    free(array);
    

    return 0; 
}

