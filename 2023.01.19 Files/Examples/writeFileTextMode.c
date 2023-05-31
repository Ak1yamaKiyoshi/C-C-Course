#include <stdio.h>

int main()
{
    FILE* file = fopen("data.csv", "at");
    if (file != NULL) {
        fprintf(file, "%d;", 3);
        fclose(file);
    }

    return 0;
}