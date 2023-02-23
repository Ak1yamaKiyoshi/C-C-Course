#include <stdio.h>
#include <malloc.h>
#include <memory.h>


void randomFilling(int *array, int size)
{
   srand(time(NULL));
   for (int *ptr = array; ptr < array + size; ptr++)
       *ptr = rand() % 50;
}


void printA(int *array, int len) {
  for (int i = 0, *ptr = array; i < len; i++, ptr++) {
      printf(" %d", *ptr);
  }
}


int main() {
   int len = 5;
   int *array = (int*)malloc(sizeof(int*)*len);
  
   randomFilling(array, len);
   printf("Before realloc:\n");
   printA(array, len);

   printf("\nAfter realloc:\n");
   len += 5;
   array = realloc(array, len * sizeof(int*));
   randomFilling(array, len);
   printA(array, len);

   free(array);

   return 0;
}
