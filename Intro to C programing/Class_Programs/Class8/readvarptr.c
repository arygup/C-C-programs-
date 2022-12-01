#include <stdio.h>

int readValue(int* ptrN)
{
    int temp;

    scanf("%d", &temp);

    *ptrN = temp;
    *ptrN = *ptrN + 1; //whatever ptrN is pointing towards, go to that loc and update it by one.
}

int printValue(int N)
{
    printf("%d\n", N);
}

int main ()
{
    int N;
    readValue(&N);

    printValue(N);

}