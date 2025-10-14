#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char** p = (char**)malloc(sizeof(char*));
    *p = (char*)malloc(sizeof(char) * 12);
    strcpy(*p, "Hello world");

    printf("%s\n", *p);
    printf("%c\n", **p);
    
    free(*p);
    free(p);
}