#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long int
ll twopow(ll n)
{
    ll t = 1LL;
    for (ll i = 0; i < n; i++)
    {
        t = t * 2LL;
    }
    return t;
}
ll twopow2(ll n)
{
    ll x = 1, a = 2;
    while(n>0)
    {
        if(n & 1LL) x = x*a;
        a = a*a;
        n >>= 1LL;
    }
    return x;
}
int main()
{
    ll n, temp, p = 0, t, node, d, two = 2;
    char s[100010];
    scanf("%lld %lld", &n, &t);
    ll out[t];
    n++;
    temp = n;
    while (temp > 1)
    {
        temp = temp / two;
        p++;
    }
    for (ll k = 0; k < t; k++)
    {
        scanf("%lld %s", &node, s);
        if(n == two)
        {
            out[k] = 1;
            continue;
        }
        if ((ll)(node % two) == 1) d = 0;
        if (node == n / two) d = p - 1;
        else
        {
            ll jk = two, rec = 4;
            for (ll i = 1; i < 63; i++)
            {
                if ((ll)(node - jk) % rec == 0)
                {
                    d = i;
                    break;
                }
                jk = jk * two;
                rec = rec * two;
            }
        }
        ll len = (ll)strlen(s);
        for (ll i = 0; i < len; i++)
        {
            if ((ll)(node % two) == 1)
            {
                if ((ll)s[i] == 'U' && node != n)
                {
                    if (((ll)((node - 1) / two) % two) == 0) node = node + 1; 
                    else node = node - 1;
                    d++;
                }
            }
            else if (node == (ll)(n / two))
            {
                if ((ll)s[i] == 'L')
                {
                    node = node / two;
                    d--;
                }
                if ((ll)s[i] == 'R')
                {
                    node = (ll)((ll)(3 * node) / two);
                    d--;
                }
            }
            else
            {
                ll fac = twopow(d), j = (node - fac) / (two * fac);
                if ((ll)s[i] == 'U')
                {
                    if ((ll)(j % two) == 0) node = node + fac;
                    else node = node - fac;
                    d++;
                }
                else
                {
                    if ((ll)s[i] == 'R') node = node + fac / two;
                    else if ((ll)s[i] == 'L') node = node - fac / two;
                    d--;
                }
            }
        }
        out[k] = node;
    }
    for (ll i = 0; i < t; i++)
    {
        printf("%lld \n", out[i]);
    }
}