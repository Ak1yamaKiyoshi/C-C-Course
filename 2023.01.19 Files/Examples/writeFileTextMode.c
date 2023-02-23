#include <stdio.h>

int main()
{
    FILE* file = fopen("data.txt", "wt");
    if (file != NULL) {
        fprintf(file, "%s\n", "Test message");
        fclose(file);
    }

    file = fopen("data.txt", "at");
    if (file) {
        fputs("and one more message", file);
        fclose(file);
    }

    return 0;
}