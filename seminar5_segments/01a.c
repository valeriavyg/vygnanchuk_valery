#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t* p = (size_t *)malloc(sizeof(char));
    *p = 123;
    printf("%zu\n", *p);
    free(p);
}