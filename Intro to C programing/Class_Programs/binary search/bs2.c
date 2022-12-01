#include<stdio.h>
#include<stdlib.h>
#define ll long long
ll a = 0, n = -1 , A[10], min = 10, max = 0, mid, m;
ll mi(ll a, ll b)
{
    if(a<b)b = a;
    return b;
}
ll ma(ll a, ll b)
{
    if(a>b)b = a;
    return b;
}
ll rec(ll g)
{
    ll sum = 0, x = 1;
    for (ll i = 0; i < 5; i++)
    {
        if(A[i] > g) return 0;
        if(sum + A[i] <= g)
        {
            sum += A[i];
        }
        else
        {
            sum = A[i];
            x++;
        }
    }
    return x <= m;
}
int main()
{
    for (ll i = 0; i < 5; i++)
    {
        scanf("%lld", &A[i]);
        max = max + A[i];
        min = ma(min, A[i]);
    }
    scanf("%lld", &m);
    while(1)
    {
        if(max - min <= 1) break;
        ll g = (min + max)/2;
        if(rec(g))
        {
            a = g;
            max = g;
        }
        else
        {
            min = g;
        }
    }
    printf("%lld", a);
}