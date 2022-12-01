#include <stdio.h>

int setVar(int *ptr)
{
    *ptr = 1; 
}

int main ()
{
    int a;
    int* ptra;

    a = 2;
    ptra = &a;

    setVar(ptra);

    printf("%d", a);
}