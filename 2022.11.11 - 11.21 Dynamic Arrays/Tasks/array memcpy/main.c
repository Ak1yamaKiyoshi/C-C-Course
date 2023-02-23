/*
2. За допомогою вказівників написати функцію яка копіює один масив у інший масив.
 2*.     Виконати попереднє завдання, але замість використання циклів використати функції копіювання шматків пам’яті.
*/
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

// void enterA(int *array, int *len) 
void enterA(int *array, int len) {
    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf("elem %d/%d: ", i, len);
        scanf("%d", ptr);
    }
}

// void printA(int *array, int *len) 
void printA(int *array, int len) {
    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf(" %d", *ptr);
    }
}


int main() {
    int len1 = 5;
    int len2 = 5;
    int *array1 = (int*)malloc(sizeof(int*)*len1);
    int *array2 = (int*)malloc(sizeof(int*)*len2);
    
    enterA(array1, len1);
    if (len1 == len2) {
        memcpy(array2, array1, sizeof(int*)*len2);
        printA(array2, len2);
    }

    free(array1); free(array2); 

    
    return 0;
}
