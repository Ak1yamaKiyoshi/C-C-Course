#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Test {
    int a;
    char b[20];
};

void writeTest(struct Test *test, size_t len) {
    FILE *file = fopen("data.txt", "w+");
    if (file){ 
        for (int i = 0; i < len; i++)
            fprintf(file,"%d %s ", test[i].a, test[i].b);
        
        fclose(file);
    }   
}

void readTest(struct Test *test, size_t len) {
    FILE *file = fopen("data.txt", "r+");
    if (file){ 
        for (int i = 0; i < len; i++) {
            fscanf(file, "%d", &test[i].a);
            fscanf(file, "%s", test[i].b);
        }

        fclose(file);
    }  
}
int main() {
    size_t len = 2;
    
    struct Test test[2];
    struct Test test1[2];
    
    test[0].a = 45; strcpy(test[0].b, "First_Struct");
    test[1].a = 45; strcpy(test[1].b, "Second_Struict");

    writeTest(&test[0], len);
    readTest(&test1[0], len);

    printf("\na: %d b: %s", test1[0].a, test1[0].b);
    printf("\na: %d b: %s", test1[1].a, test1[1].b);
}