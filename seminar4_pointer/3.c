#include <stdio.h>

void cube(float* px) 
{
    *px = *px * *px * *px;
}

int main() 
{
    float x;
    scanf("%f", &x);
    cube(&x);
    printf("%.5f\n", x);
}