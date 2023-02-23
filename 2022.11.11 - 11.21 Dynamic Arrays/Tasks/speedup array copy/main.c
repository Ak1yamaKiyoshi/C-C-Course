#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void copy(int *src, int *dst, int size)
{
   int longersize = sizeof(int)*size/sizeof(long int);
   printf("%d\n", longersize);
   for (long int *ptr = (long int*)src, *ptr2 = (long int*)dst;
        ptr < (long int*)src + longersize;
        ptr++, ptr2++)
       *ptr2 = *ptr;
   if (size%2 == 1)
       *(dst+size-1) = *(src+size-1);}

void randomFilling(int *array, int size)
{
   srand(time(NULL));
   for (int *ptr = array; ptr < array + size; ptr++)
       *ptr = rand() % 50;
}

void printArray(int *array, int size)
{
   for (int i = 0; i < size; i++)
       printf("%d ", array[i]);
   printf("\n");
}

int main()
{
   int size = 5;
   int *a = (int*)calloc(sizeof(int), size);
   int *b = (int*)calloc(sizeof(int), size);

   randomFilling(a, size);
   printf("Source array\n");
   printArray(a, size);

   copy(a, b, size);
   printf("Destination array\n");
   printArray(b, size);

   free(a);
   free(b);
}
