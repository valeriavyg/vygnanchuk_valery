#include <stdio.h>

void trim_after_first_space(char str[]) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ' ') 
        {
            str[i] = '\0';  
            return;
        }
    }
}

int main()
{
    char a[] = "Cats and Dogs";
    printf("%s\n", a); // Должно напечатать Cats and Dogs
    trim_after_first_space(a);
    printf("%s\n", a); // Должно напечатать Cats
}