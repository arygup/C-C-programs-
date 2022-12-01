#include <stdio.h>

int main ()
{
    int N, is_prime = 1; 
    scanf("%d", &N);

    if(N == 1)
    {
        printf("1 is neither prime nor composite");
        return 0;  // or exit(0); ==> but this needs #include <stdlib.h> in the start
    }

    for (int i = 2; i < N; i++)
    {
        if (N%i == 0)
        {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) // or if(is_prime == 1)
    {
        printf("%d is prime\n", N);
    }
    else 
    {
        printf("%d is not prime\n", N);
    }
}