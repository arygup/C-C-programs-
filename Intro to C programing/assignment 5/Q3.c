#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
int main()
{
    ll n, k, t, lines = 0, x = 0;
    scanf("%lld %lld", &n, &k);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &t);
        t = t + x;
        if (t >= 8)
        {
            lines = lines + 8;
            x = t - 8;
        }    
        else
        {
            lines = lines + t;   
            x = 0;
        } 
        if (lines >= k)
        {
            printf("%lld", i + 1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}