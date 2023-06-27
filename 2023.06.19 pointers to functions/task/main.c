#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef float ( *process )( float op1, float op2 );

/**
 * @brief reads input from console 
 * allocates memory for string */
char* enter() {
    char *string = (char*)calloc(sizeof(char), 100);
    printf(" <Enter expression>\n > ");
    scanf("%s", string);
    return string;
}

float add       (float op1, float op2) { return op1 + op2; }
float substract (float op1, float op2) { return op1 - op2; }
float multiply  (float op1, float op2) { return op1 * op2; }
float divide    (float op1, float op2) { return op1 / op2; }
float increment (float op1 )           { return op1 + 1; }
float decrement (float op1 )           { return op1 - 1; }
float calc ( process func, float op1, float op2 ) { return func(op1, op2); }

float calculate(char *expression) {
    float op1, op2, out;
    char *operator;
    
    int inc = 0; // increment flag 
    int dec = 0; // decrement flag
    if (strstr(expression, "++")) inc = 1;
    else if (strstr(expression, "--")) dec = 1;

    if (inc == 0 && dec == 0) {
        sscanf(expression, "%f%c%f",&op1, operator, &op2);
        if      ( *operator == '+')
            out = calc( add, op1, op2);
        else if ( *operator == '-') 
            out = calc( substract, op1, op2);
        else if ( *operator == '*')
            out = calc( multiply, op1, op2);
        else if ( *operator == '/')
            out = calc( divide, op1, op2);
    }
    else {
        sscanf(expression, "%f",&op1);
        if ( inc == 1 ) 
            out = calc ( add, op1, 1);
        else if ( dec == 1) 
            out = calc ( substract, op1, 1);
    }

    return out;
}


int main() {
    char *expression; 

    expression = enter();
    printf(" <Expression output> \n > %s ", expression);
    printf(" \n <Result> %f", calculate(expression));

    free(expression);
    return 0;
}