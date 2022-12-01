#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define m 1000000007
ll n, check1 = 0, check2 = 0;
ll mod(ll A)
{
    ll mod;
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
int main()
{
    scanf("%lld",&n);
    ll r[n][n], im[n][n];
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)scanf("%lld %lld", &r[i][j], &im[i][j]);
    ll rp[n][n], impt[n][n];
    for (ll i=0;i<n;i++)for(ll j=0;j<n;j++) rp[j][i] = r[i][j];
    for (ll i=0;i<n;i++)for(ll j=0;j<n;j++) impt[j][i] = im[i][j];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(rp[i][j] == r[i][j])
            {
                check1=1;
            }
            else
            {
                check1=0;
                printf("NO");
                return 0;
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(impt[i][j] == -1*im[i][j])
            {
                check2=1;
            }
            else
            {
                check2=0;
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}