#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "SingleLinkedList.h"
#ifndef __single_linked_list_c__
#define __single_linked_list_c__


struct point {
    int x; 
    int y;
}; 

struct square {
    struct point coordinates[4]; 
    int color; 
};

void randomFillPoint(struct point *p) {
    p->x = rand() % 10;
    p->y = rand() % 10;
}

void randomFillSquare(struct square *s) {
    for (int i = 0; i < 4; i++)  
        randomFillPoint(&s->coordinates[i]);
    s->color = rand()% 0xFFFFFF;
}

void printPoint(struct point *p) {
    printf("(%d, %d)", p->x, p->y);
}

void printSquare(struct square *s) {
    printf("[ ");
    for ( int i = 0; i < 4; i++) {
        printf("<%d", i+1);
        printPoint(&s->coordinates[i]);
        printf("> ");
    }
    printf("]\n");
}


void fprintPoint(struct point *p) {
    FILE* file = fopen("data.csv", "wt");
    if (file != NULL) {
        fprintf(file, "%d %d", p->x, p->y);
        fclose(file);
    }
}

void fprintSquare(struct square ) {
    for (int i = 0; i < 4; i++) {
        fprintf();

    }
}


void writeSquare() {
    FILE* file = fopen("squares.txt", "wt");
    if (file != NULL) {
        fprintf(file, "%s\n", "Test message");
        fclose(file);
    }
}


#endif