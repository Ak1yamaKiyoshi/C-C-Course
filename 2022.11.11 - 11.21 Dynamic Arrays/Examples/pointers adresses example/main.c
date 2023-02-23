//1. Використовуючи вказівники розвернути масив. 
//Розмір масиву та початкові значення елементів ввести з клавіатури. 
//Задачу зробити в одному циклі без використання додаткових масивів. 

#include <stdio.h>
#include <malloc.h>


int main() {

    int len;
    int *array;
    int *temp = (int*)malloc(sizeof(int*));

    printf("Enter array len: ");
    scanf("%d", &len);

    array = (int*)malloc(sizeof(int*)*len);

    for (int i = 0, *ptr = array; i < len; i++, ptr++) {
        printf("Enter %i elem: ", i+1);
        scanf("%d", ptr);
    }

    printf("___\n");
    for (int i = 0, *ptr = array; i < len; ptr++, i++) {
        printf("\n%14lld <adress || elem> %4d  || %d/%d", ptr, *ptr, i, len-1);
    }
    printf("\n-----\n");
    printf("%14lld << begin element\n%14lld << end element", array, array+len-1);
    printf("\n-----");
    for (int i = len-1, *ptr = array+(len-1); i > -1; ptr--, i--) {
        printf("\n%14lld <adress || elem> %4d  || %d/%d", ptr, *ptr, i, len-1);
    }

    for (int *beg = array, *end = array+len-1; beg <= end; beg++, end--) {
        printf("\n*beg: %2d|*end: %2d", *beg, *end);
    }



    return 0;
}
