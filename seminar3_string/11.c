#include <stdio.h>

void safe_strcpy(char after[], size_t size, const char before[]) 
{
    int i;
    for (i = 0; i < size - 1 && before[i] != '\0'; i++) 
        after[i] = before[i];
    after[i] = '\0'; 
}

int main()
{
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    safe_strcpy(a, 10, b);
    printf("%s\n", a); 
}