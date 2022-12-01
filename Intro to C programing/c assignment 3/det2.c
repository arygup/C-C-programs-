#include <stdio.h>
long long base(long long A, long long b)
{
    long long x = 0, temp;
    temp = A;
    while (temp >= 1)
    {
        x++;
        temp = temp / b;
    }
    int S[x];
    char F[x];
    for (int i = x - 1; i > -1; i--)
    {
        S[i] = A % b;
        A = A / b;
    }
    for (int i = 0; i < x; i++)
    {
        if(S[i]>=10)
        {
            F[i] = (S[i]-10) + 'a';
        }
        if(S[i]<10)
        {
            F[i] = S[i] + '0';
        }
    }
    for (int i = 0; i < x; i++)
    {
        printf("%c", F[i]);
    }
    return 0;
}
long long mod(long long A)
{
    long long mod;
    if (A >= 0)
    {
        mod = A % 1000000007;
    }
    if (A < 0)
    {
        mod = 1000000007 + (A % 1000000007);
    }
    return mod;
}
int nd(int k, int n, int B[n][n], int C[n - 1][n - 1])
{
    for (int i = 1; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (j == k)
            {
                c = c + 1;
            }
            C[i - 1][j] = B[i][j + c];
        }
    }
    return 0;
}
long long alp(long long n, int B[n][n])
{
    long long A = 0;
    int C[n - 1][n - 1], b;
    if (n == 1)
    {
        A = B[0][0];
        return A;
    }
    for (int k = 0; k < n; k++)
    {
        nd(k, n, B, C);
        A = A + alp(n - 1, C) * B[0][k];
    }
    return mod(A);
}
int main()
{
    long long n, A, q, b;
    scanf("%lld %lld", &q, &n);
    if (q == 1)
    {
        scanf("%lld", &b);
    }
    int B[n][n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &B[j][i]);
        }
    }
    A = alp(n, B);
    if (q == 0)
    {
        printf("%lld", A);
    }
    else if (q > 0)
    {
        A = base(A, b);
    }
    return 0;
}
