#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void write1G() {
    FILE* file = fopen("data.bin", "wb");
    if (file) {
        for (int i = 0, num = rand(); i < (1000000000)/4; i++, num = rand()) 
            fwrite(&num, sizeof(int), 1, file);
        fclose(file);
    }
}


int main() {
    //write1G();
    return 0;
}