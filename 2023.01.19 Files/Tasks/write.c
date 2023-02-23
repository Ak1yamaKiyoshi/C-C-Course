#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE* fileWrite = fopen("./data.txt", "wt");
    FILE* fileRead;
    if (fileWrite != NULL) {
        fputs("Lavender is Cool", fileWrite);
        fclose(fileWrite);
    }
    fileRead = fopen("./data.txt", "rt");
    if (fileRead != NULL) {
        char c;
        do {
            c = fgetc(fileRead);
            printf("%c", c);
        } while(c != EOF);
        fclose(fileRead);
    }
    return 0;
}