#include <stdio.h>
#include <math.h>

int main()
{
    float N, sqrtN;

    printf ("Enter N: ");
    scanf ("%f", &N);

    sqrtN = sqrt(N);

    printf("Square Root of %f = %f", N, sqrtN);

}