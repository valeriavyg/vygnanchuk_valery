#include <stdio.h>
int main() 
{
    int a[1000];
    int n;
    int pos = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
 
    for (int i = 0; i < n ; ++i)
        if (a[i]>=0)
        {
            a[pos] = a[i];
            pos++;
        }         
    for (int i = 0; i < pos; ++i)
        printf("%i ", a[i]);

    printf("\n");
}