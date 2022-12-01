#include <stdio.h>
#include <stdlib.h>
#define ll long long
ll max(ll a, ll b)
{
    if (b > a)
        a = b;
    return a;
}
ll rec(ll n, ll A[][2], ll C[][2],ll q, ll i)
{
    if(q>=n) return 0;
    if (C[q][i] != -1) return C[q][i];
    C[q][i] = A[q][i] + max(rec(n, A, C,q+1, 1-i), rec(n, A, C,q+2, 1-i));
    return C[q][i];
}
int main()
{
    ll n, a, b, c, d, e, f;
    scanf("%lld", &n);
    if (n == 1)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld", max(a, b));
        return 0;
    }
    if(n == 2)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        printf("%lld", max(a + c, b + d));
        return 0;
    }
    if(n == 2)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
        printf("%lld", max(a + c, b + d));
        return 0;
    }
    ll A[n][2], C[n][2];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i][0]);
    }
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i][1]);
    }
    for (ll i = 0; i < n; i++)
    {
        C[i][0] = -1;
        C[i][1] = -1;
    }
    C[n - 1][0] = A[n - 1][0];
    C[n - 1][1] = A[n - 1][1];
    // C[n - 2][0] = A[n - 2][0] + C[n - 1][1];
    // C[n - 2][0] = A[n - 2][1] + C[n - 1][0];
    printf("%lld", max(rec(n, A, C, 0, 0), rec(n, A, C, 0, 1)));
}