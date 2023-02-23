#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


void print(int *array, int len) {
    for (int i = 0; i < len; i++) printf("%d ", array[i]);
}

void write(int *array, int len) {
    FILE* file = fopen("data.bin", "wb");
    if (file) {
        fwrite(array, sizeof(int), len, file);
        fclose(file);
    }
}

void read(int *array, int len) {
    FILE* file = fopen("data.bin", "rb");
    if (file) {
        while(!feof(file)) fread(array, sizeof(int), len, file);
        fclose(file);
    }
}

void fillRand(int *array, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) array[i] = rand() % 400;
}


int main() {
    int len = 100;
    int *array = (int*)calloc(sizeof(int), len);
    int len1 = len;
    int *array1 = (int*)calloc(sizeof(int), len);
    
    fillRand(array, len);
    printf(" _ arr to write\n");
    for (int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");
    write(array, len);
    read(array1, len1);
    printf(" _ read arr from file\n");
    print(array1, len1);

    free(array);
    free(array1);
    return 0;
}
