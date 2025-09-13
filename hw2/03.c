#include <stdio.h>

void print_even(int a, int b) 
{
    while (a<=b)
    {
        if (a%2==0) 
        {
            printf("%i ", a);
            a++;
        }
        else a++;
    }
}

int main() 
{
    int a;
    int b;
    scanf("%i %i", &a,&b);
    print_even(a, b);
}
