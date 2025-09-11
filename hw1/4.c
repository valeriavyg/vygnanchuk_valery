#include <stdio.h>
#include <limits.h>
int main() 
{
    int n;
    int k=0;
    scanf("%i", &n);
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) 
    {
        int a;
        scanf("%i", &a);
        if (a > max)
        {
            max = a;
            k=0;
        }

        if (a == max)
            k++;
        
    }
    printf("%i %i", max,k);
}