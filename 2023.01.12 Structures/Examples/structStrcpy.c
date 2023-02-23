#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Sample {
    char somestring[40];
};

int main()
{
    struct Sample *s = (struct Sample*)malloc(sizeof(struct Sample));;
    strcpy(s->somestring, "Test message");
    printf("%s\n", s->somestring);
    free(s);
    return 0;
}