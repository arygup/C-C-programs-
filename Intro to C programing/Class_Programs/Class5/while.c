#include <stdio.h>

int main()
{
    int N, i;

    printf("Enter N:");
    scanf("%d", &N);

    printf("====\n");
    i = 1;
    while (i<=N)
    {
        printf("%d\n", i);
        i++;
    }
    printf("===\n");
}