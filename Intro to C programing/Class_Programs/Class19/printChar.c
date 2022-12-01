#include <stdio.h>

int main()
{
    char ch;
    ch = 'a';

    printf("%c %d 0x%x\n", ch, ch, ch);

    for (char ch = 'a', bigch = 'A'; ch <= 'z'; ch++, bigch++)
    {
        printf("%c %d %c %d\n", ch, ch, bigch, bigch);
    }
}