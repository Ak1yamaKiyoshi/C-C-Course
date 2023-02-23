#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

const int RANGEMIN = 0;
const int RANGEMAX = 100;


struct Point {
    double x, y;
};

struct Triangle {
    struct Point A, B, C;
};

void setRandomPoint(struct Point* p)
{
    p->x = RANGEMIN + rand() % (RANGEMAX - RANGEMIN);
    p->y = RANGEMIN + rand() % (RANGEMAX - RANGEMIN);
}

void buildTriangle(struct Triangle* t)
{
    setRandomPoint(&(t->A));
    setRandomPoint(&(t->B));
    setRandomPoint(&(t->C));
}

// TODO: write printTriangle function here

double getSquare(struct Triangle t)
{
    // TODO: realize this function
    return 0;
}
int main()
{
    struct Triangle* triangles = (struct Triangle*)calloc(sizeof(struct Triangle), 5);
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        buildTriangle(&triangles[i]);

    /*  TODO: Make cycle to print triangles
             To print triangle realize printTriangle function */

    for (int i = 0; i < 5; i++)
        printf("%lf\n", getSquare(triangles[i]));
    return 0;
}