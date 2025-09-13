#include <stdio.h>

int sum_of_digits(int a) 
{
    int s = 0;
    int d = a;
    while (d > 0)
    {
        s += d%10;
        d /=10;
    }
    return s;
}

int main() 
{
    int a;
    scanf("%i", &a);
    printf("%i ", sum_of_digits(a));
}
