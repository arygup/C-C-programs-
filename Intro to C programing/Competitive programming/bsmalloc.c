#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int swap(int n, char *A[n], int i)
{
    char *t;
    t = A[i];
    A[i] = A[i-1];
    A[i-1] = t;
    return 0;
}
int bs(int n, char *A[n])
{
    //char *t;
    int a = 0;
    for (int i = 1; i < n; i++)
    {
        if (strcmp(A[i - 1], A[i]) > 0)
        {
            swap(n, A, i);
            // t = A[i];
            // A[i] = A[i-1];
            // A[i-1] = t;
            a++;
        }
    }
    if (a != 0)
        bs(n - 1, A);
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    char temp[20], *A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        A[i] = malloc(strlen(temp) + 1);
        strcpy(A[i], temp);
    }
    bs(n, A);
    for (int i = 0; i < n; i++)
        printf("%s \n", A[i]);
}