#include <stdio.h>

int main()
{
    int sum = 0, i, N;

    printf ("Enter N: ");
    scanf("%d", &N);

    for(i = 1; i <= N; i++)
    {
        sum = sum + i;
    }

    printf("Sum of first N = %d natural numbers is: %d\n", N, sum);
}