#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int main()
{
    ll t, n, k;
    scanf("%lld", &t);
    for (ll o = 0; o < t; o++)
    {
        scanf("%lld %lld", &k, &n);
        if(n == 1) 
        {
            printf("1\n");
            continue;
        }
        ll y = 1, x = 0;
        while (n < k)
        {
            n = n * y;
            y++;
        }
        if (n % k != 0) x = 1;
        printf("%lld\n", n/k + x);
    }
}
