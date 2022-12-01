#include <stdio.h>

int main()
{
    int Array[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &Array[i]);
    }

    printf("%d", Array[5]);
}