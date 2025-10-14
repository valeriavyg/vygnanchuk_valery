#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* concat(const char* a, const char* b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    size_t total_len = len_a + len_b + 1;
    char* res = (char*)malloc(total_len);
    strcpy(res, a);
    strcpy(res + len_a, b);
    return res;
}

int main()
{
    char a[] = "meow";
    char b[] = "cat";
    char* merge = concat(a, b);
    printf("%s\n", merge);
    free(merge);
}