#include <stdio.h>
#include <math.h>
#include <malloc.h>

/*
	Розв’язати за допомогою вказівників задачу пошуку коренів квадратного рівняння методом дискримінанта. 
	Пам’ять для параметрів рівняння та розрахункових величин виділити динамічно, а після виконання розрахунків вивільнити.
*/

void discriminant(float *a, float *b, float *c, int *roots) {
    int d = *b**b-4**a**c;
    if (d > 0) {
        *a = (-*b-sqrt(d))/(2**a);
        *b = (-*b+sqrt(d))/(2**a);
        *roots = 2;
    }
    else if (d == 0) {
        *a = -*b/-(2**a);
        *roots = 1;
    }
    else
        *roots = 0;
}


void enter(float *a, float *b, float *c) {
    printf("Enter a: ");
    scanf("%f", a);
    printf("Enter b: ");
    scanf("%f", b);
    printf("Enter c: ");
    scanf("%f", c);
}


int main()
{
    float *a = (float*)malloc(sizeof(float));
    float *b = (float*)malloc(sizeof(float));
    int *c = (float*)malloc(sizeof(float));
    int *roots = (int*)malloc(sizeof(int));

    enter(a, b, c);
    discriminant(a, b, c, roots);
    
    if (*roots == 2) 
        printf("x1: %f x2: %f\n", *a, *b);
    else if (*roots == 1) 
        printf("x1: %f\n ", *a);
    else printf("No roots\n");
    
    free(a); 
    free(b); 
    free(c); 
    free(roots); 

    return 0;
}