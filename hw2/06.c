#include <stdio.h>

int tribarr[100];

int trib(int n)
{
    if (n == 1 || n == 0)
        return 0;
    if (n == 2)
        return 1;
    if (tribarr[n] == 0)
        tribarr[n] = trib(n - 3) + trib(n - 2) + trib(n - 1);
    return tribarr[n];
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i\n", trib(n));
}