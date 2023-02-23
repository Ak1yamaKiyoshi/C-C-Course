#include <stdio.h>
#include <malloc.h>

// void enterA(int *array, int *len) 
void enterA(int *array, int *len) {
    for (int i = 0, *ptr = array; i < *len; i++, ptr++) {
        printf("elem %d/%d: ", i, *len);
        scanf("%d", ptr);
    }
}

// void printA(int *array, int *len) 
void printA(int *array, int *len) {
    for (int i = 0, *ptr = array; i < *len; i++, ptr++) {
        printf(" %d", *ptr);
    }
}

// void copyA(int *array1, int array2, int *len1, int *len2)
void copyA(int *array1, int array2, int *len1, int *len2) {
    if (*len1 == *len2) {
        // copy arrays 
        for (int i=0, *ptr1=array1, *ptr2=array2; i < *len1; i++, ptr1++, ptr2++) {
            *ptr2 = *ptr1;
        }
    }
}

//2. За допомогою вказівників написати функцію яка копіює один масив у інший масив.
int main() {
    int *len1 = (int*)malloc(sizeof(int*));
    int *len2 = (int*)malloc(sizeof(int*));
    int *array1 = (int*)malloc(sizeof(int*)**len1);
    int *array2 = (int*)malloc(sizeof(int*)**len2);

    *len1 = 5;
    *len2 = 5;

    enterA(array1, len1);
    copyA(array1, array2, len1, len2);
    printA(array2, len2);

    free(array1); free(array2); free(len1); free(len2);

    
    return 0;
}
