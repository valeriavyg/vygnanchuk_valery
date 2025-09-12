#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);
    int a[10005];
    for (int i = 0; i < n; i++) 
        scanf("%i", &a[i]);

    for (int i = 0; i < n - 1; i++) 
        for (int j = 0; j < n - i - 1; j++)
         {
            int n1 = a[j];
            int s1 = 0;
            int d1 = n1;
            while (d1 > 0) 
            {
                s1 += d1 % 10;
                d1 /= 10;
            }
            int n2 = a[j + 1];
            int s2 = 0;
            int d2 = n2;
            while (d2 > 0) 
            {
                s2 += d2 % 10;
                d2 /= 10;
            }
            if (s1 > s2) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}