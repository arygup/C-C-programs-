#include <stdio.h>
long long mod(long long A)
{
    long long mod;
    if(A>=0)
    {
        mod = A%1000000007;
    }
    if(A<0)
    {
        mod = 1000000007 + (A%1000000007);
    }
    return mod;
}
int nd(int k,int n,int B[n][n], int C[n-1][n-1])
{
    for (int i = 1; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (j == k)
            {
                c = c + 1;
            }
            C[i-1][j] = B[i][j + c];
        }
    }
    return 0;
}
long long alp(long long n, int B[n][n])
{
    long long A = 0, s;
    int C[n-1][n-1], b;
    s =1;
    if (n == 1)
    {
        A = B[0][0];
        return A;
    }
    for (int k = 0; k < n; k++)
    {
        nd(k, n, B, C);
        A = A + s*alp(n-1, C)*B[0][k];
        s = -s;
    }
    return mod(A);
}
int main()
{
    long long n, A;
    scanf("%lld", &n);
    int B[n][n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &B[j][i]);
        }
    }
    A = alp(n, B);
    printf("%lld", A);
    return 0;
}
