#include <stdio.h>
int main()
{
    int n;
    int m;
    int s=0;
    scanf("%i%i", &n, &m);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            if ((i+j)%2==0)
                s += i*j;
            else s += -i*j;

    printf("%i\n", s);
}