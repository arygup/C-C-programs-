#include <stdio.h>
#include <stdlib.h>
#define ll long long
int main()
{
    ll n, k, s = 0;
    double x = 2;
    scanf("%lld %lld", &n, &k);
    ll A[n];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }
    if ((double)n / (double)k == x)
    {
        ll max = A[n - 1] + A[0];
        for (ll i = 0; i < n - k; i++)
        {
            if (A[i] + A[n - 1 - i] > max) max = A[i] + A[n - 1 - i];
        }
        printf("%lld", max);
        return 0;
    }
    ll max = A[n - 1];
    for (ll i = 0; i < n - k; i++)
    {
        if (A[i] + A[n - k - i] > max) max = A[i] + A[n - k - i];
    }
    printf("%lld", max);
}
