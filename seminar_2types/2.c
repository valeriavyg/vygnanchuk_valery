#include <stdio.h>

unsigned long long  f(int n, int k)
{
    unsigned long long result = 1;
    for (int i = 0; i < k; i++) 
        result *= (n - i);
    return result;
}

int main()
{
    int n, k;
    scanf("%i %i", &n, &k);
    printf("%llu\n", f(n, k));
}