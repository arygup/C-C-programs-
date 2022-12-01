 #include <stdio.h>
#define mod 1000000007
#define ll long long
ll grtstFact, x, y, z;
ll mo(ll x)
{
    if (x >= 0)
    {
        return (x % (mod));
    }
    else
    {
        return (x + mod) % mod;
    }
}
void ee(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = x - 1;
        grtstFact = a;
    }
    if(b != 0)
    {
        ee(b, a % b);
        z = x;
        x = y;
        y = z - (a / b) * y; 
    }
}
ll mi(ll a, ll Modu)
{
    ee(a, Modu);    
    return mo(x);  //returns mmi
}
int main()
{
    ll q, m, n, x1, x2, y1, y2, temp, pr = 1;
    scanf("%lld %lld", &n, &m);
    ll A[n][m], B[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            scanf("%lld", &A[i][j]);
            if (i == 0 && j != 0)
            {
                B[i][j] = mo(mo(B[i][j - 1]) * mo(A[i][j]));
            }
            if (i == 0 && j == 0)
            {
                B[0][0] = A[0][0];
            }
        }
        if (i != 0)
        {
            B[i][0] = mo(mo(B[i - 1][0]) * mo(A[i][0]));
        }
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j < m; j++)
        {
            B[i][j] = mo(mo(B[i][j - 1]) * mo(B[i - 1][j]));
            B[i][j] = mo((mo(B[i][j])) * mo(A[i][j]));
            temp = mi(B[i - 1][j - 1], mod);
            B[i][j] = mo(mo(B[i][j]) * temp); 
        }
    }
    scanf("%lld", &q);
    for (ll z = 0; z < q; z++)
    {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if (x1 > x2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
        }
        if (y1 > y2)
        {
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        if(x1 != 0 && y1 != 0)
        {
            pr = mo(mo(B[x2][y2]) * mo(B[x1 - 1][y1 - 1]));
            temp = mi(B[x1 - 1][y2], mod);
            pr = mo(mo(pr) * mo(temp));
            temp = mi(B[x2][y1 - 1], mod);
            pr = mo(mo(pr) * mo(temp));
        }
        if (x1 != 0 && y1 ==  0)
        {
            pr = mo(mo(B[x2][y2]));
            temp = mi(B[x1 - 1][y2], mod);
            pr = mo(mo(pr) * mo(temp));
        }
        if (y1 != 0 && x1 == 0)
        {
            pr = mo(mo(B[x2][y2]));
            temp = mi(B[x2][y1 - 1], mod);
            pr = mo(mo(pr) * mo(temp));
        }
        if(y1 == 0 && x1 == 0)
        {
            pr = B[x2][y2];
        }
        printf("%lld\n", pr);
    }
    return 0;
}
/*
ll pr = 1;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        if (x1 > x2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
        }
        if (y1 > y2)
        {
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        for (ll i = x1; i <= x2; i++)
        {
            for (ll j = y1; j <= y2; j++)
            {
                pr = ((pr%mod)*(A[i][j]%mod))%mod;
            }
        }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            B[i][j] = (((A[i][j] % mod) * (B[i][j - 1] % mod)) % mod + (B[i - 1][j] % mod)) % mod;
            B[i][j] = ((B[i][j] % mod) / (B[i - 1][j - 1] % mod)) % mod; // change ig
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lld ", B[i][j]);
        }
        printf("\n");
    }
    return 0;
 */