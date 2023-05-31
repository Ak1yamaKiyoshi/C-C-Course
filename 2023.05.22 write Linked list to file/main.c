#include <stdio.h>
#include <malloc.h>
#include "SingleLinkedList.c"
#ifndef __main_c__
#define __main_c__


int main() {

    int len = 4;
    struct square squares[4];

    for (int i = 0; i < len; i++) 
        randomFillSquare(&squares[i]);

    for (int i = 0; i < len; i++)
        printSquare(&squares[i]);
    
    


}


#endif