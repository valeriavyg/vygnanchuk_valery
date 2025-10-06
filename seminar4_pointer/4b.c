#include <stdio.h>

void mult2_b(int* p, size_t n) 
{
    for (size_t i = 0; i < n; i++) 
        p[i] *= 2;
}

int main() 
{
    int arr2[] = {1, 2, 3};
    size_t n = 3;
    
    mult2_b(arr2, n);
    for (size_t i = 0; i < n; i++) 
        printf("%i ", arr2[i]);
    printf("\n");
}