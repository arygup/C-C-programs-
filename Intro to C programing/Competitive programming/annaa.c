#include <stdio.h>
#include <stdlib.h>
#define ll long long
int main()
{
    ll n, k, g, s, min = 0, max = 10000000000;
    scanf("%lld %lld", &n, &k);
    while (1)
    {
        g = (min + max) / 2;
        ll temp = g;
        s = 0;
        while (temp != 0)
        {
            s = s + temp;
            temp = temp / k;
            if (s > n)
            {
                max = g;
                break;
            }
        }
        if (s < n)
        {
            min = g;
        }
        if (max - min == 1)
            break;
        if (s == n)
            break;
    }
    printf("%lld", g);
}


/*
#include <stdio.h>
#define T long long

T solve(T n , T k, T min, T max)
{
    if(max - min == 1) return max;
    T current = (min + max) / 2;
    T temp = current;
    T divider = 1;
    while(temp/(divider*k))
    {   divider *= k;
        temp += current/divider;
        if (temp >= n){
            return solve(n , k , min, current);
        }
    }

    return solve(n , k , current, max);


}

int main()
{
    T min = 0;
    T max = 100000000000;
    T n , k;
    scanf("%lld %lld", &n, &k);
    if(k >= n) {
        printf("%lld", n);
        return 0;
    }

    printf("%lld\n", solve(n , k, min, max));
    return 0;
}
*/