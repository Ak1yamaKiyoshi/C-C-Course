#include <stdio.h>
#include <malloc.h>

int main()
{
    char  c;
    FILE* file = fopen("EOFdemo.txt", "rb");
    if (file) {
        while ((c = fgetc(file)) != EOF) {
            printf("%c", c);
        }
        fclose(file);
    }
    return 0;
}