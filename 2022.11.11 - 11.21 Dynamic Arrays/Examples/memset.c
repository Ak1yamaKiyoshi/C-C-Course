#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void fillArray(int *array, int len) {
   memset(array, 0, len*sizeof(int));
}


void printA(int *array, int len) {
  for (int i = 0, *ptr = array; i < len; i++, ptr++) {
      printf(" %d", *ptr);
  }
}


int main() {

   int len = 5;
   int *array = (int*)malloc(sizeof(int*)*len);
   char num = 4;

   printf("Before filling with %d:\n", num);
   printA(array, len);
  
   fillArray(array, len);

   printf("\nAfter filling with %d:\n", num);
   printA(array, len);

   free(array);

   return 0;
}

