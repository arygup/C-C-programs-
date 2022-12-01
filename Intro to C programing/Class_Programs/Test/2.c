#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *N;
    N = malloc(3232);
    *N = 32;
    printf("%d", *N);

}