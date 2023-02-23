#include <math.h>
#include <stdio.h>

int main()
{

    int x1 = 1; 
    printf(" f1(%d) = %f\n",x1, pow(sin(x1), 2) + pow(cos(x1), 2));
    float x2 = 12, y2 = 6;
    printf(" f2(%f, %f) = %f\n",x2, y2, (0.5*x2 + (1/pow(y2 + 2, 2))) / ((x2+y2)/(x2-y2)) );
    float x3 = 100;
    float y3 = pow(x3, 3)- pow(6*x3, 2) + 2*x3 + 1;
    printf(" f3(%f) = %f", x3, x3 * cbrt(y3) - sqrt(x3 - cbrt(y3)));

    return 0;
}