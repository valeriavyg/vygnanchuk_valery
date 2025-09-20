#include <stdio.h>

int main()
{
    char c;
    int s = 0;
    while ((c = getchar()) != '\n' && c != ' ') 
        if (c >= '0' && c <= '9') s += c - '0';
    printf("%i\n", s);
}