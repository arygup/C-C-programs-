#include <stdio.h>

int readValue(int N)
{
    scanf("%d", &N);
}

int printValue(int N)
{
    printf("%d\n", N);
}

int main ()
{
    int N;
    readValue(N);

    printf("%d\n", N);

    printValue(N);

}