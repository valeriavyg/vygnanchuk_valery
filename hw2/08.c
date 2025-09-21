#include <stdio.h>

void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++) 
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int l;
    scanf("%i", &l);
    
    int array[l];
    for (int i = 0; i < l; i++) 
        scanf("%d", &array[i]); 
    reverse(array, l);
    for (int i = 0; i < l; i++) 
        printf("%i ", array[i]);

}