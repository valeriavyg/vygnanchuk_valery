#include <stdio.h>
#include <math.h>

double pi(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (pow(-1, i + 1))/(2 * i - 1);
    return 4* sum;
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%.10f\n", pi(n));
    return 0;
}