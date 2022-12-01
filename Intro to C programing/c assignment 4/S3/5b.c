#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int B[2] = {0}, F[2] = {0}, E[1000000], A[1000000], n = 1000000, C[2] = {0}, D[2] = {0};
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        y = rand();
        E[i] = y % 2;
        if (i < 128)
        {
            A[i] = y % 2;
        }
        if (i > 127)
        {
            if (E[i - 1] == 0)
            {
                B[E[i]]++;
                a++;
            }
            if (E[i - 1] == 1)
            {
                F[E[i]]++;
                b++;
            }
        }
    }
    for (int i = 128; i < n; i++)
    {
        A[i] = A[i - 1] ^ A[i - 127];
        if (A[i - 1] == 0)
        {
            C[A[i]]++;
            c++;
        }
        if (A[i - 1] == 1)
        {
            D[A[i]]++;
            d++;
        }
    }
    printf("For rand() modulo 2 the probability\n");
    printf("P(Xi = 0/Xi-1 = 0) = %lf\n", (double)B[0] / (double)a);
    printf("P(Xi = 0/Xi-1 = 1) = %lf\n", (double)F[0] / (double)b);
    printf("For XOR Generator the probability\n");
    printf("P(Xi = 0/Xi-1 = 0) = %lf\n", (double)C[0] / (double)c);
    printf("P(Xi = 0/Xi-1 = 1) = %lf\n", (double)D[0] / (double)d);
}