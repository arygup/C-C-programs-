#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ll long long
#define m 1000000007
ll n, k, A[1000001];
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
    if (b > a)a = b;
    return a;
}
ll min(ll a, ll b)
{
    if (b < a) a = b;
    return a;
}
int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }
    scanf("%lld", &k);
    ll temp = A[k];
    ll x = 0, y = -1;
    while(temp>=1)
    {
        if(x == k) y = temp%2;
        temp = temp/2;
        x++;
    }
    printf("%lld", y);
    return 0;
}
