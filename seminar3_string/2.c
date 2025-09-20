#include <stdio.h>
int main()
{
    for (int i = ' '; i <= '~'; ++i)
        printf("Symbol = %c, Code = %hhi\n", i, i);
}
