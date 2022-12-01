#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
ll mini(ll x, ll y, ll z)
{
    if(y<x) x=y;
    if(z<x) x=z;
    return x;
}
ll push(ll*A, ll x, ll i)
{
    A[i] = x;
    ll p = (i-1)/2;
    while (p >= 0 && i != 0)
    {
        if(A[p] > A[i])
        {
            ll t = A[p];
            A[p] = A[i];
            A[i] = t;
        }
        i = p;
        p = (i-1)/2;
    }
    return 0;
}
ll del(ll*A, ll i, ll s)    // curri, size
{
    ll l = i*2 + 1, r = i*2 + 2;
    if(l <= s && r <= s)
    {
        ll mi = mini(A[i], A[l], A[r]);
        if(A[i] == mi) return 0;
        if(A[l] == mi)
        {
            A[l] = A[i];
            A[i] = mi;
            del(A, l, s);
            return 0;
        }
        if(A[r] == mi)
        {
            A[r] = A[i];
            A[i] = mi;
            del(A, r, s);
            return 0;
        }
    }
    if(l <= s)
    {
        ll mi = mini(A[i], A[l], __LONG_LONG_MAX__);
        if(A[i] == mi) return 0;
        if(A[l] == mi)
        {
            A[l] = A[i];
            A[i] = mi;
            del(A, l, s);
            return 0;
        }
    }
    return 0;
}
int main()
{
    ll l, n, x;
    scanf("%lld %lld", &l, &n);
    ll A[n], s = n-1, c = 0, f = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        push(A, x, i);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     printf("%lld ", A[i]);
    // }
    while (s)
    {
        f = f + A[0];
        A[0] = A[s];
        s--;
        del(A, 0, s);
        f = f + A[0];
        A[0] = A[s];
        s--;
        del(A, 0, s);
        c = c + f;
        s++;
        push(A, f, s);
        f = 0;
    }
    printf("%lld", c);
}