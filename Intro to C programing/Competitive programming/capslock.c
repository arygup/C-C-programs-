#include <stdio.h>
#include<math.h>
int main()
{
    char a = '?';
    while (scanf("%c", &a) != -1)
    {
        for (int i = 0; i < 30; i++)if ((int)a - 'a' <= 26 && (int)a - 'a' >= 0)a = (int)a - 'a' + 'A';
        printf("%c", a);
    }
    printf("c\n");
}