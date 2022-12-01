#include <stdio.h>

int square(int a)
{
    int squared_value;

    squared_value = a * a;
    return squared_value;
}

int main()
{
    int N, sum = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        sum = sum + square(i);
    }

    printf("%d", sum);
}