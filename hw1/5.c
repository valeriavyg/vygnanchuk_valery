#include <stdio.h>
#include <limits.h>
int main() 
{
    int n;
    int max = INT_MIN;
    int l = 0;
    scanf("%i", &n);
    printf(" %i",n);
    while (n!=1)
    {
    if (n%2 == 0)
        n = n/2;
    else n = 3*n+1;

    if (n > max)
        max = n;
    l++;
    printf(" %i",n);
    }
    printf("\nLength = %i,Max =%i\n", l,max);
}
