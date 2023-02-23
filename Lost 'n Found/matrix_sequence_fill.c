#include <stdio.h>


const int SIZE = 5;
int counter = 1;

int main()
{
    int array[SIZE][SIZE];

    for (int a = 1; a <= SIZE; a++) {
        for (int b = 1; b <= SIZE; b++)
            array[a-1][b-1] = counter++;
    }

    for (int a = 1; a <= SIZE; a++) {
        for (int b = 1; b <= SIZE; b++){
          if(a == SIZE && b == SIZE)
            break;
          printf("%3d ",  array[a-1][b-1]);
        }
          
        printf("\n");
    }
    return 0;
}