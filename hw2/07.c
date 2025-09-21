#include <stdio.h>

int count_even(int arr[], int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0) k++;
    return k;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int s = 5;
    printf("Test: %i\n", count_even(arr, s));

    int l;
    scanf("%d", &l);
    int array[l];
    for (int i = 0; i < l; i++)
        scanf("%i", &array[i]);
    printf("%i\n", count_even(array, l));
}