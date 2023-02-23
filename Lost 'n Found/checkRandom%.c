#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandArray(int arr[], int len, int lRng, int rRng)
{

    srand(time(NULL));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % (rRng - lRng) + lRng;
}

void countEach(int arr[], int len, int lRng, int rRng, float countArr[])
{

    for (int i = 0; i < len; i++)
        countArr[arr[i] - lRng] += 1;
}

void printCntArr(float countArr[], int lRng, int rRng)
{

    for (int i = 0; i < (rRng - lRng); i++)
        printf("i = %d, %f%% in arr\n", i + lRng, countArr[i] / 10);
}

int main(int argc, char const *argv[])
{

    int len = 1000;
    int arr[len];
    int lRng = 3456;
    int rRng = 3470;
    float cntArr[rRng - lRng];

    getRandArray(arr, len, lRng, rRng);
    countEach(arr, len, lRng, rRng, cntArr);
    printCntArr(cntArr, lRng, rRng);

    return 0;
}