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

// Find distance between two points
double distance(struct Point a, struct Point b) {
    return sqrt(pow(a.x - b.x, 2)+pow(a.x - b.y, 2));
}
double tPeriemeter(struct Triangle *t) {
    return distance(t->A, t->B) + distance(t->B, t->C) + distance(t->C, t->A); }
// Calculates Sum of distances betwen each triangle point and dot
double tDotDelta(struct Triangle *t, struct Point a) {
    return distance(t->A, a) + distance(t->B, a) + distance(t->C, a); }
// takes Triangle sides sum, Triangle and point, 
// returns difference between Triangle periemeter and Sum of distances betwen each triangle point and dot
double tPeriemeterDeltaDotTriangleSidesSum(double sumT, struct Triangle *t,  struct Point a) {
    return sumT - tDotDelta(t, a); }
// tPeriemeterDeltaDotTriangleSidesSum(sum, t, p) > 0) 

// TODO: write printTriangle function here
void printTriangle(struct Triangle *t) {
    struct Point p;
    double sum = tPeriemeter(t);
    printf("%lf\n", sum);
    
    for (int y=0; y<100; y++) {
        printf("\n");
        for (int x=0; x<100; x++) {
            p.x = x; p.y = y;
            if (tPeriemeterDeltaDotTriangleSidesSum(sum, t, p) > 0) 
                printf("#");
            else printf(" ");
        }
    }
}

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

    for (int i = 0; i < 5; i++) 
        printTriangle(&triangles[i]);
        
        ;

    /*  TODO: Make cycle to print triangles
             To print triangle realize printTriangle function */

    //for (int i = 0; i < 5; i++)
    //    printf("%lf\n", getSquare(triangles[i]));
    return 0;
}