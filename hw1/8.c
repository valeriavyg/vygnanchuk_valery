#include <stdio.h>
int main() 
{
    int n;
    int a[n];
    scanf("%i\n", &n);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%i", &a[i]);
        printf("%i " ,a[i]);
    }   
    for (int i = 0; i < n; ++i) 
    {
        printf("%i " ,a[i]);
    }
}