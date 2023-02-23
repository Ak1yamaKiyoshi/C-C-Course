#include <stdio.h>

int main()
{
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numbers2[10];
    FILE* file = fopen("data3.txt", "wb");
    if (file) {
        fwrite((char*)&numbers, sizeof(char), sizeof(int)*10, file);
        fclose(file);
    }

    file = fopen("data3.txt", "rb");
    if (file) {
        while (!feof(file)) {
            if (fread((char*)&numbers2, sizeof(char), sizeof(int)*10, file) > 0) {
                for (int i=0; i<10; i++)
                    printf("%d ", numbers2[i]);
                printf("\n");
            }
        }
        fclose(file);
    }
    return 0;
}