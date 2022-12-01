#include <stdio.h>
int main()
{
    char a = 'a';
    while (a != EOF)
    {
        scanf("%c", &a);
        for (int i = 0; i < 30; i++)if ((int)a - 'a' <= 26 && (int)a - 'a' >= 0)a = (int)a - 'a' + 'A';
        printf("%c", a);
    }
}