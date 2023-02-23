#include <stdio.h>
#include <malloc.h>

struct Point {
    double x, y, z;
};

void printPoint(struct Point p)
{
    printf("(%.1lf, %.1lf, %.1lf)", p.x, p.y, p.z);
}

int main()
{
    struct Point p1, *p2 = (struct Point*)malloc(sizeof(struct Point));
    p1.x = 10;
    p1.y = 20;
    p1.z = 30;
    p2->x = 50;
    p2->y = 60;
    p2->z = 70;
    printPoint(p1);
    printf("\n");
    printPoint(*p2);
    printf("\n");

    free(p2);

    return 0;
}