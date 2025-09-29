#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    scanf("%i", &n);
    int x = 0, y = 0;
    
    for (int i = 0; i < n; i++) 
    {
        char direction[10];
        int distance;
        scanf("%s %i", direction, &distance);
        
        if (strcmp(direction, "North") == 0) 
            y += distance;
        else if (strcmp(direction, "South") == 0) 
            y -= distance;
        else if (strcmp(direction, "East") == 0) 
            x += distance;
        else if (strcmp(direction, "West") == 0) 
            x -= distance;
    }
    
    printf("%i %i\n", x, y);
}