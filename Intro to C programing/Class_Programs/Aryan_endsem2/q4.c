#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ll long long
#define m 1000000007
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
ll min(ll a, ll b)
{
    if (b < a)
        a = b;
    return a;
}
int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    ll n, q, t, k;
    scanf("%lld", &n);
    ll A[n][n];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            scanf("%lld", &A[i][j]);
        }
    }
    scanf("%lld", &q);
    for (ll o = 0; o < q; o++)
    {
        scanf("%lld", &k);
        ll check = 0;
        ll i = max(0, o - k);
        ll j = min(o + k, n - 1);
        for (ll v = i; v <= j; v++)
        {
            if (A[o][v] != 0)
            {
                check = 1;
                break;
            }
        }
        if (check == 0)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}