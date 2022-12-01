#include <stdio.h>
#include <math.h>
int nd(int k,int n,double B[n][n], double C[n-1][n-1])
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
long long alp(long long n, double B[n][n])
{
    long long A = 0, s;
    double C[n-1][n-1], b;
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
    return A;
}
int main()
{
    int n;
    scanf("%d", &n);
    double B[n][n], temp, C[n], D[n][n], S[n];
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &B[j][i]);
            D[i][j] = 0;
        }
    }
    if (alp(n, B) == 0)
    {
        printf("No LU decomposition");
        return 0;
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
            D[k][i] = temp;
        }
    }
    for (int j = 0; j < n; j++)
    {
        D[j][j] = 1;
        for(int i = 0;i < n;i++)
        {
            if(B[i][j]==-0)
            {
                B[i][j]=0;
            }
        }
        
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf(" %lf ", D[j][i]);
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf(" %lf ", B[j][i]);
        }
        printf("\n");
    }

    return 0;
}