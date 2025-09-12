#include <stdio.h>
int main()
{
    int a;
    int b;
    int c;
    scanf("%i%i%i", &a, &b,&c);
        while(a<=b)
        {
            if (a%c==0)
            {
                printf("%i ", a);
                a++;
            }
            else a++;
        }
}