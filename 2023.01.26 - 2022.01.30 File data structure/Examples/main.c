#include <stdio.h>
#include <malloc.h>

struct Point {
    double x;
    double y;
};

struct Figure {
    char name[20];
    int anglesCount;
    struct Point* angles;
};


void readFigure(FILE* file, struct Figure* figure)
{
    fscanf(file, "%s%d", figure->name, &(figure->anglesCount));
    figure->angles = (struct Point*)calloc(sizeof(struct Point), figure->anglesCount);
    for (int j = 0; j < figure->anglesCount; j++) {
        fscanf(file, "%lf%lf", &(figure->angles[j].x), &(figure->angles[j].y));
    }
}

void fillFigures(struct Figure* figures, int size, FILE* file)
{
    if (file == NULL) file = stdin;
    for (int i = 0; i < size; i++) {
        readFigure(file, &figures[i]);
    }
}

int main()
{
    struct Figure ar1[2];
    fillFigures(ar1, 2, NULL);
    FILE *file = fopen("test.dat", "r");
    if (file) {
        struct Figure ar2[2];
        fillFigures(ar2, 2, file);
    }
    return 0;
}