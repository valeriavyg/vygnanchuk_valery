#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used) 
{
    int letters[30] = {0};
    
    while (*str != '\0') {
        if (isalpha(*str))  letters[ tolower(*str) - 'a'] = 1;
        str++;
    }
    
    int res = 0;
    for (int i = 0; i < 26; i++) 
    {
        if (letters[i]) used[res++] = 'a' + i;
    }
    used[res] = '\0'; 
}

int main() 
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u); // Напечатает "adeprsu"
    
    strcpy(s, "123!$@");
    used_chars(s, u);
    printf("%s\n", u); // Ничего не напечатает (только перенос строки)
    
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u); // Напечатает "abcdefghijklmnopqrstuvwxyz"
}