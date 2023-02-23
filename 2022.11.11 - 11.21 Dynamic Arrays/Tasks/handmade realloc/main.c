    #include <stdio.h>
    #include <memory.h>
    #include <malloc.h>
    #include <time.h>
    #include <stdlib.h>

    /*
    Треба запитати з клавіатури розмір масиву, 
    заповнити його випадковими числами, 
    потім запитати розмір іншого бажано більшого масиву, 
    скопіювати туди попередній, 
    і решту елементів в новому масиві треба зробити нулями.
    (бажано використати memset)
    */


    int* testRealloc(int *src, int srclen, int dstlen) {
        int *array = (int*)calloc(sizeof(int*), dstlen);
        memset(array, 0, dstlen*sizeof(int));
        memcpy(array, src, sizeof(int)*srclen);
        free(src);
        return array;
    }



    int main() {
        int len;
        int len1;
        srand(time(NULL)); 
        int *array;

        printf("enter len: ");
        scanf("%d", &len);

        array = (int*)calloc(sizeof(int*), len);

        // filling with random numbers
        for (int i = 0; i < len; i++) {
            *(array+i) = (rand() % 15) + 10;
        }

        // printing array
        printf("\n");
        for (int i = 0; i < len; i++) {
            printf(" %d", *(array+i));
        }


        printf("\nenter len for new array : ");
        scanf("%d", &len1);

        array = testRealloc(array, len, len1);

        for (int i = 0; i < len1; i++) {
            printf(" %d", *(array+i));
        }

        return 0;
    }
