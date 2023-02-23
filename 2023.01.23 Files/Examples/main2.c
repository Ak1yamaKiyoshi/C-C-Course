#include <stdio.h>

int main()
{
    int numbers[] = {0, 3000, 211, 34444, 4, 5, 6, 7, 8, 9};
    int numbers2[10];
    FILE* file = fopen("q.bin", "wb");
    if (file) {
        fwrite(&numbers, 4, 10, file);
        fclose(file);
    }

    file = fopen("q.bin", "rb");
    if (file) {
        while (!feof(file)) {
            if (fread(&numbers2, 4, 10, file) > 0) {
                for (int i=0; i<10; i++)
                    printf("%d ", numbers2[i]);
                printf("\n");
            }
        }
        fclose(file);
    }
    return 0;
}