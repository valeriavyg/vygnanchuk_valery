#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{

    if (argc != 4) 
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: %s <number> <operator> <number>\n", argv[0]);
        return 1;
    }
    
    char *n1 = argv[1];
    char *op = argv[2];
    char *n2 = argv[3];

    for (int i = 0; n1[i] != '\0'; i++) 
    {
        if (n1[i] < '0' || n1[i] > '9') 
        {
            printf("Error: Operands should be integers!\n");
            return 1;
        }
    }
    
    for (int i = 0; n2[i] != '\0'; i++) 
    {
        if (n2[i] < '0' || n2[i] > '9') 
        {
            printf("Error: Operands should be integers!\n");
            return 1;
        }
    }

    int a = atoi(n1);
    int b = atoi(n2);
    int res = 0;
    
    if (op[0] == '+') 
        res = a + b;
    else if (op[0] == '-') 
        res = a - b;
    else if (op[0] == '*') 
        res = a * b;
    else if (op[0] == '/') 
    {
        if (b == 0) 
        {
            printf("Error: Division by zero!\n");
            return 1;
        }
        res = a / b;
    }
    else if (op[0] == '%') 
    {
        if (b == 0) {
            printf("Error: Division by zero!\n");
            return 1;
        }
        res = a % b;
    }
    else 
    {
        printf("Error: Invalid operator!\n");
        return 1;
    }
    printf("%i\n", res);
    return 0;
}