#include <stdio.h>

#define N 3

int main ()
{
    int A[N][N];

    // reading a matrix

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // printing a matrix

    for (int i = 0; i < N; i ++)
    {
        printf("floor = %d\n", i);

        for (int j = 0; j < N; j++)
        {
            printf ("%3d ", A[i][j]);
        }

        printf ("\n");
    }
}