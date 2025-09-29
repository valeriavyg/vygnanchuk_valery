#include <stdio.h>
#include <string.h>
int main()
{
    char a[1000];
    scanf("%s", a);
    int length = strlen(a);
    int is_palindrome = 1;  
    
    for (int i = 0; i < length / 2; i++)
    {
        if (a[i] != a[length - 1 - i])
        {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome)
        printf("Yes\n");
    else
        printf("No\n");
}
