#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

/*
Розробити калькулятор який буде виконувати унарні та бінарні операції 
( спрощений варіант завдання тільки бінарні операції ) 
Сам процес обчислень має відбуватись у функції сalculate яка набуватиме аргументи та вказівник на функцію яку треба виконати
Вказівник на функцію можна визначити розібравши рядок з виразом, наприклад 
'5+3' має передавати у функцію calculate вказівник на функцію sum, тощо 
Результат має бути надрукований у зручному для перегляду вигляді

Для складнішого варіанту, у якості унарних операторів мають бути ++ та - - 
*/

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

void slice (const char* str, char *result, size_t start, size_t end) {
    strncpy(result, str+start, end - start );
}

float calculate(char *expression) {
    float op1, op2, out;
    char operator;
    sscanf(expression, "%f%c%f",&op1,&operator, &op2);
    if (operator == "+")
        out = add(op1, op1);
    else if ( operator == "-") 
        out = substract(op1, op1);
    else if ( operator == "*")
        out = multiply(op1, op1);
    else if ( operator == "/")
        out = divide(op1, op1);
    return out;
}

float add       (float op1, float op2) { return op1 + op2; }
float substract (float op1, float op2) { return op1 - op2; }
float multiply  (float op1, float op2) { return op1 * op2; }
float divide    (float op1, float op2) { return op1 / op2; }
float increment (float op1 )           { return op1 + 1; }
float decrement (float op1 )           { return op1 - 1; }

int main() {
    char *expression; 
    
    expression = enter();
    printf(" <Expression output> \n > %s \n", expression);
    printf(" \n <Result> %f", calculate(expression));

    free(expression);
    return 0;
}