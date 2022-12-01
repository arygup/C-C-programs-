#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
ll cmp(const void *a, const void *b)
{
    return (*(ll *)a - *(ll *)b);
}
int main()
{
    ll n, q, l, r;
    scanf("%lld %lld", &n, &q);
    ll A[n], B[n];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }
    qsort(A, n, 8, cmp);
    B[0] = A[0];
    for (ll i = 1; i < n; i++)
    {
        B[i] = B[i - 1] + A[i];
    }
    ll i, j = 0;
    for (ll o = 0; o < q; o++)
    {
        scanf("%lld %lld", &l, &r);
        ll lef = 0, rig = n;
        while (1)
        {
            ll x = 0;
            if (lef > rig) break;
            ll mid = (lef + rig) / 2;
            if (A[mid] > l)
            {
                rig = mid - 1;
                continue;
            }
            if (A[mid] == l)
            {
                for (ll k = mid; k >= 0; k--)
                {
                    if (A[k] != l)
                    {
                        i = k + 1;
                        x = 1;
                        break;
                    }
                    i = k;
                }
                x = 1;
            }
            if(x > 0) break;
            else
            {
                i = mid;
                lef = mid + 1;
            }
        }
        lef = 0;
        rig = n;
        printf("%lld %lld", j, i);
    }
    return 0;
}
// 1 1 /2 3 3. 4 /5. 5