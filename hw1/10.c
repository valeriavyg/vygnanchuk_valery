#include <stdio.h>
int main() 
{
    int n;
    int m;
    scanf("%i %i", &n,&m);
    int s[m];

    for (int j = 0; j < m; ++j)
        s[j]=0;

    for (int i = 0; i < n ; ++i)
        for (int j = 0; j < m; ++j)
            {
                int a;
                scanf("%i", &a);
                s[j]+=a;
            }

    for (int j = 0; j < m; ++j)
        printf("%i ",s[j]);

    printf("\n");
}