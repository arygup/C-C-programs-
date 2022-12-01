#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    char A[t];
    int Array[t][2];

    for (int i = 0; i < t; i++)
    {
        scanf("%c", &A[i]);
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("%c ", Array[i]);
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", Array[i][j]);
        }
        printf("\n");
    }
}
