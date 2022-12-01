#include <stdio.h>

int readArray(int B[], int size)
{
    for (int i = 0; i < size; i++)
    {
        B[i] = i*i;
    }
}

int computeSum(int A[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + A[i];
    }
    return sum;
}

int main ()
{
    int A[10], sum;

    readArray(A, 10);
    sum = computeSum(A, 10);

    printf("sum = %d\n", sum);

}