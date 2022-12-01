#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    double B[n][n], temp, C[n], S[n], A;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &B[j][i]);
        }
    }
    for (int j = 0; j < n; j++)
    {
        scanf("%lf", &C[j]);
        S[j] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            temp = B[k][i] / B[i][i];
            for (int j = 0; j < n; j++)
            {
                B[k][j] = B[k][j] - (temp * B[i][j]);
            }
            C[k] = C[k] - (temp * (C[i]));
        }
    }
    S[n - 1] = C[n - 1] / B[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        A = 0;
        for (int j = 0; j < n; j++)
        {
            A = A + S[j] * B[i][j];
        }
        S[i] = (C[i] - A) / B[i][i];
    }
    for (int j = 0; j < n; j++)
    {
        printf("%lf\n", S[j]);
    }
    return 0;
}
