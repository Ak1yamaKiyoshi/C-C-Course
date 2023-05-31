#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

const int RANGEMIN = 0;
const int RANGEMAX = 100;


struct Point {
    double x, y;
};

struct Triangle {
    struct Point A, B, C;
};


void setRandomPoint(struct Point* p) {
    p->x = RANGEMIN + rand() % (RANGEMAX - RANGEMIN);
    p->y = RANGEMIN + rand() % (RANGEMAX - RANGEMIN);
}

void buildTriangle(struct Triangle* t) {
    setRandomPoint(&(t->A));
    setRandomPoint(&(t->B));
    setRandomPoint(&(t->C));
}

double distance(struct Point a, struct Point b) {
    return sqrt(pow(b.x - a.x , 2) + pow(b.y - a.x, 2));
}

int orient(struct Point a, struct Point b, struct Point c) {
    if (((b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x)) > 0) return 1;
    else return 0;
} 

int insideTriangle(struct Triangle *t, struct Point p) {
    if (orient(t->A, t->B, p) + orient(t->B, t->C, p) + orient(t->C, t->A, p) == 3) return 1;
    else return 0;
}

int min(int a, int b, int c) {
    a = (a < b) ? a : b; return (c < a) ? c : a;
}

int max(int a, int b, int c) {
    a = (a > b) ? a : b; return (c > a) ? c : a;
}

int tEXists(struct Triangle *t) {
    return (distance(t->A, t->B) + distance(t->B, t->C) + distance(t->C, t->A)) > 2 * max(distance(t->A, t->B), distance(t->B, t->C), distance(t->C, t->A));
}

double getSquare(struct Triangle *t) {   
    double ab = distance(t->A, t->B); 
    double bc = distance(t->B, t->C); 
    double ac = distance(t->C, t->A);
    double semiP = (ab + bc + ac) / 2;
    return sqrt(semiP*(semiP-ab)*(semiP-bc)*(semiP-ac));
    return 0;
}

void printTriangle(struct Triangle *t) {
    struct Point p;
    // y = min Y, y < max Y, y++
    for (int y = min(t->A.y,t->B.y,t->C.y); y < max(t->A.y,t->B.y,t->C.y);  y++) {
        printf("\n");
        // x = min X, x < max X, x++
        for (int x = min(t->A.x,t->B.x,t->C.x); x < max(t->A.x,t->B.x,t->C.x); x++) {
            p.x = x; p.y = y;
            if (insideTriangle(t, p)) printf("#");
            else printf(" ");
        }
    }
}

int main() {
    struct Triangle* triangles = (struct Triangle*)calloc(sizeof(struct Triangle), 5);
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
        buildTriangle(&triangles[i]);

    for (int i = 0; i < 5; i++) 
        if (tEXists(&triangles[i]))
            printTriangle(&triangles[i]);
        else printf("\nTriangle %d does not exists", i);

    for (int i = 0; i < 5; i++)
        if (tEXists(&triangles[i]))
            printf("\nt: %d square: %.3lf",i, getSquare(&triangles[i]));
    
    return 0;
}