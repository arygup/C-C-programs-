#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int B[2] = {0},A[1000000], n = 1000000, C[2] = {0}, d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        y = rand();
        if(i<128)
        {
            A[i] = y%2;
        }
        if(i>=128)
        {
            B[y%2]++;
            d1++;
        }
    }
    printf("for rand() modulo 2 the probability and frequency are:\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%d => %d therefore probability is %lf\n", i, B[i], (double)B[i]/(double)d1);
    }
    printf("for XOR Generator the probability and frequency are:\n");
    for (int i = 128; i < n; i++)
    {
        A[i] = A[i-1]^A[i-127];
    }
    for (int i = 128; i < n; i++)
    {
        C[A[i]]++;
        d2++;
    }
    for (int i = 0; i < 2; i++)
    {
        printf("%d => %d therefore probability is %lf\n", i, C[i], (double)C[i]/(double)d2);
    }
}
