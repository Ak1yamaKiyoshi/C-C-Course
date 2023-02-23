#include <stdio.h>
#include <stdlib.h>

void write() {
    FILE* file;
    file = fopen("alphabet.txt", "w+");
    if (file) {
        for (char c = 65; c < 65+26; c++) fputc(c, file);
        fclose(file);
    }
}

void read() {
    FILE* file;
    file = fopen("alphabet.txt", "r");
    if (file) {
        for (char c = 65; c < 65+26; c++)
            printf("%c", fgetc(file));
        fclose(file);
    }
}

void read1() {
    FILE* file;
    file = fopen("alphabet.txt", "r");
    if (file) {
        for (char c = fgetc(file); c != EOF; c = fgetc(file))
            printf("%c",c);
        fclose(file);
    }
}

void read2() {
    FILE* file = fopen("alphabet.txt", "r");
    if (file) {
        for (char c = 65; c != EOF; printf("%c", c = fgetc(file)));
        fclose(file);   
    }
}


int main() {
    write();
    read();
    printf("\n");
    read1();
    printf("\n");
    read2();
    printf("\n");
    return 0;
}
