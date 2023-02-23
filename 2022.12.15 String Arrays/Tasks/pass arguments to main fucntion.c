#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        for (int i=1; i<argc; i++) {
            puts(argv[i]);
        }
    }

    return 0;
}
