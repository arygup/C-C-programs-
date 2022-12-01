#include <stdio.h>
#include <stdlib.h>
#define ll long long
ll n, x, y, A[33][33];
char s[100];
ll rec(ll x, ll y, ll i)
{
    if(i >= n)
    {
        A[x][y] = 0;
        return 0;
    }
    if(s[i] == 'L')
    {
        rec(x-1, y, i+1);
        return 0;
    }
    if(s[i] == 'R')
    {
        rec(x+1, y, i+1);
        return 0;
    }
    if(s[i] == 'U')
    {
        rec(x, y+1, i+1);
        return 0;
    }
    if(s[i] == 'D')
    {
        rec(x, y-1, i+1);
        return 0;
    }
    rec(x-1, y, i+1);
    rec(x+1, y, i+1);
    rec(x, y+1, i+1);
    rec(x, y-1, i+1);
    return 0;
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 0; i < 33; i++)
    {
        for (ll j = 0; j < 33; j++)
        {
            A[i][j] = -1;
        }
    }
    //char t;
    //scanf("%c", &t);
    scanf("%s", s);
    rec(16, 16, 0);
    ll c = 0;
    for (ll i = 0; i < 33; i++)
    {
        for (ll j = 0; j < 33; j++)
        {
            if(A[i][j]>=0)c++;
        }
    }
    printf("%lld", c);
    return 0;
}
