#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ll long long
#define m 1000000007
ll n, k, ans = 0, calc;
long long mod(long long A)
{
    long long mod;
    if (A >= 0)
    {
        mod = A % m;
    }
    if (A < 0)
    {
        mod = m + (A % m);
    }
    return mod;
}
ll max(ll a, ll b)
{
    if (b > a)
        a = b;
    return a;
}
int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    scanf("%lld %lld", &n, &k);
    char A[n][k];
    for (ll i = 0; i < n; i++)
    {
        scanf("%s", A[i]);
    }
    for (ll i = 0; i < n-1; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            ll calc = 0;
            for (ll v = 0; v < k; v++)
            {
                if (A[i][v] != A[j][v])
                    calc++;
            }
            if (calc > ans)
                ans = calc;
            calc = 0;
        }
    }
    printf("%lld", ans);
    return 0;
}