#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ll long long
#define mo 1000000007
ll n, m, check1 = 0, check2 = 0, check3 = 0, check4 = 0;
ll max(ll a, ll b)
{
    if (b > a)
        a = b;
    return a;
}
ll min(ll a, ll b)
{
    if (b < a)
        a = b;
    return a;
}
int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    scanf("%lld %lld", &n, &m);
    ll r[n][m], im[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            scanf("%lld %lld", &r[i][j], &im[i][j]);
    }
    ll rp[n][n], impt[n][n];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            rp[j][i] = r[i][j];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            impt[j][i] = im[i][j];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (rp[i][j] == r[i][j])
            {
                check1 = 1;
            }
            else
            {
                check1 = 0;
                break;
            }
        }
        if (check1 == 0)
            break;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (impt[i][j] == -1 * im[i][j])
            {
                check2 = 1;
            }
            else
            {
                check2 = 0;
                break;
            }
        }
        if (check2 == 0)
            break;
    }

    ll r2[n][m], im2[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            scanf("%lld %lld", &r2[i][j], &im2[i][j]);
    }
    ll rp2[n][n], impt2[n][n];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            rp2[j][i] = r2[i][j];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            impt2[j][i] = im2[i][j];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (rp2[i][j] == r2[i][j])
            {
                check3 = 1;
            }
            else
            {
                check3 = 0;
                break;
            }
        }
        if (check3 == 0)
            break;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (impt[i][j] == -1 * im[i][j])
            {
                check4 = 1;
            }
            else
            {
                check4 = 0;
                break;
            }
        }
        if (check4 == 0)
            break;
    }
    if (check1 == 1 && check2 == 1 && check3 == 1 && check4 == 1)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                printf("%lld %lld ", r[i][j] + r2[i][j], im[i][j] + im2[i][j]);
            }
            // for (ll j = 0; j < m; j++)
            // {
            //     printf("%lld ", im[i][j] + im2[i][j]);
            // }
            printf("\n");
        }

        return 0;
    }
    if (m < n)
        n = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("1 0 ");
            }
            else
            {
                printf("0 0 ");
            }
        }
        printf("\n");
    }

    return 0;
}