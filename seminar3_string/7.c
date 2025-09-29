#include <stdio.h>

void encrypt(char* str, int k) 
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }
    }
}

int main() 
{
    char str[1000];
    int k;
    
    scanf("%i", &k);
    scanf("%s", str);  
    
    encrypt(str, k);
    printf("%s\n", str);
    
}