#include <stdio.h>

void mult2_a(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++) 
        *(p + i) *= 2;
}


int main() 
{
    int arr1[] = {1, 2, 3};
    size_t n = 3;
    
    mult2_a(arr1, n);
    for (size_t i = 0; i < n; i++) 
        printf("%i ", arr1[i]);
    printf("\n");
}