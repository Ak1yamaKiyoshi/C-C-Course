#include <stdio.h>
#include <malloc.h>


int main()
{

    printf("int: %d, int*: %d\n", sizeof(int), sizeof(int*));
    printf("short: %d, short*: %d\n", sizeof(short), sizeof(short*));
    printf("long %d, long* %d\n", sizeof(long), sizeof(long*));
    printf("char %d, char* %d\n", sizeof(char), sizeof(char*));
    printf("float %d, float* %d\n", sizeof(float), sizeof(float*));
    printf("double %d, double* %d\n", sizeof(double), sizeof(double*));

    return 0;
}
